#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{

    int m_x;
    int m_y;

public:

    Coordinate(int x,int y);
    Coordinate(unsigned int x,unsigned int y);

    ~Coordinate();


    int getX()const;
    int getY()const;
    void setX(int x);
    void setY(int y);

};





#endif // COORDINATE_H_INCLUDED
