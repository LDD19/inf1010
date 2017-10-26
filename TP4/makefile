CC := g++

CCFLAGS := -Wall -Wextra -g
LDFLAGS :=

EXEC := image

SRCDIR := src
BUILD  := build

OBJECTS := $(BUILD)/Main.o

all: dirs $(OBJECTS)
	$(CC) -o $(BUILD)/$(EXEC) $(OBJECTS) $(LDFLAGS)

$(BUILD)/Main.o: $(SRCDIR)/Main.cpp
	$(CC) -o $(BUILD)/Main.o -c $(SRCDIR)/Main.cpp $(CCFLAGS)

$(BUILD)/Pixel.o: $(SRCDIR)/Pixel.cpp \
                  $(SRCDIR)/Pixel.h \
                  $(SRCDIR)/TypePixel.h
	$(CC) -o $(BUILD)/Pixel.o -c $(SRCDIR)/Pixel.cpp $(CCFLAGS)

$(BUILD)/PixelCouleur.o: $(SRCDIR)/PixelCouleur.cpp \
                         $(SRCDIR)/PixelCouleur.h \
                         $(SRCDIR)/Pixel.h \
                         $(SRCDIR)/TypePixel.h
	$(CC) -o $(BUILD)/PixelCouleur.o -c $(SRCDIR)/PixelCouleur.cpp $(CCFLAGS)

$(BUILD)/PixelGris.o: $(SRCDIR)/PixelGris.cpp \
                      $(SRCDIR)/PixelGris.h \
                      $(SRCDIR)/Pixel.h \
                      $(SRCDIR)/TypePixel.h
	$(CC) -o $(BUILD)/PixelGris.o -c $(SRCDIR)/PixelGris.cpp $(CCFLAGS)

$(BUILD)/PixelBN.o: $(SRCDIR)/PixelBN.cpp \
                    $(SRCDIR)/PixelBN.h \
                    $(SRCDIR)/Pixel.h \
                    $(SRCDIR)/TypePixel.h
	$(CC) -o $(BUILD)/PixelBN.o -c $(SRCDIR)/PixelBN.cpp $(CCFLAGS)

$(BUILD)/Image.o: $(SRCDIR)/Image.cpp \
                  $(SRCDIR)/Image.h \
                  $(SRCDIR)/PixelCouleur.h \
                  $(SRCDIR)/PixelGris.h \
                  $(SRCDIR)/PixelBN.h \
                  $(SRCDIR)/Pixel.h \
                  $(SRCDIR)/TypePixel.h
	$(CC) -o $(BUILD)/Image.o -c $(SRCDIR)/Image.cpp $(CCFLAGS)

$(BUILD)/Bitmap.o: $(SRCDIR)/Bitmap.cpp
	$(CC) -o $(BUILD)/Bitmap.o -c $(SRCDIR)/Bitmap.cpp $(CCFLAGS)

$(BUILD)/GroupeImage.o: $(SRCDIR)/GroupeImage.cpp \
                        $(SRCDIR)/GroupeImage.h \
                        $(SRCDIR)/Image.h
	$(CC) -o $(BUILD)/GroupeImage.o -c $(SRCDIR)/GroupeImage.cpp $(CCFLAGS)

dirs:
	mkdir -p $(BUILD)

clean:
	rm -vf $(OBJECTS)
	rm -vf $(BUILD)/$(EXEC)

mrproper:
	rm -rf $(BUILD)
