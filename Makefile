COMPILER=gcc
VERSION=-std=c2x
FLAGS=-Werror -Wall -pedantic -fsanitize=address
INCPATH=-I./
LIBPATH=-L./
SRC:=$(wildcard ./*.c)
LIBS=-lm -lpthread
TARGET=./main

.SILENT:
.PHONY: all clean

all:
	${COMPILER} ${VERSION} ${FLAGS} ${INCPATH} ${LIBPATH} ${SRC} ${LIBS} -o ${TARGET}
	${TARGET}

clean:
	$(RM) ${TARGET}