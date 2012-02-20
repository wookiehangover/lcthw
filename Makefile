CFLAGS=-Wall -g
SOURCES=ex1 ex4 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex20

all: $(SOURCES)

clean:
	rm -f $(SOURCES)
	rm -f *.dat
	rm -rf *.dSYM
