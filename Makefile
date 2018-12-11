
CC = gcc
OBJS = main.o utils.o string_utils.o
EXEC = prog
COMP_FLAG = -std=c99 -Wall -Werror

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c utils.o
	$(CC) -c $(COMP_FLAG) $*.c

utils.o: utils.c string_utils.o

string_utils.o: string_utils.o

clean:
	rm -f $(OBJS) $(EXEC)