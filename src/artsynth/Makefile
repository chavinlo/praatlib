# Makefile of the library "artsynth"
# Paul Boersma, April 9, 2008

include ../makefile.defs
CFLAGS = -I ../num -I ../sys -I ../fon -I ../stat

all: libartsynth.a

OBJECTS = Speaker.o Articulation.o Artword.o \
     Art_Speaker.o Art_Speaker_to_VocalTract.o Artword_Speaker.o Artword_Speaker_Sound.o \
     Artword_Speaker_to_Sound.o Artword_to_Art.o \
     Delta.o Speaker_to_Delta.o Art_Speaker_Delta.o \
     ArtwordEditor.o praat_Artsynth.o manual_Artsynth.o

libartsynth.a: $(OBJECTS)
	touch libartsynth.a
	rm libartsynth.a
	ar cq libartsynth.a $(OBJECTS)
	$(RANLIB) libartsynth.a

$(OBJECTS): *.h ../num/NUM.h ../sys/*.h ../fon/*.h ../stat/*.h

