# INCLUDE = -I/usr/include/
# LIBDIR  = -L/usr/X11R6/LIBDIR

COMPILERFLAGS = -Wall
CC = g++
CFLAGS = $(COMPILERFLAGS) $(INCLUDE)
LIBRARIES = -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm

all: bin RubiksCube clean

# Initialise bin folder
bin:
	mkdir -p bin

RubiksCube.o:
	$(CC) $(CFLAGS) -c RubiksCube.cpp $(LIBRARIES)

RubiksCube: RubiksCube.o
	$(CC) $(CFLAGS) -o RubiksCube.lexec RubiksCube.o $(LIBRARIES)

clean:
	find . -type f -name '*.o' -delete