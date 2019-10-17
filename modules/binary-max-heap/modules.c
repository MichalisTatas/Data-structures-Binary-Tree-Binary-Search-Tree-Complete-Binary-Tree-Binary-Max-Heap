#include "binary-max-heap.h"
#include "complete-bt.h"
#include "queues.h"
#include "bhModuleTypes.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void swap(BTnode* item1, BTnode* item2)
{
    BTnode* temp = malloc(sizeof(BTnode));
    temp->data = item1->data;
    item1->data = item2->data;
    item2->data = temp->data; 
}

Heap* BHCreate(int maxelem)
{
    Heap* heap = malloc(sizeof(Heap));
    heap->Count = 0;
    heap->tree = malloc(sizeof(CBTtree));
    heap->tree = CBTCreate(maxelem);
    return heap;
}

bool BHIsEmpty(Heap* heap)
{
    if(heap->Count == 0)
        return true;
    else
        return false;
}

int BHGetMaxPriority(Heap* heap)
{
    return CBTGetRoot(heap->tree)->node->data.priority;
}

BHItemType BHGetMaxItem(Heap* heap)
{
    Queue Q;
    InitializeQueue(&Q);
    BTnode* temp;
    BHItemType max = BTGetRoot(heap->tree->root)->data.item;
    Insert(BTGetRoot(heap->tree->root), &Q);
    while(!Empty(&Q))
    {   
        // printf("FGD   ");
        temp = Remove(&Q);
        if(temp->data.item > max)
            max = temp->data.item;
        if(BTGetChildLeft(heap->tree->root, temp) != NULL)
            Insert(BTGetChildLeft(heap->tree->root, temp), &Q);
        if(BTGetChildRight(heap->tree->root, temp) != NULL)
            Insert(BTGetChildRight(heap->tree->root, temp), &Q);
    }
    return max;
}

void BHRemove(Heap* heap)
{
    swap(CBTGetRoot(heap->tree)->node, CBTGetLast(heap->tree));
    CBTRemoveLast(heap->tree);
    heapify_down(heap->tree->root, BTGetRoot(heap->tree->root));
}

void heapify_up(BTtree* tree, BTnode* node)
{
    if(BTGetParent(tree, node)==NULL)
        return;
    if(BTGetParent(tree, node)->data.priority < node->data.priority)
        swap(BTGetParent(tree, node), node);
    heapify_up(tree, BTGetParent(tree,node));   
}

void BHInsert(Heap* heap, int priority, BHItemType item)
{
    CBTItemType temp;
    temp.priority = priority;
    temp.item = item;
    CBTInsertLast(heap->tree, temp);
    heapify_up(heap->tree->root, CBTGetLast(heap->tree));
}

void help(BTtree* tree, BTnode* node)
{   
    
    if(BTGetChildLeft(tree, node)!=NULL && BTGetChildRight(tree, node)!=NULL)
    {
        if(BTGetChildLeft(tree, node)->data.priority > BTGetChildRight(tree, node)->data.priority)
        {
            if(node->data.priority < BTGetChildLeft(tree, node)->data.priority)
                swap(node, BTGetChildLeft(tree, node));
        }
        else if(node->data.priority < BTGetChildRight(tree, node)->data.priority)
                swap(node, BTGetChildRight(tree, node));
    }
    if(BTGetChildLeft(tree, node)!=NULL && BTGetChildRight(tree, node)==NULL)
    {
        if(node->data.priority < BTGetChildLeft(tree, node)->data.priority)
        {
            swap(BTGetChildLeft(tree, node), node);
        }   
    }
    if(BTGetChildRight(tree, node)!=NULL && BTGetChildLeft(tree, node)==NULL)
    {
        if(node->data.priority < BTGetChildRight(tree, node)->data.priority)
        {
            swap(BTGetChildRight(tree, node), node);
        }   
    }  
}

void heapify_down(BTtree* tree, BTnode* node)
{
    if(node==NULL)
        return; 
    heapify_down(tree, BTGetChildLeft(tree, node));
    heapify_down(tree, BTGetChildRight(tree, node));
    help(tree, node);
}

Heap* BHHeapify(int n ,int* priorities, BHItemType* items)
{
    Heap* heap = BHCreate(13);
    CBTItemType temp;
    temp.priority = *priorities;
    temp.item = *items;
    CBTInsertRoot(heap->tree, temp);
    heap->Count++;
    for(int i=1; i<n; i++)
    {
        temp.priority = *(priorities+i);
        temp.item = *(items+i);
        CBTInsertLast(heap->tree, temp);
        heap->Count++; 
    }
    visit = print1;
    heapify_down(heap->tree->root, BTGetRoot(heap->tree->root));
    return heap;
}

void BHDestroy(Heap* heap)
{
    CBTDestroy(heap->tree);
    free(heap);
}

Heap* BHNaiveHeapify(int n ,int* priorities, BHItemType* items)
{
    Heap* heap = BHCreate(13);
    CBTItemType temp;
    temp.priority = *priorities;
    temp.item = *items;
    CBTInsertRoot(heap->tree, temp);
    heap->Count++;
    for(int i=1; i<n; i++)
    {
        temp.priority = *(priorities+i);
        temp.item = *(items+i);
        BHInsert(heap, temp.priority, temp.item);   
        heap->Count++; 
    }
    return heap;
}

void BHrand(int n ,int* priorities, BHItemType* items)
{
    int temppr;
    BHItemType tempit;
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        int temp = rand()%n;
        temppr = *(priorities+temp);
        *(priorities+i) = *(priorities+temp);
        *(priorities+temp) = temppr;
        tempit = *(items+temp);
        *(items+i) = *(items+temp);
        *(items+temp) = tempit;        
    }
}

Heap* BHNaiveHeapifyRnd(int n ,int* priorities, BHItemType* items)
{
    Heap* heap = BHCreate(13);
    CBTItemType temp;
    temp.priority = *priorities;
    temp.item = *items;
    CBTInsertRoot(heap->tree, temp);
    heap->Count++;
    BHrand(n ,priorities, items);
    for(int i=1; i<n; i++)
    {
        temp.priority = *(priorities+i);
        temp.item = *(items+i);
        BHInsert(heap, temp.priority, temp.item);   
        heap->Count++; 
    }
    return heap;
}