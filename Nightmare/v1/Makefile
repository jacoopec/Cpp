CPPFLAGS := -pthread
all: pjt

pjt: canvas main
	gcc main.o canvas.o -o main
canvas:
	gcc canvas.c -c
main:
	gcc main.c -c
