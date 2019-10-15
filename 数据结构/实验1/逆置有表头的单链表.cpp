#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define SUCCESS 1
typedef int ElemType;
typedef struct node{
	ElemType element;
	struct node *link;
}node;

typedef struct{
	struct node *head;
	int n;
}headerList;

int Init(headerList *L); 
int Find(headerList L, int i, ElemType *x);
int Insert(headerList *L, int i, ElemType x);
int Delete(headerList *L, int i);
int Output(headerList L);
int Destory(headerList *L);
int Reverse(headerList *L);

int main(){
	headerList list;
	int  element, delIndex, elementLength, findIndex, findElement, result;
	Init(&list);
	printf("��������Ҫ�����Ԫ�ظ�����");
	scanf("%d",&elementLength);
	printf("������������Ҫ�����Ԫ�أ�\n"); 
	for(int i = 0;i < elementLength; i++){
		scanf("%d", &element);
		Insert( &list, i - 1, element );
	}
	printf("\n���б�ͷ�ĵ��������ɹ������ڵ��б�ͷ�ĵ�����Ϊ��");
	Output(list);

	printf("\n���Ƿ�Ҫ�������ã���������1����������0\n");
	scanf("%d", &result);
	if(result == 1){
		Reverse(&list);
		printf("\n���óɹ������ڵ��б�ͷ�ĵ�����Ϊ��");
		Output(list);
	}

	Destory(&list);
	return SUCCESS;
}
int Init(headerList *L){
	L -> head = (node*)malloc(sizeof(node)); 
	L -> head -> link = NULL;
	L -> n = 0;
	return SUCCESS;
}

int Find(headerList L, int i, ElemType *x){
	node *p = L.head -> link;
	if( i > L.n -1 || i < 0 )
	return ERROR;
	for(int j = 0; j < i; j++)
	p = p -> link;
	*x = p -> element;
	return *x;
}

int Insert(headerList *L, int i, ElemType x){
	node *p = L -> head, *q = (node*)malloc(sizeof(node)); 
	if( i > L -> n -1 || i < -1 )
	return ERROR;
	for(int j = 0; j <= i; j++)
	p = p -> link;
	q -> link = p -> link;
	p -> link = q;
	q -> element = x;
	L -> n++;
	return SUCCESS;
}

int Delete(headerList *L, int i){
	node *p = L -> head, *q;
	if( i > L -> n -1 || i < 0 )
	return ERROR;
	for(int j = 0; j < i; j++)
	p = p -> link;
	q = p -> link;
	p -> link = q -> link;
	free(q);
	L -> n--;
	return SUCCESS;  
}

int Output(headerList L){
	node *p = L.head -> link;
	if(!L.n)
	return ERROR;
	while(p){
		printf("%d  ",p -> element);
		p = p -> link;
	}
	return SUCCESS;
}

int Destory(headerList *L){
	node *p = L -> head;
	while(L -> head){
		p = L -> head -> link;
		free(L -> head);
		L -> head = p;
	}
}

int Reverse(headerList *L)   
{
	node *pre, *cur, *rear;
	pre = L -> head -> link;
	cur = L -> head -> link -> link;
	while (cur)
	{
		rear = cur->link;
		cur->link = pre;
		pre = cur;
		cur = rear;
	}
	L -> head -> link -> link = NULL;
	L -> head -> link = pre;
}
