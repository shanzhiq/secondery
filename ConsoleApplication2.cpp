#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
struct LNode
{
	int a;
	struct LNode *next;
};

struct LNode *listreset(struct LNode *head)
{
	struct LNode *p1, *p2, *p3;
	p1 = head;
	p2 = p1->next;
	p1->next = NULL;
	p3 = p2->next;
	while (p3->next != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;

	}
	p2->next = p1;
	p3->next = p2;
	return p3;
}

int main()
{
	struct LNode *p1, *p2, *head;
	p1 = (struct LNode *)malloc(sizeof(struct LNode));
	head = p1;
	scanf_s("%d", &p1->a);
	while (p1->a != 0)
	{
		p2 = (struct LNode *)malloc(sizeof(struct LNode));
		p1->next = p2;
		p1 = p2;
		scanf_s("%d", &p1->a);
	}
	p1->next = NULL;
	p1 = head;
	while (p1)
	{
		printf("%d ", p1->a);
		p1 = p1->next;
	}
	printf("\n");
	p1=listreset(head);
	while (p1)
	{
		printf("%d ", p1->a);
		p1 = p1->next;
	}
	return 0;
}

