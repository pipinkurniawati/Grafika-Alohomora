all: Rubik.cpp

Rubik.o: Rubik.cpp
	g++ -c -o Rubik.o Rubik.cpp -Iinclude/
	
Rubik: Rubik.o
	g++ -o Rubik Rubik.o -Llib/ -lfreeglut -lopengl32 -lwinmm -lgdi32 -Wl,--subsystem,windows