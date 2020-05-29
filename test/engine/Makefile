CC = gcc
CFLAGS = -fPIC
LDFLAGS = -shared

testEngine: testEngine.so
	openssl engine -t -c $(PWD)/$^

testEngine.so: testEngine.o ../noRand/noRand.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
testEngine.o: testEngine.c ../noRand/noRand.c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean
clean:
	$(RM) testEngine.so testEngine.o ../noRand/noRand.o
