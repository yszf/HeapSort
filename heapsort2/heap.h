#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define HEAP_SIZE 100
typedef int ELEMTYPE;
typedef struct
{
	ELEMTYPE * data;
	int cursize;
	int totalsize;
}Heap;

bool Init_Heap(Heap *hp);
void Destroy_Heap(Heap *hp);
void Clear_Heap(Heap *hp);
bool Is_Full(Heap *hp);
bool Is_Empty(Heap *hp);
int Size_Heap(Heap *hp);
void Push_Heap(Heap *hp,ELEMTYPE elem,bool (*fp)(ELEMTYPE,ELEMTYPE));
void Insert_Heap(Heap *hp,ELEMTYPE *ar,int n);
void Make_Heap(Heap *hp);
void Heap_Sort(Heap *hp,bool (*fp)(ELEMTYPE,ELEMTYPE));
void Print_Heap(Heap *hp);

#endif
