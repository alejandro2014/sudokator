CC=gcc
EXE=sudokator
OBJDIR=obj
SRCDIR=src

#${EXE}: obj/init.o obj/print.o obj/sudokator.o
#	${CC} obj/init.o obj/print.o obj/sudokator.o -o ${EXE}
${EXE}: obj/init.o obj/sudokator.o
	${CC} obj/init.o obj/sudokator.o -o ${EXE}

obj/init.o: src/init.c
	${CC} -c src/init.c -o obj/init.o

#obj/print.o: src/print.c
#	${CC} -c src/print.c -o obj/print.o

obj/sudokator.o: src/sudokator.c
	${CC} -c src/sudokator.c -o obj/sudokator.o

clean:
	rm obj/* ${EXE}
