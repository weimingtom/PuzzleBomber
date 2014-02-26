# Project: 
# Makefile created by Dev-C++ 4.9.9.2

CPP  = g++
CC   = gcc
WINDRES = 
RES  = 
OBJ  =   main.o  $(RES)
LINKOBJ  = main.o  $(RES)
LIBS =  -lSDLmain -lSDL -lSDL_ttf -lSDL_mixer -lSDL_image  
INCS = 
CXXINCS =
BIN  = puzzlebomber
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)  
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before puzzlebomber all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "puzzlebomber" $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp  -o main.o  $(CXXFLAGS) -w 


