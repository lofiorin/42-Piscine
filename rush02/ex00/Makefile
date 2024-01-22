#Compiler flags
CFLAGS := -Wall -Wextra -Werror

#Compiled filename
OUT_NAME := bsq

#Get all *.c source files
SRCS = $(wildcard *.c)

#Get all objects files by converting source filenames from .c to .o
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#First and the default rule executed with make
#Prerequisites: rule called as value of OUT_NAME
all: re

#Rule called as value of OUT_NAME
#Prerequisites: all objects names
$(OUT_NAME): $(OBJS)
#$@ = name of the target of the rule
#$^ = names of all prerequisites
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o
fclean: clean
	rm -f $(OUT_NAME)

re: fclean $(OUT_NAME)
