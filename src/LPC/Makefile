# Makefile of the library "LPC"
# David Weenink 20051012


include ../makefile.defs

CFLAGS = -I ../num -I ../dwtools -I ../fon -I ../sys -I ../dwsys -I ../stat

all: libLPC.a

clean:
	rm *.o

OBJECTS = Cepstrum.o Cepstrumc.o Cepstrum_and_Spectrum.o \
	LPC.o LPC_and_Cepstrumc.o LPC_and_Formant.o LPC_and_LFCC.o \
	LPC_and_Polynomial.o \
	LPC_to_Spectrum.o  LPC_to_Spectrogram.o \
	LPC_and_Tube.o \
	Sound_and_LPC.o  Sound_and_LPC_robust.o \
	Sound_and_Cepstrum.o Tube.o \
	praat_LPC_init.o manual_LPC.o

$(OBJECTS): *.h ../num/NUM.h ../dwtools/*.h ../fon/*.h ../sys/*.h ../dwsys/*.h ../stat/*.h

libLPC.a: $(OBJECTS)
	touch libLPC.a
	rm libLPC.a
	ar cq libLPC.a $(OBJECTS)
	$(RANLIB) libLPC.a
