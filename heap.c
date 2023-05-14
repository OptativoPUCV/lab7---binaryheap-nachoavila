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
  if(pq->size >= pq->capac)
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

  int pos = 0;
  if(pq->size == 0) return;

  pq->heapArray[0] = pq->heapArray[pq->size-1];
  pq->size--;

  while(1){
    int hijoIzq = 2*pos+1;
    int hijoDer = 2*pos+2;

    if(hijoIzq >= pq->size && hijoDer >= pq->size) break;
    
    int hijoMayor = hijoIzq;
    
    if(hijoDer < pq->size && pq->heapArray[hijoDer].priority > pq->heapArray[hijoIzq].priority){
      hijoMayor = hijoDer;
    }
    
    heapElem aux;
    
    if(pq->heapArray[hijoMayor].priority > pq->heapArray[pos].priority){
      aux = pq->heapArray[hijoMayor];
      pq->heapArray[hijoMayor] = pq->heapArray[pos];
      pq->heapArray[pos] = aux;
      pos = hijoMayor;
    }
    else break;
  }
}

Heap* createHeap(){
  Heap * h = malloc(3 * sizeof(Heap));
  h->heapArray = malloc(3 * sizeof(Heap));
  h->size = 0;
  h->capac = 3;
  
   return h;
}
