#ifndef ILLEGALCHAREXCEPTION_H
#define ILLEGALCHAREXCEPTION_H

#include<iostream>

class IllegalCharException
{
private:
    char m_illegalChar;

public:
    IllegalCharException(char illegalChar):m_illegalChar(illegalChar)
    {
    }


    char theChar()const
    {
        return  m_illegalChar;
    }

};






#endif
