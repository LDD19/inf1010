CC = g++
CCFLAGS = -Wall
LDFLAGS = 
EXEC = image

all: Pixel.o Main.o
	$(CC) -o $(EXEC) src/Pixel.o src/Main.o $(LDFLAGS)

Main.o: src/Main.cpp
	$(CC) -o src/Main.o -c src/Main.cpp $(CCFLAGS)


Pixel.o: src/Pixel.h src/Pixel.cpp
	$(CC) -o src/Pixel.o -c src/Pixel.cpp $(CCFLAGS)
