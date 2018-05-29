/**************************************************************************

  Name: ballanimation.h
  Description: This is the header file of BallAnimation. BallAnimation creates a
  rectangle, and within that rectangle, it will animate a ball (with each repaint).
  Author: Ethan Randolph
  Email: randolphe@student.vvc.edu
  Created: May 29, 2018

**************************************************************************/
#ifndef BALLANIMATION_H
#define BALLANIMATION_H

#include <QWidget>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    //Constructor:
    /**
     * @brief BallAnimation Initiates the object.
     * @param parent
     */
    explicit BallAnimation(QWidget *parent = nullptr);
    //Mutators:
    /**
     * @brief setOrigin Sets m_origin to origin.
     * @param origin
     */
    void setOrigin(const QPoint& origin);
    /**
     * @brief addToOrigin adds origin to the m_origin.
     * @param point
     */
    void addToOrigin(const QPoint& point);
    /**
     * @brief setDirectionX changes m_directionx to x.
     * @param x
     */
    void setDirectionX(int x);
    /**
     * @brief setDirectionY changes m_directiony to y.
     * @param y
     */
    void setDirectionY(int y);
    //Assessors:
    /**
     * @brief touchingBorderX detects if the ball is touching one of the borders lying on the x-axis.
     * @return true if touching, false if not.
     */
    bool touchingBorderX();
    /**
     * @brief touchingBorderY detects if the ball is touching one of the borders lying on the y-axis.
     * @return true if touching, false if not.
     */
    bool touchingBorderY();
    /**
     * @brief getDirectionX
     * @return m_directionx
     */
    int getDirectionX();
    /**
     * @brief getDirectionY
     * @return m_directiony
     */
    int getDirectionY();
    /**
     * @brief getOrigin
     * @return m_origin
     */
    QPoint getOrigin();


signals:

public slots:
    void paintEvent(QPaintEvent *event);
private:
    QPoint m_origin;
    int m_size_x;
    int m_size_y;
    int m_directionx;
    int m_directiony;
};

#endif // BALLANIMATION_H
