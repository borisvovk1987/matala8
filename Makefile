CXX=clang++-5.0
CXXFLAGS=-std=c++17	
	
all:a.out
	


a.out:main.o Board.o BoardRow.o Coordinate.o Content.o IllegalCoordinateException.o
	$(CXX) $(CXXFLAGS) main.o Board.o BoardRow.o Content.o Coordinate.o IllegalCoordinateException.o -o a.out

main.o:main.cpp Board.h 
	$(CXX) $(CXXFLAGS) --compile main.cpp -o main.o 

Board.o:Board.cpp Board.h BoardRow.h IllegalCoordinateException.h Coordinate.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

BoardRow.o:BoardRow.cpp BoardRow.h Content.h
	$(CXX) $(CXXFLAGS) --compile BoardRow.cpp -o BoardRow.o
Coordinate.o:Coordinate.cpp Coordinate.h 
	$(CXX) $(CXXFLAGS) --compile Coordinate.cpp -o Coordinate.o 
Content.o:Content.cpp Content.h IllegalCharException.h
	$(CXX) $(CXXFLAGS) --compile Content.cpp -o Content.o 

IllegalCoordinateException.o:IllegalCoordinateException.cpp IllegalCoordinateException.h 
$(CXX) $(CXXFLAGS) --compile IllegalCoordinateException.cpp -o IllegalCoordinateException.o
