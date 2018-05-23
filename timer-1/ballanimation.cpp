#include "ballanimation.h"
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
BallAnimation::BallAnimation(QWidget *parent) : QWidget(parent),
    m_origin(QPoint(50,50))
{
    setFixedSize(100,100);
    // setGeometry(0,0,100,100);
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

bool BallAnimation::touchingBorderx()
{
   if (m_origin.x() + 10 >= width())
   {
       return true;
   }
   else if (m_origin.x() - 10 <= 0)
   {
       return true;
   }
   else
   {
       return false;
   }
}

bool BallAnimation::touchingBordery()
{
   if (m_origin.y() + 10 >= height())
   {
       return true;
   }
   else if (m_origin.y() - 10 <= 0)
   {
       return true;
   }
   else
   {
       return false;
   }

}

void BallAnimation::paintEvent(QPaintEvent *event)
{
    qDebug() << "Painting";
    QPainter painter(this);
    painter.drawRect(QRect(0,0,width(),height()));
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::red);
    painter.drawEllipse(m_origin,10,10);
    //painter.drawRect(QRect(0,0,width()-1,height()-1));
    //painter.drawLine(QPoint(0,0),QPoint(50,50));


}
