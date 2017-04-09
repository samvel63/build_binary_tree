CC = gcc
LDFLAGS =-std=c99 -Wall -Wextra -Werror -Wshadow -Wstrict-prototypes -Wold-style-definition -pedantic -O2 -Wno-unused-variable -Wno-sign-compare -Wno-unused-variable -Wno-unused-result -Wno-unused-parameter
CFLAGS =-c -std=c99 -Wall -Wextra -Werror -Wshadow -Wstrict-prototypes -Wold-style-definition -pedantic -O2 -Wno-unused-variable -Wno-sign-compare -Wno-unused-variable -Wno-unused-result -Wno-unused-parameter
SOURCES = main.o bintree.o
EXECUTABLE = start

all: $(EXECUTABLE)


$(EXECUTABLE): $(SOURCES)
	$(CC) $(LDLAGS) $(SOURCES) -o $@


.c.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	-rm -f *.o start