

#mingw32-make

INC = -I raylib/src -I raylib/src/external

main: 
	gcc main.cpp $(INC) -c raylib/src/core.c

#g++ main.cpp -o hello.exe -Lraylib/src -lraylib.h

#g++ main.cpp -o hello.exe -I raylib/src -I raylib/src/external

#g++ 01_hello_SDL.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o 01_hello_SDL