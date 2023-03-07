CC := gcc

CFLAGS := -g

SUBDIRS := structTest sixteenBit PID

.PHONY: $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	@[ -d bin ] || mkdir bin
	$(CC) $(CFLAGS) $@/main.c -o bin/$@
