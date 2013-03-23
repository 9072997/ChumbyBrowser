// Copyright (c) 2011  Stefan A. van der Meer
// See "LICENSE" file included with source code for terms and conditions.

#include "chumbyknobhandler.h"

#include <QApplication>
#include <QKeyEvent>

// Keyboard socket access
#include <QSocketNotifier>
#include <linux/input.h>
#include <fcntl.h>


// There should be no reason to change the sockets on Chumby One (Falconwing),
// but just in case: they can be easily modified with -D compile flags
#ifndef SOCKET_CHUMBY_WHEELBUTTON
    #define SOCKET_CHUMBY_WHEELBUTTON "/dev/input/by-id/soc-noserial-event-joystick"
#endif

int ChumbyKnobHandler::fdevice_wheel = -1;

ChumbyKnobHandler::ChumbyKnobHandler(QObject *parent)
        :QObject(parent)
{
    //
    // Button presses are detected by reading the socket in which the device
    // generates the input events. Simpler than a keyboard driver.
    //

    // Hook up key handler for volume wheel events.
    fdevice_wheel = ::open(SOCKET_CHUMBY_WHEELBUTTON, O_RDONLY|O_NDELAY, 0);

    if (fdevice_wheel >= 0) {
        QSocketNotifier *notifier_wheel = new QSocketNotifier(fdevice_wheel, QSocketNotifier::Read, this);
        connect(notifier_wheel, SIGNAL(activated(int)), this, SLOT(readWheel()));

        qDebug("Connected fdevice_wheel slot");
    } else {
        qWarning("Failed to connect to top button socket at %s", SOCKET_CHUMBY_WHEELBUTTON);
    }
}

ChumbyKnobHandler::~ChumbyKnobHandler()
{
    if (fdevice_wheel >= 0) {
        ::close(fdevice_wheel);
        fdevice_wheel = -1;
    }
}

// Process a wheel rotation. The rotation parameter is positive for up, negative
// for down. Normal rotation gives a magnitude of 1, while very fast rotation
// gives magnitudes between 2-4.
//
// Currently this handler simply generates a keypress event in the webview of
// the arrow key that matches the rotation direction (up/down). This keypress
// can be detected as a DOM event in javascript loaded in the webview.
void ChumbyKnobHandler::handleWheelEvent(int rotation) {
    QKeyEvent *ev = new QKeyEvent(QEvent::KeyPress,
                                  rotation > 0 ? Qt::Key_Up : Qt::Key_Down,
                                  0);

    qApp->postEvent(parent(), ev);
}

// Read all events from the wheel button socket. For every rotation event
// call handleWheelEvent.
//
// The event value varies with the rotation direction and
// speed.
void ChumbyKnobHandler::readWheel()
{
    struct input_event event;
    const int event_size = sizeof(struct input_event);

    int rb = 0;

    while (true) {
        rb = ::read(fdevice_wheel, &event, event_size);

        if (rb != event_size) break;
        if (event.type != EV_REL) continue;

        if (event.code == REL_WHEEL) {
            handleWheelEvent(event.value);
        }
    }
}


