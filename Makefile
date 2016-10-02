src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lncurses -llua -Wall

ninox: $(obj)
		$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
	clean:
		rm -rf $(obj) ninox
