MODULES =../modules

CFLAGS = -g -Wall -I.

PROGRAM = ex7

OBJS = main.o

include $(MODULES)/priority-queue/make.inc

$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)