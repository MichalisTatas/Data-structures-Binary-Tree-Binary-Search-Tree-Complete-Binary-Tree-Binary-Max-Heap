#include "binary-search-tree.h"
#include <stdbool.h>
#include "stdlib.h"

BSTtree* BSTCreate(int maxelem)
{
    BSTtree* tree = malloc(sizeof(BSTtree));
    tree->root = BTCreate(maxelem);
    return tree;
}

void insert(BTtree* tree, BTnode* node, BTItemType temp)
{
    if(node == NULL)
        BTInsertRoot(tree, temp);
    BTnode* temp1 = malloc(sizeof(BTnode));
    while(node != NULL)
    {  
        temp1 = node;
        if(compare(temp.key, temp1->data.key))
            node = BTGetChildRight(tree, node);
        else
            node = BTGetChildLeft(tree, node); 
    }
    if(compare(temp.key, temp1->data.key))
        BTInsertRight(tree, temp1, temp);
    else
        BTInsertLeft(tree, temp1, temp);
}



void BSTInsert(BSTtree* tree, BSTItemType item, BSTkey key)
{
    BTItemType temp;
    temp.item = item;
    temp.key = key;
    insert(tree->root, BTGetRoot(tree->root), temp);
}

void BSTInOrder(BSTtree* tree, void *visit)
{
    BTInOrder(tree->root, visit);
}

void mike(BTtree* tree, BTnode* root, BSTkey key)
{
    if(!BTGetChildRight(tree, root))
    {
        key = root->data.key;
        BTnode* oldroot = root;
        root = BTGetChildLeft(tree, root);
        free(oldroot);
    }
    else
    {
        mike(tree, BTGetChildRight(tree, root), key);
    }
    
}

void BSTDelete(BSTtree* tree,BSTnode* node)
{
    BTRemove(tree->root, node->node);
}

void BSTDestroy(BSTtree* tree)
{
    BTDestroy(tree->root);
    free(tree);
}