#ifndef BOARDROW_H
#define BOARDROW_H

#include"Content.h"
#include<iostream>
class  BoardRow
{
private:
    int m_rowSize;
    Content* m_boardRow;



public:
    BoardRow()
    {
       m_rowSize=0;
       m_boardRow=NULL;
    }
    BoardRow(int rowSize);
    BoardRow(const BoardRow &other);

    ~BoardRow();

     void setBoardRow(const int size);
    // overloded operators decleration
    friend std::ostream& operator<<(std::ostream& out,const BoardRow &row);
    BoardRow& operator=(const BoardRow& other);
    BoardRow& operator=(const char cha);
    Content& operator[]( const int index);



};


#endif
