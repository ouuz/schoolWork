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
	printf("请输入你要输入的元素个数：");
	scanf("%d",&elementLength);
	
	printf("请依次输入你要输入的元素：\n"); 
	for(int i = 0;i < elementLength; i++){
		scanf("%d", &element);
		Insert( &list, i - 1, element );
	}
	
	printf("\n带有表头的单链表创建成功！现在的有表头的单链表为：");
	Output(list);
	
	printf("\n排序过后的单链表为：\n");
	Sort(&list);
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

void Sort(headerList *h){
    node *s1,*s2,*s3,*s4,*p,*q;
    for (p=h->head;p!=NULL && p->link!=NULL;p=p->link) { 
        for (q=p->link;q!=NULL && q->link!=NULL;q=q->link) {
            if (p->link->element > q->link->element) {
                s1=p->link;
                s2=p->link->link;
                s3=q->link;
                s4=q->link->link;
 
                if (s2!=s3) {
                    p->link=s3;
                    s3->link=s2;
                    q->link=s1;
                    s1->link=s4;
                }
                else {                                    
                    p->link=s3;
                    s3->link=s1;
                    q=s3;
                    s1->link=s4;
                }
            }
        }
    }
}
