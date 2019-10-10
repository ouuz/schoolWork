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
void Sort(headerList *L);

int main(){
	headerList list;
	int  element, delIndex, elementLength, findIndex, findElement;
	
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
	
	printf("qqqqq");
	Sort(&list);
	Output(list);
	printf("\n��Ҫ���ҵ��ǵڼ���Ԫ�أ������������±꣺");
	scanf("%d", &findIndex);
	Find(list,findIndex, &findElement);
	printf("\n���ҳɹ�������ҵ�Ԫ��Ϊ��%d", findElement);
	
	printf("\n��Ҫɾ�����ǵڼ���Ԫ�أ������������±꣺");
	scanf("%d", &delIndex);
	Delete(&list,delIndex);
	printf("\nɾ���ɹ������ڵ��б�ͷ�ĵ�����Ϊ��");
	Output(list);
	
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

void Sort(headerList *L){
	node *p = L -> head -> link , *q = NULL;
	
	if(L -> head -> link == NULL || L -> head -> link -> link == NULL)
	return ;
	
	while(q != L -> head -> link -> link) {
		for(p = L -> head; p -> link -> link != q; p = p -> link)
		{
			if(p -> link -> element > p -> link -> link -> element)
			{
				p -> link = p -> link -> link;
				p -> link -> link = p -> link -> link -> link;
				p -> link -> link -> link = p -> link;
			}
		}
		q = p -> link;
	}

}
