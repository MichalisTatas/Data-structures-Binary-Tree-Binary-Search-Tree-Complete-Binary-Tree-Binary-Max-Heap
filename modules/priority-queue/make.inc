CFLAGS += -I$(MODULES)/priority-queue

ifeq ($(PQ_IMPL), bh)
    include $(MODULES)/binary-max-heap/make.inc
    CFLAGS += -DPQ_IMPL_BINARY_HEAP
    OBJS += $(MODULES)/priority-queue/moduleBinaryHeap.o
else
    include $(MODULES)/binary-search-tree/make.inc
    CFLAGS += -DPQ_IMPL_BINARY_SEARCH_TREE
    OBJS += $(MODULES)/priority-queue/moduleBinarySearchTree.o
endif