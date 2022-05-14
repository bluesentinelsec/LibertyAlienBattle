cc="clang"
cflags=-I/usr/local/include/SDL2 -D_THREAD_SAFE -L/usr/local/lib -lSDL2 -I/opt/homebrew/include/ -L/opt/homebrew/lib -lSDL2_image

all: compile link

compile: src/main.c
	$(cc) $(cflags) -c src/main.c -o obj/main.o

link: obj/main.o
	$(cc) $(cflags) -o game obj/main.o