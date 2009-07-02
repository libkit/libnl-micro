prefix=/usr/local

UNAME=$(shell uname)
CC=gcc
AR=ar
WFLAGS=-Wall
CFLAGS=-O2
INCLUDES:=-Iinclude
LIBNAME=libnl-micro.a

all: $(LIBNAME)

%.o: %.c
	$(CC) $(WFLAGS) -c -o $@ $(INCLUDES) $(CFLAGS) $<

LIBNL_OBJ=attr.o msg.o

$(LIBNAME): $(LIBNL_OBJ)
	rm -f $@
	$(AR) rcu $@ $^

install:
	install -d -m 0755 $(prefix)/include/libnl-micro
	cp include/*.h $(prefix)/include/libnl-micro/
	install -d -m 0755 $(prefix)/include/libnl-micro/netlink
	cp include/netlink/*.h $(prefix)/include/libnl-micro/netlink/
	install -d -m 0755 $(prefix)/include/libnl-micro/linux
	cp include/linux/*.h $(prefix)/include/libnl-micro/linux/
	install -d -m 0755 $(prefix)/lib
	cp $(LIBNAME) /usr/local/lib

clean:
	rm -f *.o *.a
