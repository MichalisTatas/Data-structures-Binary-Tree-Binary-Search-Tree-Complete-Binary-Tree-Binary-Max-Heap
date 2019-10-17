#include "priority-queue.h"

PQ* PQCreate(int maxelem)
{
    PQ* q = malloc(sizeof(PQ));
    q->tree = BSTCreate(maxelem);
    q->front = malloc(sizeof(queuenode));
    q->rear = malloc(sizeof(queuenode));
    q->front = NULL;
    q->rear = NULL;
    return q;
}