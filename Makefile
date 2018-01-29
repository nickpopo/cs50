# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow

# name for executable
EXE = speller
EXE1 = counter

# space-separated list of header files
HDRS = dictionary.h my.h

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =

# space-separated list of source files
SRCS = speller.c dictionary.c
SRCS2 = counter.c
# automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies
$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f core $(EXE) *.o
	
$(EXE1):
	$(CC) $(CFLAGS) -o $@ $(SRCS2)
	
