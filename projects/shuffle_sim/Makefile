CC=gcc
CFLAGS=-Wall -pedantic -g -std=c99 -O0

DEPS = diversification.h rand.h

OBJ = main.o rand.o diversification.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(INCDIR)/*~
