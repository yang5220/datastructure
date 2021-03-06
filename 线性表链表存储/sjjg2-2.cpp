// sjjg2-2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<malloc.h>

typedef int ElementType;
typedef struct LNode* List;
struct LNode {
	ElementType Data;
	List Next;
};

int Length(List PtrL) {
	List p = PtrL;
	int count = 0;
	while (p) {
		count++;
		p = p->Next;
	}
	return count;
}

List FindKth(int K, List PtrL) {//按序查找
	List p = PtrL;
	int i = 1;
	while (i < K&&p != NULL) {
		p = p->Next;
		i++;
	}
	if (i == K)
		return p;
	else return NULL;
}

List Find(ElementType x, List PtrL) {
	List p = PtrL;
	while (p->Data != x&&p != NULL) {
		p = p->Next;
	}
	return p;
}

List Insert(ElementType x, int i, List PtrL) {
	List p, s;
	if (i == 1) {
		s = (List)malloc(sizeof(struct LNode));
		s->Data = x;
		s->Next = PtrL;
		return s;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL) {
		printf("插入位置错误,返回原链表");
		return PtrL;
	}
	else {
		s = (List)malloc(sizeof(struct LNode));
		s->Data = x;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;
	}
}

List Delete(int i, List PtrL) {
	List p, s;
	if (i == 1) {
		s = PtrL;
		if (PtrL != NULL)
			PtrL = PtrL->Next;
		else return NULL;
		free(s);
		return PtrL;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL || p->Next == NULL) {
		printf("第%d个节点不存在,返回原链表", i);
		return PtrL;
	}
	else {
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	}
}

void print(List PtrL) {
	printf("列表输出为：");
	List p = PtrL;
	while (p) {
		printf("%d  ", p->Data);
		p = p->Next;
	}
	printf("\n");
	return;
}


int main()
{
	List P = (List)malloc(sizeof(struct LNode));
	P = NULL;
	for (int i = 0; i < 5; i++) {
		P=Insert(i, i + 1, P);
	}
	print(P);

	ElementType x = 9;
	P = Insert(x, 4, P);
	print(P);

	int add = 5;
	List s = FindKth(add, P);
	if (s != NULL);
	printf("第%d个位置上的元素是：%d\n", add, s->Data);

	int value = 3;
	List f = Find(value, P);
	if (f != NULL)
		printf("元素%d在链表中\n", value);

	
	P = Delete(3, P);
	print(P);

	int len = Length(P);
	printf("链表长度为%d\n", len);
    return 0;
}

