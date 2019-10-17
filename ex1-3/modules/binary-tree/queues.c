#include <stdio.h>
#include <stdlib.h>
#include "modules.h"s
#include "queues.h"
void InitializeQueue(Queue *Q)
{
    Q->Front=NULL;
    Q->Rear=NULL;
}

int Empty(Queue *Q)
{
   return(Q->Front==NULL);
}

int Full(Queue *Q)
{
   return(0);
}
/* We assume an already constructed queue */
/* is not full since it can potentially grow */
/* as a linked structure.                   */

void Insert(ItemType R, Queue *Q)
{
   QueueNode *Temp;
   Temp=(QueueNode *)malloc(sizeof(QueueNode));
   Temp->Item = malloc(sizeof(ItemType));
   if (Temp==NULL){
      printf("System storage is exhausted");
   } else {
      Temp->Item=R;
      Temp->Link=NULL;
      if (Q->Rear==NULL){
         Q->Front=Temp;
         Q->Rear=Temp;
      } else {
         Q->Rear->Link=Temp;
         Q->Rear=Temp;
      }
   }
}


ItemType Remove(Queue *Q)
{
   QueueNode *Temp;
   ItemType temp1 = malloc(sizeof(ItemType));

   if (Q->Front==NULL){
      printf("attempt to remove item from an empty queue");
      return NULL;
   } else {
      temp1=Q->Front->Item;
      Temp=Q->Front;
      Q->Front=Temp->Link;
      // free(Temp);
      if (Q->Front==NULL) Q->Rear=NULL;
      return temp1;
   }
}
