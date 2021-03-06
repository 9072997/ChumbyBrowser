// Copyright (c) 2011  Stefan A. van der Meer
// See "LICENSE" file included with source code for terms and conditions.

#ifndef CHUMBYBUTTONHANDLER_H
#define CHUMBYBUTTONHANDLER_H

#include <QObject>
#include "mainwindow.h"

// Reads events from sockets specific to the Chumby, in order to send keypress
// events to its parent object.
//
// The QKeyEvents are:
//   Qt::Key_Home  for the top button on the device;
//   Qt::Key_Up    when rotating the wheel button upwards;
//   Qt::Key_Down  when rotating the wheel button downwards.
class ChumbyButtonHandler : public QObject
{
    Q_OBJECT

public:
    ChumbyButtonHandler(MainWindow*);
    ~ChumbyButtonHandler();

private slots:
    // Read from top button socket
    void readButton();

private:
    // Generate appropriate key event for a top button press and send to parent
    void handleTopButtonPress(bool pressed);

    // Socket identifiers
    static int fdevice_top;

    MainWindow *w;
    bool buttonState;
    bool cpState;
};

#endif // CHUMBYBUTTONHANDLER_H
