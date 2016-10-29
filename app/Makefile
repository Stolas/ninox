src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lncurses -llua -Wall -lpthread

# gpio:
# 	WITH_GPIO = -DWITH_GPIO
#
# rpm:

ninox: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS) $(WITH_GPIO)

.PHONY: clean
clean:
	rm -rf $(obj) ninox
