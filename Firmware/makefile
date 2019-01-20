
#command to compile
#mingw32-make

OBJ_NAME = main.exe

#All directories to search through for include files
INC = -IC:\repos\FirstRepo\SDL2-2.0.9\i686-w64-mingw32\include\SDL2 -I.

#all libraries to include
LIB = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

#all pathes to search for libraries
LIB_PATH = -LC:\Repos\FirstRepo\SDL2-2.0.9\i686-w64-mingw32\lib

CPPFILES = GameWindow.cpp
CPPFILES += dot.cpp
CPPFILES += Texture.cpp
CPPFILES += Button.cpp
CPPFILES += ButtonActions.cpp



main: 
	g++ main.cpp $(CPPFILES) -g $(INC) $(LIB_PATH) $(LIB) -o $(OBJ_NAME)


#g++ 01_hello_SDL.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o 01_hello_SDL