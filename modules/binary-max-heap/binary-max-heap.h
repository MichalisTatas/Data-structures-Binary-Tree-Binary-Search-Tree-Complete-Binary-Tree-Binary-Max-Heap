#include "bhModuleTypes.h"
#include "complete-bt.h"
#include "stdbool.h"
#pragma once

typedef struct Heap
{
    int Count;
    CBTtree* tree;
}Heap;

void (*compare)(BHItemType item1, BHItemType item2);
Heap* BHCreate(int maxelem);
bool BHIsEmpty(Heap* heap);
int BHGetMaxPriority(Heap* heap);
BHItemType BHGetMaxItem(Heap* heap);
void BHRemove(Heap* heap);
void BHInsert(Heap* heap, int priority, BHItemType item);
Heap* heapify(Heap* heap);
Heap* BHHeapify(int n ,int* priorities, BHItemType* items);
void BHDestroy(Heap* heap);
void print1(BTnode* node);
void help(BTtree* tree, BTnode* node);
void heapify_down(BTtree* tree, BTnode* node);
void heapify_up(BTtree* tree, BTnode* node);
void swap(BTnode* item1, BTnode* item2);
//exercise 8 below
Heap* BHNaiveHeapify(int n ,int* priorities, BHItemType* items);
Heap* BHNaiveHeapifyRnd(int n ,int* priorities, BHItemType* items);