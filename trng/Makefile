CC = gcc
MKDIR_P = mkdir -p

SRCDIR = src
TARGETDIR = bin
BUILDDIR = $(TARGETDIR)/obj

all: directories trngSmallCrush trngSmallCrush_ssl cleanobj

.PHONY: directories clean cleanobj
directories:
	$(MKDIR_P) $(BUILDDIR)
clean:
	$(RM) -r $(TARGETDIR)
cleanobj:
	$(RM) -r $(BUILDDIR)

trngSmallCrush: $(TARGETDIR)/trngSmallCrush

$(TARGETDIR)/trngSmallCrush: $(BUILDDIR)/trngSmallCrush.o
	$(CC) -o $@ $^ -Iinclude -Llib -ltestu01 -ltestu01probdist -ltestu01mylib -lm

$(BUILDDIR)/trngSmallCrush.o: $(SRCDIR)/trngSmallCrush.c
	$(CC) -o $@ -c $^ -mrdrnd

trngSmallCrush_ssl: $(TARGETDIR)/trngSmallCrush_ssl

$(TARGETDIR)/trngSmallCrush_ssl: $(BUILDDIR)/trngSmallCrush_ssl.o
	$(CC) -o $@ $^ -Iinclude -Llib -ltestu01 -ltestu01probdist -ltestu01mylib -lm -lcrypto

$(BUILDDIR)/trngSmallCrush_ssl.o: $(SRCDIR)/trngSmallCrush_ssl.c
	$(CC) -o $@ -c $^ -mrdrnd