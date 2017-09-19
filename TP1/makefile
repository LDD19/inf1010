CC = g++
CCFLAGS = -Wall -g
LDFLAGS =
EXEC = image

all: Pixel.o Image.o GroupImage.o Main.o
	$(CC) -o $(EXEC) \
		src/Pixel.o \
		src/Image.o \
		src/GroupImage.o \
		src/Main.o $(LDFLAGS)

Main.o: src/Main.cpp
	$(CC) -o src/Main.o -c src/Main.cpp $(CCFLAGS)

Pixel.o: src/Pixel.h src/Pixel.cpp
	$(CC) -o src/Pixel.o -c src/Pixel.cpp $(CCFLAGS)

Image.o: src/Image.h src/Image.cpp src/Pixel.h
	$(CC) -o src/Image.o -c src/Image.cpp $(CCFLAGS)

GroupImage.o: src/GroupImage.h src/GroupImage.cpp src/Image.h
	$(CC) -o src/GroupImage.o -c src/GroupImage.cpp $(CCFLAGS)
