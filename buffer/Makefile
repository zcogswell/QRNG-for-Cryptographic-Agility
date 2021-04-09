CC = gcc
MKDIR_P = mkdir -p

SRCDIR = src
TARGETDIR = bin
BUILDDIR = $(TARGETDIR)/obj

all: directories buffer writeTest readTest bufferSmallCrush bufferTrng cleanobj

.PHONY: directories clean cleanobj
directories:
	$(MKDIR_P) $(BUILDDIR)
clean:
	$(RM) -r $(TARGETDIR)
cleanobj:
	$(RM) -r $(BUILDDIR)

buffer: $(BUILDDIR)/buffer.o

$(BUILDDIR)/buffer.o: $(SRCDIR)/buffer.c
	$(CC) -o $@ -c $^

writeTest: $(TARGETDIR)/writeTest

$(TARGETDIR)/writeTest: $(BUILDDIR)/writeTest.o $(BUILDDIR)/buffer.o
	$(CC) -o $@ $^

$(BUILDDIR)/writeTest.o: $(SRCDIR)/writeTest.c
	$(CC) -o $@ -c $^

readTest: $(TARGETDIR)/readTest

$(TARGETDIR)/readTest: $(BUILDDIR)/readTest.o $(BUILDDIR)/buffer.o
	$(CC) -o $@ $^

$(BUILDDIR)/readTest.o: $(SRCDIR)/readTest.c
	$(CC) -o $@ -c $^

bufferSmallCrush: $(TARGETDIR)/bufferSmallCrush

$(TARGETDIR)/bufferSmallCrush: $(BUILDDIR)/bufferSmallCrush.o $(BUILDDIR)/buffer.o
	$(CC) -o $@ $^ -Iinclude -Llib -ltestu01 -ltestu01probdist -ltestu01mylib -lm -lcrypto

$(BUILDDIR)/bufferSmallCrush.o: $(SRCDIR)/bufferSmallCrush.c
	$(CC) -o $@ -c $^

bufferTrng: $(TARGETDIR)/bufferTrng

$(TARGETDIR)/bufferTrng: $(BUILDDIR)/bufferTrng.o $(BUILDDIR)/buffer.o
	$(CC) -o $@ $^

$(BUILDDIR)/bufferTrng.o: $(SRCDIR)/bufferTrng.c
	$(CC) -o $@ -c $^ -mrdrnd
