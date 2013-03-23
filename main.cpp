// Copyright (c) 2011  Stefan A. van der Meer
// See "LICENSE" file included with source code for terms and conditions.

#include <cstdio>

#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QHash>
#include <QHashIterator>

#include "chumbybuttonhandler.h"
#include "chumbyknobhandler.h"
#include "chumbycmdhandler.h"
#include "chumbypage.h"

int main(int argc, char *argv[])
{
    // Create app as server, equivalent to starting with -qws
    QApplication app(argc, argv, QApplication::GuiServer);

    // Page responsible for all special chumby-related browsing behaviour.
    // If no --command-path was given, don't create a command handler.
    ChumbyPage *vpage = new ChumbyPage(new SimpleCommandHandler("/mnt/usb/userapp/bin"));

    // The button handler reads Chumby's button sockets and converts their
    // events into keypress events, which are sent to its parent. We want to
    // use the key events in Javascript, so we parent it to the page, which
    // will handle them like any other keypress (sending them to the DOM etc).
    ChumbyKnobHandler *ckh = new ChumbyKnobHandler(vpage);

    // The MainWindow will tell its QWebView component to use the page class we
    // inject, and load the given URL.
    MainWindow *v = new MainWindow(QUrl( "http://localhost/" ), vpage);
    v->show();

    ChumbyPage *cpage = new ChumbyPage(new SimpleCommandHandler("/mnt/usb/userapp/bin"), 0, v);
    MainWindow *c = new MainWindow(QUrl( "http://localhost/cp" ), cpage);
    c->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    ChumbyButtonHandler *cbh = new ChumbyButtonHandler(c);
    c->show();


    return app.exec();
}
