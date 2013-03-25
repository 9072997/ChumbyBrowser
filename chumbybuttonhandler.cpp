// Copyright (c) 2011  Stefan A. van der Meer
// See "LICENSE" file included with source code for terms and conditions.

#include "chumbybuttonhandler.h"

#include <QApplication>
#include <QKeyEvent>

// Keyboard socket access
#include <QSocketNotifier>
#include <linux/input.h>
#include <fcntl.h>


// There should be no reason to change the sockets on Chumby One (Falconwing),
// but just in case: they can be easily modified with -D compile flags
#ifndef SOCKET_CHUMBY_TOPBUTTON
    #define SOCKET_CHUMBY_TOPBUTTON   "/dev/input/by-id/soc-noserial-event-kbd"
#endif

int ChumbyButtonHandler::fdevice_top   = -1;

ChumbyButtonHandler::ChumbyButtonHandler(MainWindow *w)
        :QObject()
{
    //
    // Button presses are detected by reading the socket in which the device
    // generates the input events. Simpler than a keyboard driver.
    //
    this->w = w;
    buttonState = false;
    cpState = false;
    // Hook up key handler for top button events.
    fdevice_top = ::open(SOCKET_CHUMBY_TOPBUTTON, O_RDONLY|O_NDELAY, 0);

    if (fdevice_top >= 0) {
        QSocketNotifier *notifier_top = new QSocketNotifier(fdevice_top, QSocketNotifier::Read, this);
        connect(notifier_top, SIGNAL(activated(int)), this, SLOT(readButton()));

        qDebug("Connected fdevice_top slot.");
    } else {
        qWarning("Failed to connect to top button socket at %s", SOCKET_CHUMBY_TOPBUTTON);
    }
}

ChumbyButtonHandler::~ChumbyButtonHandler()
{
    if (fdevice_top >= 0) {
        ::close(fdevice_top);
        fdevice_top = -1;
    }
}

//
// Input handling
//
// Because Qt's keyboard driver infrastructure was a hassle, we manually read
// keypresses and generate events that we post to the browser widget. Ugly!
//

void ChumbyButtonHandler::handleTopButtonPress(bool show) {
    if(show) {
        w->show();
        qDebug("Showing CP");
    } else {
        w->hide();
        qDebug("Hideing CP");
	w->goTo("http://localhost/cp");
    }
}

// Read all events from the top button socket. For every button press or release,
// call handleTopButtonPress (there is usually only one event).
void ChumbyButtonHandler::readButton()
{
    struct input_event event;
    const int event_size = sizeof(struct input_event);

    int rb = 0;
    while (true) {
        rb = ::read(fdevice_top, &event, event_size);

        if (rb != event_size) break;
        if (event.type != EV_KEY) continue;
        buttonState = !buttonState;
    }
    // This magic number is the key code the Chumby top button generates.
    if(buttonState == false) {
        cpState = !cpState;
    } else {
        if (event.code == 28) {
            handleTopButtonPress(cpState);
        }
    }
}


