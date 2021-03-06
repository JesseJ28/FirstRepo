
#command to compile
#mingw32-make

OBJ_NAME = main.exe

#All directories to search through for include files
INC = -I$(CURDIR)\SDL2-2.0.9\include -I.

#all libraries to include
LIB =  -lSDL2main -lSDL2  -lSDL2_ttf -lSDL2_image
#-lmingw32
#-lSDL2_image

#all pathes to search for libraries
LIB_PATH = -L$(CURDIR)\SDL2-2.0.9\lib\x86

CPPFILES = Firmware/GameWindow.cpp
CPPFILES += Firmware/dot.cpp
CPPFILES += Firmware/Texture.cpp
CPPFILES += Firmware/Button.cpp
CPPFILES += Firmware/ButtonActions.cpp
#$(CPPFILES)


main: 
	g++ Firmware/main.cpp $(CPPFILES) -g $(INC) $(LIB_PATH) $(LIB) -o $(OBJ_NAME)


#g++ 01_hello_SDL.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o 01_hello_SDL