CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lcrypto

noRand: noRand.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

noRand.o: noRand.c noRand.h
	$(CC) $(CFLAGS) -c $^

.PHONY: clean
clean:
	$(RM) noRand noRand.o
