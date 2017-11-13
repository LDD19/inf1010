CC := g++

CCFLAGS := -Wall -Wextra -g
LDFLAGS :=

EXEC := image

SRCDIR := src
BUILD  := build

OBJECTS := $(BUILD)/Main.o \
           $(BUILD)/Pixel.o \
           $(BUILD)/PixelCouleur.o \
           $(BUILD)/PixelGris.o \
           $(BUILD)/PixelBN.o \
           $(BUILD)/Image.o \
           $(BUILD)/Bitmap.o \
           $(BUILD)/GroupeImage.o \
           $(BUILD)/BaseDeDonnesSpecifique.o

all: dirs $(OBJECTS)
	$(CC) -o $(BUILD)/$(EXEC) $(OBJECTS) $(LDFLAGS)

$(BUILD)/Main.o: $(SRCDIR)/Main.cpp \
                 $(SRCDIR)/BaseDeDonnesGenerique.h \
                 $(SRCDIR)/BaseDeDonnesSpecifique.h \
                 $(SRCDIR)/GroupeImage.h \
                 $(SRCDIR)/Foncteur.h
	$(CC) -o $@ -c $< $(CCFLAGS)

$(BUILD)/Pixel.o: $(SRCDIR)/Pixel.cpp \
                  $(SRCDIR)/Pixel.h \
                  $(SRCDIR)/TypePixel.h
	$(CC) -o $@ -c $< $(CCFLAGS)

$(BUILD)/PixelCouleur.o: $(SRCDIR)/PixelCouleur.cpp \
                         $(SRCDIR)/PixelCouleur.h \
                         $(SRCDIR)/Pixel.h \
                         $(SRCDIR)/TypePixel.h
	$(CC) -o $@ -c $< $(CCFLAGS)

$(BUILD)/PixelGris.o: $(SRCDIR)/PixelGris.cpp \
                      $(SRCDIR)/PixelGris.h \
                      $(SRCDIR)/Pixel.h \
                      $(SRCDIR)/TypePixel.h
	$(CC) -o $@ -c $< $(CCFLAGS)

$(BUILD)/PixelBN.o: $(SRCDIR)/PixelBN.cpp \
                    $(SRCDIR)/PixelBN.h \
                    $(SRCDIR)/Pixel.h \
                    $(SRCDIR)/TypePixel.h
	$(CC) -o $@ -c $< $(CCFLAGS)

$(BUILD)/Image.o: $(SRCDIR)/Image.cpp \
                  $(SRCDIR)/Image.h \
                  $(SRCDIR)/PixelCouleur.h \
                  $(SRCDIR)/PixelGris.h \
                  $(SRCDIR)/PixelBN.h \
                  $(SRCDIR)/Pixel.h \
                  $(SRCDIR)/TypePixel.h
	$(CC) -o $@ -c $< $(CCFLAGS)

$(BUILD)/Bitmap.o: $(SRCDIR)/Bitmap.cpp
	$(CC) -o $@ -c $< $(CCFLAGS)

$(BUILD)/GroupeImage.o: $(SRCDIR)/GroupeImage.cpp \
                        $(SRCDIR)/GroupeImage.h \
                        $(SRCDIR)/Image.h
	$(CC) -o $@ -c $< $(CCFLAGS)

$(BUILD)/BaseDeDonnesSpecifique.o: $(SRCDIR)/BaseDeDonnesSpecifique.cpp \
                                   $(SRCDIR)/BaseDeDonnesSpecifique.h \
                                   $(SRCDIR)/BaseDeDonnesGenerique.h \
                                   $(SRCDIR)/GroupeImage.h \
                                   $(SRCDIR)/Image.h
	$(CC) -o $@ -c $< $(CCFLAGS)

dirs:
	mkdir -p $(BUILD)

clean:
	rm -vf $(OBJECTS)
	rm -vf $(BUILD)/$(EXEC)

mrproper:
	rm -rf $(BUILD)
