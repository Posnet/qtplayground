#include "coordinates.h"

Coordinate::Coordinate(unsigned
    int xCoordinate,
    unsigned int yCoordinate,
    unsigned int frameHeight,
    unsigned int frameWidth):
    m_xCoordinate(xCoordinate),
    m_yCoordinate(yCoordinate),
    m_frameHeight(frameHeight),
    m_frameWidth(frameWidth)
{}

int Coordinate::getQtRenderingYCoordinate()
{
    return m_frameHeight - m_yCoordinate;
}

int Coordinate::getQtRenderingXCoordinate(){
    return m_xCoordinate;
}

void Coordinate::changeInXCoordinate(int change){
    m_xCoordinate += change;
}

void Coordinate::changeInYCoordinate(int change){
    m_yCoordinate += change;
}

void Coordinate::setYCoordinateToZero(int offset){
    m_yCoordinate = 0 + offset;
}

void Coordinate::setXCoordinateToZero(int offset){
    m_xCoordinate = 0 + offset;
}

void Coordinate::setYCoordinateToMax(int offset){
    m_yCoordinate = m_frameHeight - offset;
}

void Coordinate::setXCoordinateToMax(int offset){
    m_xCoordinate = m_frameWidth - offset;
}

unsigned int Coordinate::getFrameHeight(){
    return m_frameHeight;
}

unsigned int Coordinate::getFrameWidth(){
    return m_frameWidth;
}


