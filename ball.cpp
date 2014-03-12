#include "ball.h"
#include <iostream>

Ball::Ball(Coordinate coordinate): m_coordinate(coordinate){}

Ball::Ball(Coordinate coordinate,
    unsigned int radius):
    m_coordinate(coordinate),
    m_radius(radius)
{}

Ball::Ball(Coordinate coordinate,
    unsigned int radius,
    double gravity,
    double xVelocity,
    double yVelocity):
    m_coordinate(coordinate),
    m_radius(radius),
    m_gravity(gravity),
    m_xVelocity(xVelocity),
    m_yVelocity(yVelocity)
{}

void Ball::render(QPainter &painter, unsigned int time)
{
//    std::cout << "x: " << m_coordinate.getQtRenderingXCoordinate() << " y: " << m_coordinate.getQtRenderingYCoordinate() << std::endl;
//    std::cout << "coll: " << isCollision() << std::endl;
    if (isCollision() == 0) {
        m_coordinate.setXCoordinateToZero(this->getRadius());
        m_xVelocity *= -1;
    } else
    if (isCollision() == 1) {
        m_coordinate.setXCoordinateToMax(this->getRadius());
        m_xVelocity *= -1;
    } else
    if (isCollision() == 2) {
        m_coordinate.setYCoordinateToMax(this->getRadius());
        m_yVelocity *= -1;
    } else
    if (isCollision() == 3) {
        m_coordinate.setYCoordinateToZero(this->getRadius());
        m_yVelocity *= -1;
    }

    painter.setPen ( Qt::black );
    painter.setBrush( QBrush( Qt::yellow ) );
    painter.drawEllipse(m_coordinate.getQtRenderingXCoordinate() - (int) m_radius,
        m_coordinate.getQtRenderingYCoordinate() -(int) m_radius,
        m_radius * 2,
        m_radius * 2);
    m_yVelocity += m_gravity / 32.0;
    m_coordinate.changeInXCoordinate(m_xVelocity);
    m_coordinate.changeInYCoordinate(m_yVelocity);
}


int Ball::isCollision()
{
    int bottom = (signed int) (m_coordinate.getFrameHeight() - (signed int) m_radius);
    int top = (signed int) (0 + (signed int) m_radius);
    int left = (signed int) (0 + (signed int) m_radius);
    int right = (signed int) (m_coordinate.getFrameWidth() - (signed int) m_radius);
    if (m_coordinate.getQtRenderingXCoordinate() < left) return 0;
    if (m_coordinate.getQtRenderingXCoordinate() > right) return 1;
    if (m_coordinate.getQtRenderingYCoordinate() < top) return 2;
    if (m_coordinate.getQtRenderingYCoordinate() > bottom) return 3;
    return -1;

}

unsigned int Ball::getRadius(){
    return m_radius;
}
