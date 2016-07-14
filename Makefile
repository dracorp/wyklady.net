#    CC - nazwa kompilatora języka C
#    CXX - nazwa kompilatora języka C++
#    CFLAGS - opcje kompilatora języka C
#    CXXLAGS - opcje kompilatora języka C++
#    LFLAGS - opcje dla linkera

#    < - aktualnie przetwarzany plik z listy składników (patrz przykład)
#    @ - nazwa pliku docelowego
#    ^ - składniki


CFLAGS=-march=native -O2 -pipe
CXXFLAGS="${CFLAGS}"

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
BINS = $(SOURCES:.c=)

all: $(BINS)

print:
	@echo $(BINS)

clean:
	@rm -f $(BINS)

%: %.c
	$(CXX) $(CFLAGS) $< -o $@


.PHONY: all clean
