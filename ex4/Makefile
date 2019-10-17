MODULES = ../modules

CFLAGS = -g -Wall -I.

PROGRAM = ex4

OBJS = main.o

include $(MODULES)/complete-binary-tree/make.inc

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)