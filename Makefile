


CXX=clang++-5.0 
CXXFLAGS=-std=c++17


all:Board.o BoardRow.o Content.o Content.o IllegalCoordinateException.o Coordinate.o  

Board.o:Board.cpp Board.h BoardRow.h Coordinate.h IllegalCoordinateException.h 
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

BoardRow.o:BoardRow.cpp BoardRow.h Content.h
	$(CXX) $(CXXFLAGS) --compile BoardRow.cpp -o BoardRow.o

Content.o:Content.cpp Content.h IllegalCharException.h
	$(CXX) $(CXXFLAGS) --compile Content.cpp -o Content.o

llegalCoordinateException.o:IllegalCoordinateException.cpp IllegalCoordinateException.h 
	$(CXX) $(CXXFLAGS) --compile IllegalCoordinateException.cpp -o IllegalCoordinateException.o

Coordinate.o:Coordinate.cpp Coordinate.h 
	$(CXX) $(CXXFLAGS) --compile Coordinate.cpp -o Coordinate.o


Clean: 
	rm *.o a.out


buildAndRun: all main.o
	$(CXX) $(CXXFLAGS) main.o Board.o BoardRow.o Content.o IllegalCoordinateException.o 
	./a.out
