#include "bstModuleTypes.h"
#include "binary-tree.h"
#include <stdbool.h>
#pragma once

typedef struct BSTnode{
    BTnode* node;
}BSTnode;

typedef struct BSTtree{
    BTtree* root;
}BSTtree;

void (*visit)(BTnode* node);
bool (*compare)(BSTItemType item1, BSTItemType item2);
BSTtree* BSTCreate(int maxelem);
void BSTInsert(BSTtree* tree, BSTItemType item, BSTkey key);
void insert(BTtree* tree, BTnode* node, BTItemType temp);
void BSTInOrder(BSTtree* tree, void *visit);
void BSTDelete(BSTtree* tree, BSTnode* node);
void BSTDestroy(BSTtree* tree);