CC = gcc
MKDIR_P = mkdir -p

SRCDIR = src
TARGETDIR = bin
BUILDDIR = $(TARGETDIR)/obj

all: directories prngSmallCrush testEngine noRand cleanobj

.PHONY: directories clean cleanobj
directories:
	$(MKDIR_P) $(BUILDDIR)
clean:
	$(RM) -r $(TARGETDIR)
cleanobj:
	$(RM) -r $(BUILDDIR)

prngSmallCrush: $(TARGETDIR)/prngSmallCrush

$(TARGETDIR)/prngSmallCrush: $(BUILDDIR)/prngSmallCrush.o
	$(CC) -o $@ $^ -Iinclude -Llib -ltestu01 -ltestu01probdist -ltestu01mylib -lm -lcrypto

$(BUILDDIR)/prngSmallCrush.o: $(SRCDIR)/prngSmallCrush.c
	$(CC) -o $@ -c $^

testEngine: $(TARGETDIR)/testEngine.so
	openssl engine -t -c $(PWD)/$<

$(TARGETDIR)/testEngine.so: $(BUILDDIR)/testEngine.o $(BUILDDIR)/noRand.o
	$(CC) -shared -o $@ $^
	
$(BUILDDIR)/testEngine.o: $(SRCDIR)/testEngine.c
	$(CC) -fPIC -o $@ -c $<

noRand: $(TARGETDIR)/noRand

$(TARGETDIR)/noRand: $(BUILDDIR)/noRand.o
	$(CC) -o $@ $^ -lcrypto

$(BUILDDIR)/noRand.o: $(SRCDIR)/noRand.c
	$(CC) -fPIC -o $@ -c $<