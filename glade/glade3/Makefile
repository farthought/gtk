CC=gcc
CFLAGS=-Wall -g
SIG=-export-dynamic
FLAGS=`pkg-config --cflags --libs gtk+-3.0`

tutorial:main.c
	${CC} ${CFLAGS} -o $@ $< ${SIG} ${FLAGS}

.PHONY:

clean:
	rm tutorial
