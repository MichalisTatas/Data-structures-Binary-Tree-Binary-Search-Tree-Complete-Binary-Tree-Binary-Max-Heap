#include "complete-bt.h"
#include "queues.h"

CBTtree* CBTCreate(int maxelem)
{   
    CBTtree* temp = malloc(sizeof(CBTtree));
    temp->root = malloc(sizeof(BTtree));
    temp->root = BTCreate(maxelem);
    return temp;
}

int CBTHeight(CBTtree* tree)
{
    return BTHeight(tree->root);
}

int CBTSize(CBTtree* tree)
{
    return BTSize(tree->root);
}

CBTnode* CBTGetRoot(CBTtree* tree)
{   
    CBTnode* temp = malloc(sizeof(CBTnode));
    temp->node = BTGetRoot(tree->root);
    return temp;
}

CBTnode* CBTGetParent(CBTtree* tree, CBTnode* node)
{
    CBTnode* temp = malloc(sizeof(CBTnode));
    temp->node = BTGetParent(tree->root, node->node);
    return temp;
}

CBTnode* CBTGetChildLeft(CBTtree* tree, CBTnode* node)
{
    CBTnode* temp = malloc(sizeof(CBTnode));
    temp->node =  BTGetChildLeft(tree->root, node->node);
    return temp;
}

CBTnode* CBTGetChildRight(CBTtree* tree, CBTnode* node)
{
    CBTnode* temp = malloc(sizeof(CBTnode));
    temp->node = BTGetChildRight(tree->root, node->node);
    return temp;
}

bool CBTIsNil(CBTnode* node)
{
    return BTIsNil(node->node);
}

CBTItemType CBTGetItem(CBTtree* tree, CBTnode* node)
{
    return BTGetItem(tree->root, node->node);
}

void CBTInsertRoot(CBTtree* tree, CBTItemType item)
{
    BTInsertRoot(tree->root, item);
}

BTnode* CBTGetLast(CBTtree* tree)
{
    Queue Q;
    BTnode* temp;
    InitializeQueue(&Q);
    Insert(BTGetRoot(tree->root), &Q);
    while(!Empty(&Q))
    {
        temp = Remove(&Q);
        if(BTGetChildLeft(tree->root, temp) != NULL)
            Insert(BTGetChildLeft(tree->root, temp), &Q);
        if(BTGetChildRight(tree->root, temp) != NULL)
            Insert(BTGetChildRight(tree->root, temp), &Q);
    }
    return temp;
}

void CBTInsertLast(CBTtree* tree, CBTItemType item)
{
    Queue Q;
    InitializeQueue(&Q);
    BTnode* temp = BTGetRoot(tree->root);
    Insert(temp, &Q);
    temp  = Remove(&Q);
    while(BTGetChildLeft(tree->root, temp) != NULL && BTGetChildRight(tree->root, temp) != NULL)
    {
        if(BTGetChildLeft(tree->root, temp) != NULL)
            Insert(BTGetChildLeft(tree->root, temp), &Q);
        if(BTGetChildRight(tree->root, temp) != NULL)
            Insert(BTGetChildRight(tree->root, temp), &Q);
        temp  = Remove(&Q);
    }
    if(BTGetChildLeft(tree->root, temp) == NULL)
        BTInsertLeft(tree->root, temp, item);
    else
        BTInsertRight(tree->root, temp, item);
    
}

void CBTRemoveLast(CBTtree* tree)
{
    BTnode* temp = CBTGetLast(tree);
    BTRemove(tree->root, temp);
}

void CBTChange(CBTtree* tree, CBTnode* node, CBTItemType item)
{
    BTChange(tree->root, node->node, item);
}

void CBTPreOrder(CBTtree* tree, void(*visit)(BTnode* node))
{
    BTPreOrder(tree->root, visit);
}

void CBTInOrder(CBTtree* tree, void(*visit)(BTnode* node))
{
    BTInOrder(tree->root, visit);
}

void CBTPostOrder(CBTtree* tree, void(*visit)(BTnode* node))
{
    BTPostOrder(tree->root, visit);
}

void CBTLevelOrder(CBTtree* tree, void(*visit)(BTnode* node))
{
    BTLevelOrder(tree->root, visit);
}

void CBTDestroy(CBTtree* tree)
{
    BTDestroy(tree->root);
    free(tree);
}