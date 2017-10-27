#include "heap.h"

bool greater_equ(ELEMTYPE a,ELEMTYPE b)
{
	return a >= b;
}

bool less_equ(ELEMTYPE a,ELEMTYPE b)
{
	return a <= b;
}

int main()
{
	Heap hp;
	Init_Heap(&hp);
	ELEMTYPE ar[] = {87,26,34,19,78,41,90,77,9,66};
	int n = sizeof(ar)/sizeof(ar[0]);
	for (int i = 0;i < n;++i)
	{
	//	Push_Heap(&hp,ar[i],greater_equ);
		Push_Heap(&hp,ar[i],less_equ);
	}

//	Insert_Heap(&hp,ar,n);
	Print_Heap(&hp);
	Heap_Sort(&hp,less_equ);
	Print_Heap(&hp);
	system("pause");
	return 0;
}
