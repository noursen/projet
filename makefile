prog:personnage.o main.o
	gcc personnage.o main.o -o prog
main.o:main.c
	gcc -c main.c
personnage.o:personnage.c
	gcc -c personnage.c
