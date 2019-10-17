#include "priority-queue.h"

PQ* PQCreate(int maxelem)
{
    PQ* q = malloc(sizeof(PQ));
    q->tree = BHCreate(maxelem);
    return q;
}

bool PQIsEmpty(PQ* q)
{
    if(q == NULL)
        return true;
    else
        return false;       
}

int PQGetMaxPriority(PQ* q)
{
    return BHGetMaxPriority(q->tree);
}

PQItemType PQGetMaxItem(PQ* q)
{
    return BHGetMaxItem(q->tree);
}

void PQInsert(PQ* q, PQ* node)
{
    BHInsert(q->tree, int priority, BHItemType item);
}

void PQDestroy(PQ* q)
{
    BHDestroy(q->tree);
    free(q);
}