MODULES = ../modules

CFLAGS = -g -Wall -I.

PROGRAM = ex5

OBJS = main.o

include $(MODULES)/binary-max-heap/make.inc

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)