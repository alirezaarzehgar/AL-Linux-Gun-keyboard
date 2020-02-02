CC  = cc
INP = *.c
OUT = AL-Gun-Key
LIB = `pkg-config --libs --cflags gtk+-2.0`
ARG = -g -w -Wall

all:
	$(CC) $(ARG) -o $(OUT) $(INP) $(LIB)
