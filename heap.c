#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"
#include <stdbool.h>

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
  if(pq->size==0) return NULL;
  if(pq->heapArray[0].data!=NULL) return pq->heapArray[0].data;
  else return NULL;
    
}

void heap_push(Heap* pq, void* data, int priority){
  if(pq->size==pq->capac){
    pq->heapArray=realloc(pq->heapArray, sizeof(heapElem)*pq->capac*2);
  }
  heapElem par;
  par.data=data;
  par.priority=priority;
  pq->heapArray[pq->size]=par;
  int posicion;
  int padre=(posicion-1)/2;
  pq->size++;
  
  while(padre>0){
    if(pq->heapArray[posicion].priority>=pq->heapArray[padre].priority){
      heapElem aux=pq->heapArray[posicion];
      pq->heapArray[posicion]=pq->heapArray[padre];
      pq->heapArray[padre]=aux;
      padre= (padre-1)/2;
      posicion = (posicion-1)/2;
    }
    else{
      break;
    }
  }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *heap=(Heap *) malloc(sizeof(Heap));
  if(heap==NULL) return NULL;
  heap->heapArray=malloc(sizeof(heapElem)*3);
  if(heap->heapArray==NULL) return NULL;
  heap->capac=3;
  heap->size=0;
  
   return heap;
}
