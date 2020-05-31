CC = gcc
MKDIR_P = mkdir -p

SRCDIR = src
TARGETDIR = bin
BUILDDIR = $(TARGETDIR)/obj

all: directories qrngSmallCrush qrngEngine qRand cleanobj

.PHONY: directories clean cleanobj
directories:
	$(MKDIR_P) $(BUILDDIR)
clean:
	$(RM) -r $(TARGETDIR)
cleanobj:
	$(RM) -r $(BUILDDIR)

qrngSmallCrush: $(TARGETDIR)/qrngSmallCrush

$(TARGETDIR)/qrngSmallCrush: $(BUILDDIR)/qrngSmallCrush.o
	$(CC) -o $@ $^ -Iinclude -Llib -ltestu01 -lprobdist -lmylib -lm -lcrypto

$(BUILDDIR)/qrngSmallCrush.o: $(SRCDIR)/qrngSmallCrush.c
	$(CC) -o $@ -c $^

qrngEngine: $(TARGETDIR)/qrngEngine.so
	openssl engine -t -c $(PWD)/$<

$(TARGETDIR)/qrngEngine.so: $(BUILDDIR)/qrngEngine.o #$(BUILDDIR)/qRand.o
	$(CC) -shared -o $@ $^
	
$(BUILDDIR)/qrngEngine.o: $(SRCDIR)/qrngEngine.c
	$(CC) -fPIC -o $@ -c $<

qRand: $(TARGETDIR)/qRand

$(TARGETDIR)/qRand: $(BUILDDIR)/qRand.o
	$(CC) -o $@ $^ -lcrypto

$(BUILDDIR)/qRand.o: $(SRCDIR)/qRand.c
	$(CC) -fPIC -o $@ -c $<