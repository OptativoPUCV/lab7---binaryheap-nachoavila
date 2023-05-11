#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size == 0) return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  int pos = pq->size;
  heapElem aux;
  int padre = (pos-1)/2;
  if(pq->size == pq->capac)
  {
    pq->heapArray = realloc(pq->heapArray, pq->capac*2+1);
  }
  if(pq->size == 0)
  {
    pq->heapArray[0].data = data;
    pq->heapArray[0].priority = priority;
    pq->size++;
  }
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  pq->size++;
  while(pq->heapArray[pos].priority > pq->heapArray[padre].priority)
  {
    if(pq->heapArray[pos].priority > pq->heapArray[padre].priority)
    {
      aux = pq->heapArray[pos];
      pq->heapArray[pos] = pq->heapArray[padre];
      pq->heapArray[padre] = aux;
      pos = padre;
      padre = (pos-1)/2;
    }
  }
}


void heap_pop(Heap* pq){
  pq->heapArray[0].data = pq->heapArray[pq->size].data;
  
}

Heap* createHeap(){
  Heap * h = malloc(3 * sizeof(Heap));
  h->heapArray = malloc(3 * sizeof(Heap));
  h->size = 0;
  h->capac = 3;
  
   return h;
}
