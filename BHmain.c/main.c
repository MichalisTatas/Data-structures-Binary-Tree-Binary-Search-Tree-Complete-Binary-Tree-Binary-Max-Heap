#include "binary-max-heap.h"
#include "stdio.h"
#include "UserFunctions.h"

int main(void)
{
    int priorities[]={2,3,5,4,2,1};
    BHItemType items[]={4,5,40,23,60,10}; 
    Heap* heap = BHHeapify(6,priorities,items);
    visit=print1;
    CBTLevelOrder(heap->tree, visit);
    CBTPreOrder(heap->tree, visit);
    printf("Max priority is : %d \n",BHGetMaxPriority(heap));
    printf("Max item is : %d \n",BHGetMaxItem(heap));
    BHRemove(heap);
    CBTLevelOrder(heap->tree, visit);
    BHInsert(heap, 888, 333);
    CBTLevelOrder(heap->tree, visit);
    printf("Max priority is : %d \n",BHGetMaxPriority(heap));
    BHDestroy(heap);
    return 0;
}
