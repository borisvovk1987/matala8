#ifndef BOARD_H
#define BOARD_H


#include "Coordinate.h"
#include"BoardRow.h"
#include"IllegalCoordinateException.h"

#include <sys/stat.h>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board
{
private:
    int m_boardSize;
    BoardRow* m_board;

     bool fileExists( const string& filename);        // I used a function from:
                                                      // https://stackoverflow.com/questions/4316442/stdofstream-check-if-file-exists-before-writing


    void drawO(Coordinate& cor,int gap,RGB *image ,int size); // darwing a O in wanted coordinate
    void drawX(Coordinate& co,int gap,RGB *image,int size);  // drawing a X in a wantedcoordinate
    bool onCircle(int x,int y,Coordinate& cor,int radius);

public:

    Board();
    Board(int boardSize);
    Board(const Board &other);

    ~Board();
    friend std::ostream& operator<<(std::ostream& out,const Board& board );
    friend std::istream& operator>>(std::istream& in,Board& board);
    Board& operator=(const Board&  other );
    Board& operator=(const char cha);
    Content& operator[](Coordinate coordinate)const;
    int size()const;

    std::string draw(int size);

};



#endif
