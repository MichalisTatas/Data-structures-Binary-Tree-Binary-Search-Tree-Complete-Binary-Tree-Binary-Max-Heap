#include "cbtModuleTypes.h"
#include "binary-tree.h"
#include <stdio.h>
#include <stdbool.h>
#pragma once

typedef struct CBTnode{
    BTnode* node;
}CBTnode;

typedef struct CBTtree{
    BTtree* root;
}CBTtree;


CBTtree* CBTCreate(int maxelem);
int CHeight(CBTnode* node,CBTtree* tree);
int CBTHeight(CBTtree* tree);
int CSize(CBTnode* node, CBTtree* tree);
int CBTSize(CBTtree* tree);
CBTnode* CBTGetRoot(CBTtree* tree);
CBTnode* CBTGetParent(CBTtree* tree, CBTnode* node);
CBTnode* CBTGetChildLeft(CBTtree* tree, CBTnode* node);
CBTnode* CBTGetChildRight(CBTtree* tree, CBTnode* node);
bool CBTIsNil(CBTnode* node);
CBTItemType CBTGetItem(CBTtree* tree, CBTnode* node);
void CBTInsertRoot(CBTtree* tree, CBTItemType item);
void CBTRemove(CBTtree* tree, CBTnode* node);
void CBTChange(CBTtree* tree, CBTnode* node, CBTItemType item);
void CBTPreOrder(CBTtree* tree, void(*visit)(BTnode* node));
void CBTInOrder(CBTtree* tree, void(*visit)(BTnode* node));
void CBTPostOrder(CBTtree* tree, void(*visit)(BTnode* node));
void CBTLevelOrder(CBTtree* tree, void(*visit)(BTnode* node));
void Cdestroy(CBTnode* node, CBTtree* tree);
void CBTDestroy(CBTtree* tree);  //8elei orisdma to tree h oxi?
BTnode* CBTGetLast(CBTtree* tree);
void CBTInsertLast(CBTtree* tree, CBTItemType item);
void CBTRemoveLast(CBTtree* tree);