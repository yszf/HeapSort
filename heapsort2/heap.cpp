#include "heap.h"

//#define MINHEAP

void Swap(ELEMTYPE *a,ELEMTYPE *b)
{
	ELEMTYPE tmp = *a;
	*a = *b;
	*b = tmp;
}

void FilterDown(ELEMTYPE *ar,int pos,int end)
{
	int i = pos;
	int j = 2 * i + 1;
	ELEMTYPE tmp = ar[pos];
	while (j <= end)
	{
#ifdef MINHEAP

		if (j < end && ar[j] >= ar[j+1])
		{
			j += 1;
		}
		if (tmp <= ar[j])
		{
			break;
		}
#else
		if (j < end && ar[j] <= ar[j+1])
		{
			j += 1;
		}
		if (tmp >= ar[j])
		{
			break;
		}
#endif
		ar[i] = ar[j];
		i = j;
		j = 2 * i + 1;
	}
	ar[i] = tmp;
}

void FilterUp(ELEMTYPE *ar,int start)
{
	int i = start;
	int j = (i - 1)/2;
	ELEMTYPE tmp = ar[i];
	while(i > 0)
	{
#ifdef MINHEAP
		if (tmp >= ar[j])
		{
			break;
		}
#else
		if(tmp <= ar[j])
		{
			break;
		}
#endif
		ar[i] = ar[j];
		i = j;
		j = (i - 1)/2;
	}
	ar[i] = tmp;
}

void FilterDown2(ELEMTYPE *ar,int pos,int end,bool (*fp)(ELEMTYPE,ELEMTYPE))
{
	int i = pos;
	int j = 2 * i + 1;
	ELEMTYPE tmp = ar[pos];
	while (j <= end)
	{
		if (j < end && !fp(ar[j],ar[j+1]))
		{
			j += 1;
		}
		if (fp(tmp,ar[j]))
		{
			break;
		}

		ar[i] = ar[j];
		i = j;
		j = 2 * i + 1;
	}
	ar[i] = tmp;
}

void FilterUp2(ELEMTYPE *ar,int start,bool (*fp)(ELEMTYPE,ELEMTYPE))
{
	int i = start;
	int j = (i - 1)/2;
	ELEMTYPE tmp = ar[i];
	while(i > 0)
	{
		if (fp(ar[j],tmp))
		{
			break;
		}
		ar[i] = ar[j];
		i = j;
		j = (i - 1)/2;
	}
	ar[i] = tmp;
}
bool Init_Heap(Heap *hp)
{
	assert(NULL != hp);
	hp->cursize = 0;
	hp->totalsize = HEAP_SIZE;
	hp->data = (ELEMTYPE *)malloc(sizeof(ELEMTYPE)*hp->totalsize);
	if (hp->data == NULL)
	{
		exit(1);
	}
	return true;
}
void Destroy_Heap(Heap *hp)
{
	assert(hp != NULL);
	hp->cursize = 0;
	hp->totalsize = 0;
	free(hp->data);
	hp->data = NULL;
}
void Clear_Heap(Heap *hp)
{
	assert(hp != NULL);
	hp->cursize = 0;
}
bool Is_Full(Heap *hp)
{
	assert(hp != NULL);
	return hp->cursize == hp->totalsize;
}
bool Is_Empty(Heap *hp)
{
	assert(hp != NULL);
	return hp->cursize == 0;
}
int Size_Heap(Heap *hp)
{
	assert(hp != NULL);
	return hp->cursize;
}
void Push_Heap(Heap *hp,ELEMTYPE elem,bool (*fp)(ELEMTYPE,ELEMTYPE))
{
	assert(hp != NULL);
	if (Is_Full(hp))
	{

	}
	hp->data[hp->cursize] = elem;
	hp->cursize++;
	FilterUp2(hp->data,hp->cursize-1,fp);
}
ELEMTYPE Pop_Heap(Heap *hp)
{
	assert(hp != NULL);
	if (!Is_Empty(hp))
	{
		ELEMTYPE tmp = hp->data[0];
		Swap(&hp->data[0],&hp->data[hp->cursize-1]);
		FilterDown(hp->data,0,--hp->cursize-1);
		return tmp;
	}
	else
	{
		return -1;
	}
}
void Insert_Heap(Heap *hp,ELEMTYPE *ar,int n)
{
	assert(hp != NULL && ar != NULL && n > 0);
	if (!Is_Full(hp))
	{
		int i;
		for (i=0;i<n;++i)
		{
			hp->data[i] = ar[i];
	//		hp->data[hp->cursize] = ar[i];
	//		hp->cursize++;
	//		FilterUp(hp->data,hp->cursize-1);
		}
		hp->cursize = n;
		Make_Heap(hp);
	}
}

void Make_Heap(Heap *hp)
{
	assert(hp != NULL);
	int end = hp->cursize - 1;
	int pos = (end - 1)/2;
	while(pos >= 0)
	{
		FilterDown(hp->data,pos,end);
		--pos;
	}
}

void Heap_Sort(Heap *hp,bool (*fp)(ELEMTYPE,ELEMTYPE))
{
	assert(hp != NULL);
	int i;
	for (i = hp->cursize-1;i > 0;--i)
	{
		Swap(&hp->data[0],&hp->data[i]);
		if (i > 1)
		{
	//		FilterDown(hp->data,0,i-1);
			FilterDown2(hp->data,0,i-1,fp);
		}

	}
}

void Print_Heap(Heap *hp)
{
	assert(hp != NULL);
	int i;
	for (i = 0;i < hp->cursize;i++)
	{
		printf("%d ",hp->data[i]);
	}
	printf("\n");
}
