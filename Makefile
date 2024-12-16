CFLAGS=$(cat CFLAGS)
DEPENDENCIES=-I./3rdparty/stc/include/ -I./3rdparty/pimbs/
CFILES="src/ecs.c"
CC=clang
BUILDDIR=build/
OUT=${BUILDDIR}main

all:
	mkdir -p ${BUILDDIR}
	${CC} ${CFILES} ${CFLAGS} ${DEPENDENCIES} -o ${OUT}

clean:
	trash build
