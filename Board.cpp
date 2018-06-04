#include"Board.h"




//****** constrocturs *****
Board::Board()
{
    m_boardSize=0;
    m_board=NULL;
}
Board::Board(const Board& other)
{

    if(other.m_board)
    {
        m_boardSize=other.m_boardSize;
        m_board=new BoardRow[m_boardSize];
        for(int i=0;i<m_boardSize;i++)
        {
            m_board[i]=other.m_board[i];
        }

    }


}
Board::Board(int boardSize):m_boardSize(boardSize)
{
    try
    {
        if(boardSize<=0)
            throw "The size most be biger then 0";
        m_board=new BoardRow[boardSize];
        for(int i=0;i<boardSize;i++)
        {
            m_board[i].setBoardRow(boardSize);
        }
    }
    catch(const char* exeption )
    {
        std::cout<<"Eror: "<<exeption<<std::endl;
    }

}

//**** destructor*****

Board::~Board()
{
    delete[] m_board;

}

//**** overloded operators *****

std::ostream& operator<<(std::ostream& out,const Board &board)
{
    for(int i=0;i<board.m_boardSize;i++)
    {
        out<<board.m_board[i]<<"\n";
    }
    return out;
}
std::istream& operator>>(std::istream& in,Board &board)
{
	std::string path="";
	in>>path;
	std::ifstream readFile;
	readFile.open(path);



	if(readFile)
	{
        // calculating the size of the board in the file.
		readFile.seekg(0,readFile.end);
		int length = readFile.tellg();
		readFile.seekg(0,readFile.beg);

		int newBoardSize=sqrt(length);
		Board brd{newBoardSize};

        //coping the board in the file
		for(int i=0;i<newBoardSize;i++)
		{
			BoardRow br{newBoardSize};
			for(int j=0;j<newBoardSize;j++)
			{
                char ch;
                readFile>>ch;
				brd[{i,j}]=ch;

			}
		}
		board=brd;

	}
	else
	{
		std::cout<<"Unable to open file"<<std::endl;
	}

    readFile.close();
	return in;


}

Board& Board::operator=(const Board& other)
{
    if(this==&other)
        return *this;

    delete[] m_board;
    m_boardSize=other.m_boardSize;
    m_board=new BoardRow[m_boardSize];
    for(int i=0;i<m_boardSize;i++)
    {
        m_board[i]=other.m_board[i];
    }
    return *this;

}
Board& Board::operator=(const char cha)
{
    try{
        if(cha!='X' && cha!='O' && cha!='.')
            throw IllegalCharException(cha);
        if(m_board)
        {
            for(int i=0;i<m_boardSize;i++)
            {
                m_board[i]=cha;
            }
        }

    }
    catch( IllegalCharException ex)
    {
       std::cout<<"Illegal cahr: "<<ex.theChar()<<std::endl;
    }

    return *this;


}


Content& Board::operator[](Coordinate coordinate)const
{
    if(coordinate.getX()<0 || coordinate.getX()>=m_boardSize || coordinate.getY()<0 || coordinate.getY()>=m_boardSize)
        throw IllegalCoordinateException(coordinate.getX(),coordinate.getY());
    return m_board[coordinate.getX()][coordinate.getY()];

}


int Board::size()const
{
    return m_boardSize;

}

//********************************************
//*********** functions **********************
//********************************************

//*************** draw function*********

    string Board::draw(int size)
{

    string fileName="board.ppm";
    string fileNameTemp=fileName;
    int i=0;

    while(fileExists(fileNameTemp))
    {
       fileNameTemp =fileName+to_string(i)+".ppm";
       i++;
    }
    fileName=fileNameTemp;	    
    const int dimx=size,dimy=size;
    ofstream imageFile(fileName, ios::out | ios::binary);
    imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;

   RGB image[size*size];
   for(int i=0;i<size*size;i++)
   {
        image[i].red=120;
        image[i].blue=255;
        image[i].green=120;

   }


   int gap=size/m_boardSize;
    for(int i=0;i<size;i++){        // this loop maks coloms

        for(int j=0;j<size;j=j+gap)
        {
            image[size*i+j].red=255;
            image[size*i+j].green=0;
            image[size*i+j].blue=0;
        }

    }

    for(int i=0;i<size;i=i+gap)
    {
        for(int j=0;j<size;j++)
        {
            image[size*i+j].red=255;
            image[size*i+j].green=0;
            image[size*i+j].blue=0;
        }

    }

    for(int i=0;i<m_boardSize;i++)
    {
        for(int j=0;j<m_boardSize;j++)
        {

            Coordinate cor={i,j};
            if(m_board[i][j].getChar()=='X')
            {

               drawX(cor,gap,image,size);
            }
            else if(m_board[i][j].getChar()=='O')
            {

                drawO(cor,gap,image,size);
            }
        }
   }



    imageFile.write(reinterpret_cast<char*>(&image), 3*size*size);
    imageFile.close();


    return fileName;
}



//************************* private functions *************************

// Function: fileExists
// this function checks if the file is already exsists
/**
    Check if a file exists
@param[in] filename - the name of the file to check

@return    true if the file exists, else false

*/
bool Board::fileExists( const string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}


//  this function draws O in the table
void Board::drawO(Coordinate& cor,int gap,RGB *image ,int size)
{
    int radius=gap/3;

    int centerX=cor.getX()*gap+(gap/2);
    int centerY=cor.getY()*gap+(gap/2);
    Coordinate center{centerX,centerY};
    int startX=cor.getX()*gap+(gap/10);
    int startY=cor.getY()*gap+(gap/10);

    for(int i=startX;i<startX+gap-2*((gap/10));i++)
    {
        for(int j=startY;j<startY+gap-2*((gap/10));j++)
        {

            if(onCircle(i,j,center,radius))
            {
                image[size*i+j].green=255;
            }
        }

    }


}

// this function draws X in the table.
void Board::drawX(Coordinate& cor,int gap,RGB *image,int size)
{
    int startX=cor.getX()*gap+(gap/10);
    int startY=cor.getY()*gap+(gap/10);

    for(int i=startX,j=startY;i<startX+gap-2*((gap/10));i++,j++)
    {
        image[size*i+j].green=255;

    }
    int startX2=startX+gap-2*(gap/10);
    startY=startY;
    for(int i=startX2,j=startY;i>startX;i--,j++)
    {

        image[size*i+j].green=255;
    }

}


// this function checks if the point is on the circle withe the praticular radius
// if it is the case we draw in that point
bool Board::onCircle(int x,int y,Coordinate& cor ,int radius)
{
    int distance=pow(pow(x-cor.getX(),2)+pow(y-cor.getY(),2),0.5);
    return (distance==radius);

}
