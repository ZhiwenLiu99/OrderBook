CC=g++
CCG=g++ -std=gnu++11
CCC=g++ -std=c++11

ReconstructOrderBook: main.cpp messageHandler.hpp
	$(CC) main.cpp messageHandler.hpp -o ReconstructOrderBook.out