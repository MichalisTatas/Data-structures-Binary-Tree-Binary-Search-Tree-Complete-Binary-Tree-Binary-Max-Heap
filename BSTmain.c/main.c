#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary-search-tree.h"
#include "UserFunctions.h"

int main(void)
{
    compare = mycompare;
    visit = myvisit;
    BSTtree* tree = malloc(sizeof(BSTtree)); 
    tree = BSTCreate(40);
    BSTInsert(tree, 4, 15);
    BSTInsert(tree, 4, 4);
    BSTInsert(tree, 4, 7);
    BSTInsert(tree, 4, 12);
    BSTInsert(tree, 4, 23);
    // BSTInsert(tree, 4, 20);                                       //uncomment and comment the one below to delete node with two childs
    BSTInsert(tree, 4, 45);
    BSTInOrder(tree, visit);
    BSTnode* temp = malloc(sizeof(BSTnode));
    temp->node=BTGetChildRight(tree->root, BTGetRoot(tree->root));
    temp->node = BTGetChildRight(tree->root, temp->node);            //comment to delete node with one child
    BSTDelete(tree, temp);
    BSTInOrder(tree, visit);
    BSTDestroy(tree);
    return 0;
}