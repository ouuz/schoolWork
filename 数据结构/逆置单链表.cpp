#include<stdio.h>  
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next;
}Node;

void Output(Node *head)   
{
	Node *p = head;
	while (p->next)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("%d\t\n", p->data);
}

void Reverse(Node *&head)   
{
	if (head == NULL || head->next == NULL)  
		return;
	Node *pre, *cur, *rear;
	pre = head;
	cur = head->next;
	while (cur)
	{
		rear = cur->next;
		cur->next = pre;
		pre = cur;
		cur = rear;
	}
	head->next = NULL;
	head = pre;
}
int main()
{
	Node A,B,C,D,E;
	A.data = 1;
	A.next = &B;
	
	B.data = 2;
	B.next = &C;
	
	C.data = 3;
	C.next = &D;	
		
	D.data = 4;
	D.next = &E;
	
	E.data = 5;
	E.next = NULL;	 
	
	Node *head = &A;
	printf("Ô­±íÊÇ\n");
	Output(head);
	printf("ÄæÖÃ\n");
	Reverse(head);
	Output(head);
	return 0;
} 
