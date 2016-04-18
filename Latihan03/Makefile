all: Rubik.cpp

Rubik.o: Rubik.cpp
	g++ -c -o Rubik.o Rubik.cpp -Iinclude/
	
Rubik: Rubik.o
	g++ -o Rubik Rubik.o -Llib/ -lfreeglut -lopengl32 -lwinmm -lgdi32 -Wl,--subsystem,windows

coba: coba3.cpp
	g++ coba3.cpp -o coba -Llib-mingw/ -lglfw3 -lopengl32 -lgdi32