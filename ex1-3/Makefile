 MODULES = ../modules

 CFLAGS = -g -Wall -I.

 PROGRAM = ex1-3

 OBJS = main.o

 include $(MODULES)/binary-tree/make.inc

 $(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)