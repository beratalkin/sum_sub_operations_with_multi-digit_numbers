all: Executable

Executable:	main.o	islemler.o
	gcc	main.o	islemler.o	-o	e

main.o:	main.c
	gcc	-c	main.c

islemler.o:	islemler.c	islemler.h
	gcc	-c	islemler.c