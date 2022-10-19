CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

gameOfLife: main.o grid.o cell.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: ./src/main.cc ./lib/grid.h ./lib/cell.h 
	$(CXX) -c ./src/main.cc

grid.o: ./src/grid.cc ./lib/grid.h
	$(CXX) -c ./src/grid.cc

cell.o: ./src/cell.cc ./lib/cell.h 
	$(CXX) -c ./src/cell.cc