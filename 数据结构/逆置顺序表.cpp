#include <stdio.h>
#define MaxSize 100
typedef int ElemType;
typedef struct{
	int length;
	ElemType data[MaxSize];
}SeqList;

void Reverse(SeqList *L){
	ElemType temp;
	for(int i=0;i<L->length/2;i++){
		temp = L->data[i];
		L->data[i] = L->data[L->length-1-i];
		L->data[L->length-1-i] = temp;
	}
}

void Output(SeqList *L){
	for(int i=0;i<L->length;i++){
		printf("%d\t",L->data[i]);
	};
}

int main(){
	SeqList SL;
	SL.length = 9;
	for(int i = 0;i<SL.length;i++){
		SL.data[i] = i;
	}
	Output(&SL);
	Reverse(&SL);
	printf("\n\nÄæÖÃ¹ýºó£º\n\n");
	Output(&SL);
	return 0;
}
