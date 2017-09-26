CC = g++
CCFLAGS = -Wall -Wextra -g
LDFLAGS =
EXEC = image

SRCDIR = src
BUILD  = build

OBJECTS = $(BUILD)/Pixel.o \
          $(BUILD)/Image.o \
          $(BUILD)/GroupImage.o \
          $(BUILD)/Main.o

all: .PHONY $(OBJECTS)
	$(CC) -o $(BUILD)/$(EXEC) $(OBJECTS) $(LDFLAGS)

$(BUILD)/Main.o: $(SRCDIR)/Main.cpp
	$(CC) -o $(BUILD)/Main.o -c $(SRCDIR)/Main.cpp $(CCFLAGS)

$(BUILD)/Pixel.o: $(SRCDIR)/Pixel.h \
                  $(SRCDIR)/Pixel.cpp
	$(CC) -o $(BUILD)/Pixel.o -c $(SRCDIR)/Pixel.cpp $(CCFLAGS)

$(BUILD)/Image.o: $(SRCDIR)/Image.h \
                  $(SRCDIR)/Image.cpp \
                  $(SRCDIR)/Pixel.h
	$(CC) -o $(BUILD)/Image.o -c $(SRCDIR)/Image.cpp $(CCFLAGS)

$(BUILD)/GroupImage.o: $(SRCDIR)/GroupImage.h \
                       $(SRCDIR)/GroupImage.cpp \
                       $(SRCDIR)/Image.h
	$(CC) -o $(BUILD)/GroupImage.o -c $(SRCDIR)/GroupImage.cpp $(CCFLAGS)

.PHONY:
	mkdir -p $(BUILD)

clean:
	rm -vf $(OBJECTS)
	rm -vf $(BUILD)/$(EXEC)

mrproper:
	rm -rf $(BUILD)
