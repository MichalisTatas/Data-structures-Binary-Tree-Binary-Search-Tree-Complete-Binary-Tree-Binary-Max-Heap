#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "btModuleTypes.h"
#pragma once

#ifdef BT_IMPL_POINTERS
typedef struct BTnode
{
    BTItemType data;
    struct BTnode* parent;
    struct BTnode* left;
    struct BTnode* right;
}BTnode;

typedef struct BTtree
{
    struct BTnode* root;
}BTtree;

#else
typedef struct BTnode
{
    BTItemType data;
    int position;
}BTnode;

typedef struct BTtree
{
    int arraySize;
    struct BTnode** root;
}BTtree;

#endif

void (*visit)(BTnode* node);
void print(BTnode* node);
BTtree* BTCreate(int maxelem);
int Height(BTnode* node,BTtree* tree);
int BTHeight(BTtree* tree);
int Size(BTnode* node, BTtree* tree);
int BTSize(BTtree* tree);
BTnode* BTGetRoot(BTtree* tree);
BTnode* BTGetParent(BTtree* tree, BTnode* node);
BTnode* BTGetChildLeft(BTtree* tree, BTnode* node);
BTnode* BTGetChildRight(BTtree* tree, BTnode* node);
bool BTIsNil(BTnode* node);
BTItemType BTGetItem(BTtree* tree, BTnode* node);
void BTInsertRoot(BTtree* tree, BTItemType item);
void BTInsertLeft(BTtree* tree, BTnode* node, BTItemType item);
void BTInsertRight(BTtree* tree, BTnode* node, BTItemType item);
void BTRemove(BTtree* tree, BTnode* node);
void BTChange(BTtree* tree, BTnode* node, BTItemType item);
void preorder(BTnode* node,BTtree* tree, void (*visit)(BTnode* node));
void BTPreOrder(BTtree* tree, void (*visit)(BTnode* node));
void inorder(BTnode* node, BTtree* tree, void (*visit)(BTnode* node));
void BTInOrder(BTtree* tree, void (*visit)(BTnode* node));
void postorder(BTnode* node, BTtree* tree, void (*visit)(BTnode* node));
void BTPostOrder(BTtree* tree, void (*visit)(BTnode* node));
void BTLevelOrder(BTtree* tree, void (*visit)(BTnode* node));
void destroy(BTnode* node, BTtree* tree);
void BTDestroy(BTtree* tree);  //8elei orisdma to tree h oxi?
