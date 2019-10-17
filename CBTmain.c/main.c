#include <stdio.h>
#include <stdlib.h>
#include "complete-bt.h"
#include "UserFunctions.h"

int main(void)
{
    visit = print;
    CBTtree* tree = malloc(sizeof(CBTtree));
    tree = CBTCreate(1500);
    CBTInsertRoot(tree, 10);
    CBTInsertLast(tree, 9);
    CBTInsertLast(tree, 8);
    CBTInsertLast(tree, 7);
    CBTInsertLast(tree, 6);
    CBTInsertLast(tree, 5);
    CBTInsertLast(tree, 4);
    CBTInsertLast(tree, 3);
    CBTInsertLast(tree, 2);
    CBTInsertLast(tree, 1);
    CBTLevelOrder(tree, visit);
    CBTRemoveLast(tree);
    CBTLevelOrder(tree, visit);
    printf("Last node's data : %d \n",CBTGetLast(tree)->data);
    return 0;
}