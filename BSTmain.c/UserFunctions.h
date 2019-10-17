#include "binary-search-tree.h"
#pragma once

void myvisit(BTnode* node)
{
    printf("%d  ",node->data.key);
}

bool mycompare(BSTkey item1, BSTkey item2)
{
    if(item1 >= item2)
        return true;
    else 
        return false;
}
