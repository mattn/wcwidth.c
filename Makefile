
AR ?= ar
CC ?= gcc
PREFIX ?= /usr/local
CFLAGS = -std=c99 -Wall -Wextra -U__STRICT_ANSI__

SRC = wcwidth.c
HEADERS = wcwidth.h
OBJS = $(SRC:.c=.o)


all: clean test libwcwidth.a

libwcwidth.a: $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

test: test.o $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)
	@./$@

clean:
	rm -f test $(OBJS)

install: libwcwidth.a
	cp -f libwcwidth.a $(PREFIX)/lib/libwcwidth.a
	cp -f src/wcwidth.h $(PREFIX)/include/wcwidth.h

uninstall:
	rm -f $(PREFIX)/lib/libwcwidth.a
	rm -f $(PREFIX)/include/wcwidth.h

.PHONY: test clean include uninstall
