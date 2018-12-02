

#mingw32-make

INC = raylib/src

main: 
	g++ main.cpp -o hello.exe -I $(INC)

#g++ main.cpp -o hello.exe -Lraylib/src -lraylib.h