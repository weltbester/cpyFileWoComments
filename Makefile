CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall -Wwrite-strings -O3
DBGFLAGS = -std=gnu99 -pedantic -Wall -Wwrite-strings -ggdb3 -DDEBUG
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))
DBGOBJS=$(patsubst %.c,%.dbg.o,$(SRCS))
.PHONY: clean depend all
all: cpyFileWoComments cpyFileWoComments-debug
cpyFileWoComments: $(OBJS)
	   gcc -o $@ -O3 $(OBJS)
cpyFileWoComments-debug: $(DBGOBJS)
		 gcc -o $@ -ggdb3 $(DBGOBJS)
%.dbg.o: %.c
	 gcc $(DBGFLAGS) -c -o $@ $<
clean:
	rm -f cpyFileWoComments cpyFileWoComments-debug *.o *.c~ *.h~
depend:
	makedepend $(SRCS)
	makedepend -a -o .dbg.o  $(SRCS)
# DO NOT DELETE
anotherFile.o: anotherHeader.h someHeader.h
oneFile.o: oneHeader.h someHeader.h
