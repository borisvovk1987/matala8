#include"BoardRow.h"
//#include"Content.h"


BoardRow::BoardRow(int rowSize):m_rowSize(rowSize)
{
    m_boardRow=new Content[m_rowSize];
}

BoardRow::BoardRow(const BoardRow &other)
{
    m_rowSize=other.m_rowSize;
    if(other.m_boardRow)
    {
        m_boardRow=new Content[m_rowSize];
        for(int i=0;i<m_rowSize;i++)
        {
            m_boardRow[i]=other.m_boardRow[i];
        }
    }


}



BoardRow::~BoardRow()
{
    delete[] m_boardRow;
}


void BoardRow::setBoardRow(const int size)
{
        if(m_boardRow)
        {
            delete[] m_boardRow;
        }
        m_boardRow=new Content[size];
        m_rowSize=size;

}
std::ostream& operator<<(std::ostream& out,const BoardRow &row)
    {
          for(int i=0;i<row.m_rowSize;i++)
        {
            out<<row.m_boardRow[i];
        }
        std::cout<<"\n";
        return out;
    }
BoardRow& BoardRow::operator=(const BoardRow& other)
{
     if(this==&other)
            return *this;

        delete[] m_boardRow;

        m_rowSize=other.m_rowSize;
        m_boardRow=new Content[m_rowSize];
        for(int i=0;i<m_rowSize;i++)
        {
            m_boardRow[i]=other.m_boardRow[i];
        }
        return *this;
}
BoardRow& BoardRow::operator=(const char cha )
{
    if(m_boardRow)
    {
        for(int i=0;i<m_rowSize;i++)
        {
            m_boardRow[i]=cha;
        }
    }
    return *this;
}

Content& BoardRow::operator[](const int index)
{
    return m_boardRow[index];
}







