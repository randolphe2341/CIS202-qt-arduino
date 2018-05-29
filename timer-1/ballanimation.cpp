/**************************************************************************

  Name: ballanimation.cpp
  Description: This is the implementation of the BallAnimation class.
  Author: Ethan Randolph
  Email: randolphe@student.vvc.edu
  Created: May 29, 2018

**************************************************************************/
#include "ballanimation.h"
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <cmath>
#include <ctime>

//All function descriptions are in the header file.
BallAnimation::BallAnimation(QWidget *parent) : QWidget(parent),
    m_origin(QPoint(50,50))
{
    setFixedSize(100,100);
    m_size_x = 10;
    m_size_y = 10;
    srand(time(NULL));
    do
    {
        m_directionx = (rand() % 3);
        m_directiony = (rand() % 3);
    } while (m_directionx == 0 && m_directiony == 0);
}

void BallAnimation::setOrigin(const QPoint &origin)
{
    m_origin = origin;
}

void BallAnimation::addToOrigin(const QPoint &point)
{
    m_origin += point;
}

QPoint BallAnimation::getOrigin()
{
    return m_origin;
}

bool BallAnimation::touchingBorderX()
{
   if (m_origin.x() + m_size_x >= width())
   {
       return true;
   }
   else if (m_origin.x() - m_size_x <= 0)
   {
       return true;
   }
   else
   {
       return false;
   }
}

bool BallAnimation::touchingBorderY()
{
   if (m_origin.y() + m_size_y >= height())
   {
       return true;
   }
   else if (m_origin.y() - m_size_y <= 0)
   {
       return true;
   }
   else
   {
       return false;
   }

}

void BallAnimation::setDirectionX(int x)
{
    m_directionx = x;
}

void BallAnimation::setDirectionY(int y)
{
    m_directiony = y;
}

int BallAnimation::getDirectionX()
{
    return m_directionx;
}

int BallAnimation::getDirectionY()
{
   return m_directiony;
}

void BallAnimation::paintEvent(QPaintEvent *event)
{
    qDebug() << "Painting";
    QPainter painter(this);
    painter.drawRect(QRect(0,0,width(),height()));
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::black);
    if (touchingBorderX() || touchingBorderY())
    {
        bool painted = false;
        if (touchingBorderX())
        {
            if (m_directionx < 1)
            {
                painter.drawEllipse(m_origin-QPoint(m_size_x/2,0),m_size_x/2,m_size_y+(m_size_x/2));
            }
            else
            {
                painter.drawEllipse(m_origin+QPoint(m_size_x/2,0),m_size_x/2,m_size_y+(m_size_x/2));
            }
            setDirectionX(-(m_directionx));
            painted = true;
        }
        if (touchingBorderY())
        {
            if (m_directiony < 1 && !painted)
            {
                painter.drawEllipse(m_origin-QPoint(0,m_size_y/2),m_size_x+(m_size_y/2),m_size_y/2);
            }
            else if (!painted)
            {
                painter.drawEllipse(m_origin+QPoint(0,m_size_y/2),m_size_x+(m_size_y/2),m_size_y/2);
            }
            setDirectionY(-(m_directiony));
        }
    }
    else
    {
        painter.drawEllipse(m_origin,m_size_x,m_size_y);
    }
}
