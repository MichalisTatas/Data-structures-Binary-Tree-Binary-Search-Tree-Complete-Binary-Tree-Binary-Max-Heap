CFLAGS += -I$(MODULES)/complete-binary-tree

OBJS += $(MODULES)/complete-binary-tree/module.o

include $(MODULES)/binary-tree/make.inc
