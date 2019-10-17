CFLAGS += -I$(MODULES)/binary-tree

OBJS += $(MODULES)/binary-tree/queues.o

ifeq ($(BT_IMPL),pointers)
    CFLAGS += -DBT_IMPL_POINTERS
    OBJS += $(MODULES)/binary-tree/modulePointers.o
else
    CFLAGS += -DBT_IMPL_ARRAY
    OBJS += $(MODULES)/binary-tree/moduleArray.o
endif