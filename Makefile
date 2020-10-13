VPATH=src
SOURCES = \
	bonus.c \
	common.c \
	game.c \
	gamestate.c \
	intro.c \
	main.c \
	pit.c \
	score.c \
	ship.c

PROGRAM = petfall
D64_NAME= $(PROGRAM).d64

C1541   = c1541
CC      = cl65
CC65_TARGET = pet
CFLAGS  = -t $(CC65_TARGET) -O
LDFLAGS = -t $(CC65_TARGET) -m $(PROGRAM).map

.SUFFIXES:
.PHONY: all clean full
all: $(PROGRAM)
full: $(PROGRAM).d64

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(PROGRAM): $(SOURCES:.c=.o)
	$(CC) $(LDFLAGS) -o $@ $^

$(D64_NAME): $(PROGRAM)
	$(RM) $@
	$(C1541) \
		-format "$(PROGRAM),42" d64 $@ \
		-write $(PROGRAM)

clean:
	$(RM) *.o *.map $(PROGRAM) *.d64
