#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define SUCCESS 1

typedef int ElemType;

typedef struct {
	int n;
	ElemType *ele;
	int maxLength;
}SeqList;

int Init( SeqList *L, int maxSize); 
int Find( SeqList L, int i, ElemType *x );
int Insert( SeqList *L, int i, ElemType x );
int Delete( SeqList *L, int i );
int Output( SeqList L );
int Destory( SeqList *L);

int main(){
	SeqList list;
	int maxLength, element, delIndex, elementLength, findIndex, findElement;
	printf("��������Ҫ������˳������󳤶ȣ�");
	scanf("%d", &maxLength);
	Init(&list, maxLength);
	printf("��������Ҫ�����Ԫ�ظ�����");
	scanf("%d",&elementLength);
	printf("������������Ҫ�����Ԫ�أ�"); 
	for(int i = 0;i < elementLength; i++){
		scanf("%d", &element);
		Insert( &list, i - 1, element );
	}
	printf("\n˳������ɹ������ڵ�˳���Ϊ��");
	Output(list);
	printf("\n��Ҫ���ҵ��ǵڼ���Ԫ�أ������������±꣺");
	scanf("%d", &findIndex);
	Find(list,findIndex, &findElement);
	printf("\n���ҳɹ�������ҵ�Ԫ��Ϊ��%d", findElement);
	printf("\n��Ҫɾ�����ǵڼ���Ԫ�أ������������±꣺");
	scanf("%d", &delIndex);
	Delete(&list,delIndex);
	printf("\nɾ���ɹ������ڵ�˳���Ϊ��");
	Output(list);
	Destory(&list);
	return SUCCESS;
}

int Init( SeqList *L, int maxSize){
	L -> maxLength = maxSize;
	L -> n = 0;
	L -> ele = ( ElemType* ) malloc ( sizeof(ElemType*) * maxSize );
	if(!L -> ele)
	return ERROR;
	return SUCCESS;
}

int Find( SeqList L, int i, ElemType *x ){
	if( i > L.n -1 || i < 0 )
	return ERROR;
	*x = L.ele[i];
	return SUCCESS;
}

int Insert( SeqList *L, int i, ElemType x ){
	if( i > L -> n -1 || i < -1 || L -> n == L -> maxLength)
	return ERROR;
	for( int j = L -> n - 1; j > i; j--)
		L -> ele[j + 1] = L -> ele[j];
	L -> ele[i + 1] = x;
	L -> n = L -> n + 1;
	return SUCCESS; 
}

int Delete( SeqList *L, int i ){
	if( i > L -> n - 1 || i < 0)
	return ERROR;
	for( int j  = i + 1; j < L -> n ; j++)
	L -> ele[j - 1] = L -> ele[j];
	L -> n --;
	return SUCCESS;
}

int Output( SeqList L ){
	if(!L.n)
	return ERROR;
	for( int i = 0; i < L.n ; i++)
	printf("%d  ", L.ele[i]);
	return SUCCESS;
}

int Destory( SeqList *L){
	(*L).n = 0;
	(*L).maxLength = 0;
	free( (*L).ele );
}
