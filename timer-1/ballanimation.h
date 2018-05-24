#ifndef BALLANIMATION_H
#define BALLANIMATION_H

#include <QWidget>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    //Constructor:
    explicit BallAnimation(QWidget *parent = nullptr);
    //Mutators:
    void setOrigin(const QPoint& origin);
    void addToOrigin(const QPoint& point);
    void setDirectionX(int x);
    void setDirectionY(int y);
    //Assessors:
    bool touchingBorderX();
    bool touchingBorderY();
    int getDirectionX();
    int getDirectionY();
    QPoint getOrigin();


signals:

public slots:
    void paintEvent(QPaintEvent *event);
private:
    QPoint m_origin;
    int m_size_x;
    int m_size_y;
    int directionx;
    int directiony;
};

#endif // BALLANIMATION_H
