prog:personnage.o main.o
	gcc personnage.o main.o -o prog -L/usr/include/SDL  -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c
personnage.o:personnage.c
	gcc -c personnage.c
