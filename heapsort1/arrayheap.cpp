#include <stdio.h>
#include <stdlib.h>

typedef int HeapElem;

//交换元素
void swap(HeapElem *a,HeapElem *b)
{
	HeapElem temp = *a;
	*a = *b;
	*b = temp;
}
//打印数组元素
void PrintArr(HeapElem *ar,int n)
{
	for (int i = 0;i < n;++i)
	{
		printf("%d ",ar[i]);
	}
	printf("\n");
}
//调整为最小堆
void FilterDown(HeapElem *ar,int pos,int end)//调整函数
{
	int i = pos;
	int j = 2 * i + 1;
	HeapElem tmp = ar[i];
	while (j <= end)
	{
		if (j < end && ar[j] > ar[j+1])
		{
			j += 1;
		}

		if (ar[i] > ar[j])
		{
		//	swap(&ar[i],&ar[j]);
			ar[i] = ar[j];
			i = j;
			j = i * 2 + 1;
			ar[i] = tmp;
		}
		else
		{
			break;
		}
	}
//	ar[i] = tmp;
}

//初始化生成最小堆
void MakeMinHeap(HeapElem *ar,int n)
{
	if(ar == NULL || n < 2)
	{
		return;
	}
	int end = n - 1;
	int pos = (end - 1)/2;
//	int pos = n / 2 - 1;
	while (pos >= 0)
	{
		FilterDown(ar,pos,end);
		--pos;
	}
}

//堆排序：从大到小排序
void heap_sort1(HeapElem *ar,int n)
{
	//将数组元素调整为最小堆
	MakeMinHeap(ar,n);
	int i;
	for (i=n-1;i>0;--i)//
	{
		swap(&ar[0],&ar[i]);
		if (i > 1)
		{
			FilterDown(ar,0,i-1);
		}
	}
}
//调整为最大堆
void FilterUp(HeapElem *ar,int start,int end)
{
	int i = start;
	int j = 2 * i + 1;
	HeapElem tmp = ar[i];
	while (j <= end)
	{
		if (j < end && ar[j] < ar[j+1])
		{
			j += 1;
		}
		if (ar[i] >= ar[j])
		{
			break;
		}
		ar[i] = ar[j];
	//	swap(&ar[i],&ar[j]);
		i = j;
		j = 2 * i + 1;
		ar[i] = tmp;
	}

}

//初始化生成最大堆
void MakeMaxHeap(HeapElem *ar,int n)
{
	if (ar == NULL || n < 2)
	{
		return;
	}
	int end = n - 1;
//	int pos = (end - 1)/2;
	int pos = n / 2 - 1;
	while (pos >= 0)
	{
		FilterUp(ar,pos,end);
		--pos;
	}
}
//堆排序：从小到大排序
void heap_sort2(HeapElem *ar,int n)
{
	//将数组元素调整为大顶堆
	MakeMaxHeap(ar,n);
//	PrintArr(ar,n);
	int i;
	for (i=n-1;i>0;--i)//
	{
		swap(&ar[0],&ar[i]);
		if (i > 1)
		{
			FilterUp(ar,0,i-1);
		}
	}
}

//测试函数
int main()
{
	HeapElem ar[] = {87,26,34,19,78,41,90,77,9,66};
	int len = sizeof(ar)/sizeof(ar[0]);
	PrintArr(ar,len);
//	heap_sort1(ar,len);
	heap_sort2(ar,len);
	PrintArr(ar,len);
	system("pause");//调试时在这暂停
	return 0;
}
