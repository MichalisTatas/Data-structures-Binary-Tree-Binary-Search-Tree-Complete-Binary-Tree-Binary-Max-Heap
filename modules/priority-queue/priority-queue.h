#include "pqModuleTypes.h"

#ifdef PQ_IMPL_BINARY_HEAP
#include "binary-max-heap.h"
typedef struct queuenode{
    BHnode* node;
}PQnode;

typedef struct{
    Heap* tree;
    // queuenode* front;
    // queuenode* rear;
}PQ;

#else
#include "binary-search-tree.h"

typedef struct queuenode{
    BSTnode* node;
}PQnode;

typedef struct{
    BSTtree* tree;
    // queuenode* front;
    // queuenode* rear;
}PQ;

#endif

PQ* PQCreate(int maxelem);
bool PQIsEmpty(PQ* q);
void PQInsert(PQ* q, PQItemType item);
void PQDestroy(PQ* q);
int PQGetMaxPriority(PQ* q);
PQItemType PQGetMaxItem(PQ* q);
// delete