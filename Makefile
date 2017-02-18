CC=gcc
EXE=sudokator
OBJDIR=obj
SRCDIR=src

${EXE}: obj/sudokator.o
	${CC} obj/sudokator.o -o ${EXE}

obj/sudokator.o: src/sudokator.c
	${CC} -c -o $@ $<
