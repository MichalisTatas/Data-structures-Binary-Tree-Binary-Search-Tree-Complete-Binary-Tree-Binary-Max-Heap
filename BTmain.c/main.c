#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"
#include "UserFunctions.h"

int main(void)
{
    visit=myvisit;


    BTtree* tree = BTCreate(100);
    BTnode* node;
    BTInsertRoot(tree, 10);
    node = BTGetRoot(tree);
    BTInsertLeft(tree, node, 4);
    BTInsertRight(tree, node, 7);
    BTPreOrder(tree, visit);
    node = BTGetChildLeft(tree, node);
    BTInsertRight(tree, node, 14);
    BTInOrder(tree, visit);
    BTLevelOrder(tree, visit);
    BTGetItem(tree, node);
    BTChange(tree, node, 20);
    printf("right's node value has changed to %d \n", BTGetItem(tree, node));
    printf("Height of tree is : %d \n", BTHeight(tree));
    printf("Size of tree is : %d \n", BTSize(tree));
    node = BTGetChildRight(tree, node);
    BTRemove(tree, node);
    BTPostOrder(tree, visit);
    printf("Height of tree after removal is : %d \n", BTHeight(tree));
    printf("Size of tree after removal is : %d \n", BTSize(tree));
    BTDestroy(tree);
    printf("Size of tree after destruction is : %d \n", BTSize(tree));
    return 0;
}