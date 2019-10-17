MODULES = ../modules

CFLAGS = -g -Wall -I.

PROGRAM = ex6

OBJS = main.o

include $(MODULES)/binary-search-tree/make.inc

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)