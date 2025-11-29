/* NOTE: this is a "simple", "bare-bones" single linked list implementation of a stack. @FRS */

#include <stdio.h>
#include <stdlib.h>

struct nodeTag {
   int data;
   struct nodeTag *pNext;
};

struct nodeTag *CreateStack()
{
   return NULL;
}

struct nodeTag *CreateNode(int x)
{
  // allocate space for new node
  struct nodeTag *pTemp;
  pTemp = malloc(sizeof(struct nodeTag));
  if (pTemp != NULL) { // mem. was allocated
     pTemp->data = x;     // copy the element value x
     pTemp->pNext = NULL;
  }    
  else
     printf("ERROR: no more mem. space!\n");

  return pTemp;
}

struct nodeTag *Push(struct nodeTag *pFirst, int x)
{  
  // insert new node
  struct nodeTag *pTemp;

  pTemp = CreateNode(x);
  if (pTemp != NULL) {
     pTemp->pNext = pFirst;
     pFirst = pTemp;
  }

  return pFirst;
}

int StackEmpty(struct nodeTag *pFirst)
{
    if (pFirst == NULL) 
       return 1;
    else 
       return 0;
}

struct nodeTag *Pop(struct nodeTag *pFirst, int *elem)
{
    if (!StackEmpty(pFirst)) {
       struct nodeTag *pTemp;
       pTemp = pFirst;
       *elem = pTemp->data;

       // adjust first pointer
       pFirst = pFirst->pNext;

       // remove the original first node
       free(pTemp);
    }
    else {
       printf("UNDERFLOW ERROR!\n");
    }
           
    return pFirst;
}

int main() 
{
   struct nodeTag *pFirst;
   int x;

   pFirst = CreateStack();

   pFirst = Push(pFirst, 10);
   pFirst = Push(pFirst, 20);
  
   pFirst = Pop(pFirst, &x);
   printf("x = %d\n", x);

   pFirst = Pop(pFirst, &x);
   printf("x = %d\n", x);

   pFirst = Pop(pFirst, &x);
   printf("x = %d\n", x);

   return 0;
}
