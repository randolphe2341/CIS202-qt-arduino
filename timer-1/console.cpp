/**************************************************************************

  Name: console.cpp
  Description: This is the implementation of the Console class.
  Author: Ethan Randolph
  Email: randolphe@student.vvc.edu
  Created: May 29, 2018

**************************************************************************/
#include "console.h"
#include <QKeyEvent>
#include <QScrollBar>

Console::Console(QWidget *parent) :
    QTextBrowser(parent)
{
    document()->setMaximumBlockCount(100);
    setFixedSize(640,20);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    setPalette(p);
}

void Console::putData(const QString &data)
{
    insertPlainText(data);
    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void Console::setLocalEchoEnabled(bool set)
{
    m_localEchoEnabled = set;
}

void Console::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Backspace:
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
        break;
    default:
        if (m_localEchoEnabled)
            QTextBrowser::keyPressEvent(e);
        emit getData(e->text().toLocal8Bit());
    }
}

void Console::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
    setFocus();
}

void Console::mouseDoubleClickEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
}

void Console::contextMenuEvent(QContextMenuEvent *e)
{
    Q_UNUSED(e)
}
