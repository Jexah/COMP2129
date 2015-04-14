CC=clang
CFLAGS=-std=c11 -g -Wall -fsanitize=address

TARGETS=todo

.PHONY: clean

all: $(TARGETS)

todo.o: todo.c
	$(CC) -c $(CFLAGS) $^ -o $@

list.o: list.c
	$(CC) -c $(CFLAGS) $^ -o $@

todo: todo.o list.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(TARGETS)
	rm -f *.o
