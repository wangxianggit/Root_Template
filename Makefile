#OBJ = DSSD2Tr_March TSCorrSiGe DSSDGeMerge separate_March BuildDecay DSSDGeCorr PLASTIC2Tr
#OBJ = online_DSSD WASABI2Tr
#OBJ = enthe 
#sourcefile = main.cpp enthe.cpp enthe.h 

EXE = cali
sourcefile = main.cpp cali.h cali.cpp
OBJ = $(subst,.cpp,.o,$(filter %.cpp,$(sourcefile)))

ROOTCFLAGS  = $(shell root-config --cflags)
ROOTLIBS    = $(shell root-config --libs)

CFLAGS = -Wall -O2 -I$(ROOTSYS)/include -lXMLParser -lSpectrum
#-lanacore

GXX = g++ 
#-std=c++0x

all:$(EXE)

$(EXE):main.o cali.o
	$(GXX) $(ROOTCFLAGS) $(ROOTLIBS) -o $(EXE) main.o cali.o
	

main.o: main.cpp cali.h
	$(GXX)  $(ROOTCFLAGS) $(ROOTLIBS) -c main.cpp

cali.o: cali.cpp cali.h
	$(GXX) $(ROOTCFLAGS) $(ROOTLIBS) -c cali.cpp
clean:
	rm -f *~ *.o $(EXE)
