CFLAGS=-Wall -g
SOURCES=ex1 ex4 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16

all: $(SOURCES)

clean:
	rm -f $(SOURCES)
	rm -rf *.dSYM
