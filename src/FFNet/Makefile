# Makefile of the library "FFNet"
# David Weenink 19990223
# djmw 20081011 Latest modification.


include ../makefile.defs

CFLAGS = -I ../num -I ../dwtools -I ../fon -I ../sys -I ../dwsys -I ../stat

all: libFFNet.a

clean:
	rm *.o

OBJECTS = FFNet.o \
	FFNet_Eigen.o FFNet_Matrix.o FFNet_Pattern.o \
	FFNet_Activation_Categories.o FFNet_Pattern_Activation.o \
	FFNet_Pattern_Categories.o \
	praat_FFNet_init.o manual_FFNet.o

$(OBJECTS): *.h ../num/NUM.h ../sys/*.h ../dwtools/*.h ../fon/*.h ../dwsys/*.h ../stat/*.h

libFFNet.a: $(OBJECTS)
	touch libFFNet.a
	rm libFFNet.a
	ar cq libFFNet.a $(OBJECTS)
	$(RANLIB) libFFNet.a
