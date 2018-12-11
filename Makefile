
CC = gcc
OBJS = main.o utils.o
EXEC = prog
COMP_FLAG = -std=c99 -Wall -Werror

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c utils.o
	$(CC) -c $(COMP_FLAG) $*.c

utils.o: utils.c

clean:
	rm -f $(OBJS) $(EXEC)