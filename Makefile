CC=gcc
EXE=sudokator
OBJDIR=obj
SRCDIR=src

${EXE}: obj/sudokator.o obj/print.o
	${CC} obj/sudokator.o obj/print.o -o ${EXE}

obj/sudokator.o: src/sudokator.c
	${CC} -c src/sudokator.c -o obj/sudokator.o

obj/print.o: src/print.c
	${CC} -c src/print.c -o obj/print.o
