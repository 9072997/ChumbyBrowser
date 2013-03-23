// Copyright (c) 2011  Stefan A. van der Meer
// See "LICENSE" file included with source code for terms and conditions.

#include "chumbypage.h"

#include <QWebFrame>

ChumbyPage::ChumbyPage(ChumbyCommandHandler *handler, QObject *parent, QObject *widgetview)
        : QWebPage(parent), command_handler(handler)
{
    command_handler->setParent(this);
    bool isCp;
    if(widgetview) {
        ChumbyPage::widgetview = widgetview;
        mainFrame()->connect(mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(addWidgetHandlerToFrame()));
        isCp = true;
    } else {
        isCp = false;
    }

    // An object exposed to JavaScript must be re-added every time the DOM
    // is cleared (page load).
    mainFrame()->connect(mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(addCommandHandlerToFrame()));

}

void ChumbyPage::addCommandHandlerToFrame()
{
    mainFrame()->addToJavaScriptWindowObject("ChumbyCommandHandler", command_handler);
}

void ChumbyPage::addWidgetHandlerToFrame()
{
    mainFrame()->addToJavaScriptWindowObject("WidgetHandler", widgetview);
}

// Show console messages and errors in debug output.
void ChumbyPage::javaScriptConsoleMessage ( const QString & message, int lineNumber, const QString & sourceID )
{
    qDebug("JS console: %s \t[%s:%d]", qPrintable(message), qPrintable(sourceID), lineNumber);
}
