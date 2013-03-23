// Copyright (c) 2011  Stefan A. van der Meer
// See "LICENSE" file included with source code for terms and conditions.

#ifndef CHUMBYKNOBHANDLER_H
#define CHUMBYKNOBHANDLER_H

#include <QObject>

// Reads events from sockets specific to the Chumby, in order to send keypress
// events to its parent object.
//
// The QKeyEvents are:
//   Qt::Key_Home  for the top button on the device;
//   Qt::Key_Up    when rotating the wheel button upwards;
//   Qt::Key_Down  when rotating the wheel button downwards.
class ChumbyKnobHandler : public QObject
{
    Q_OBJECT

public:
    ChumbyKnobHandler(QObject *parent=0);
    ~ChumbyKnobHandler();

private slots:
    // Read from wheel button socket
    void readWheel();

private:
    // Generate key event for wheel rotation and send to parent.
    void handleWheelEvent(int rotation);

    // Socket identifiers
    static int fdevice_wheel;
};

#endif // CHUMBYKNOBHANDLER_H
