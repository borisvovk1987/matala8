#ifndef ILLEGALCOORDINATEEXCEPTION_H
#define ILLEGALCOORDINATEEXCEPTION_H

#include<iostream>


class IllegalCoordinateException
{
private:
    int m_row;
    int m_col;

public:
    IllegalCoordinateException(int row,int col):m_row(row),m_col(col)
    {
    }
    friend std::ostream& operator<<(std::ostream& out,const IllegalCoordinateException& illegalCor);

    IllegalCoordinateException theCoordinate()const
    {
        return *this;

    }

};




#endif
