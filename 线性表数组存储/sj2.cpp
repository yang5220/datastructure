// sj2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<malloc.h>
#define MAXSIZE 10
typedef int ElementType;
typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE];
	int Last;  //Last==n-1
};

List MakeEmpty() {
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;
	return PtrL;
}

int Find(ElementType x, List PtrL) {
	printf("查找");
	int i = 0;
	while (i <= PtrL->Last&&PtrL->Data[i] != x) {
		i++;
	}
	if (i > PtrL->Last) {
		return -1;
	}
	else {
		return (i+1);
	}
}

void Insert(ElementType x, int i, List PtrL) {
	printf("插入");
	if (PtrL->Last == MAXSIZE - 1)
		printf("表满");
	if (i<1 || i> PtrL->Last+2)
		printf("插入位置不合法");
	int j;
	for (j = PtrL->Last; j >= i - 1; j--) {
		PtrL[j + 1] = PtrL[j];
	}
	PtrL->Data[i - 1] = x;
	PtrL->Last += 1;
}

void Delete(int i, List PtrL) {
	printf("删除");
	if (i<1 || i>PtrL->Last + 1) {
		printf("不存在第%d个元素", i);
	}
	int j;
	for (j = i; j <= PtrL->Last; j++)
		PtrL->Data[j - 1] = PtrL->Data[j];
	PtrL->Last -= 1;
}

void print(List PtrL) {
	int i;
	printf("输出列表为：");
	for (i = 0; i < PtrL->Last + 1; i++)
		printf("%d   ", PtrL->Data[i]);
	printf("\n");
}


int main()
{
	int i;
	List P = MakeEmpty();
	for (i = 0; i < MAXSIZE - 3; i++)
		Insert(i, i + 1, P);
	print(P);
	printf("Last=%d  P->Data[0]=%d", P->Last, P->Data[0]);

	ElementType x = 9;
	int add = Find(x, P);
	if (add != -1)
		printf("%d的位置是%d\n", x, add);
	else printf("查找失败，%d不在列表中\n", x);

	ElementType k = 19;
	Insert(k, P->Last+2, P);
	print(P);

	Delete(6, P);
	print(P);


    return 0;
}

