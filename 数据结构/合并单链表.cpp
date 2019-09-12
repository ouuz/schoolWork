#include <stdio.h>
#include <stdlib.h>   
 
typedef int ElementType;
typedef struct Node *node;
struct Node {
    ElementType Data;    
    node   Next;    
};
typedef node List;    
 
List Read();    
void Print( List L );   
List Merge( List L1, List L2 );    
 
int main() {
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
 
List Read() {
	int N, i;
	scanf("%d", &N);
	
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;    
	List r = L;    
	for ( i = 0; i < N; i++ ) {
		List p = (List)malloc(sizeof(struct Node));   
		scanf("%d", &p->Data);   
		r->Next = p;   
		r = p;   
	}
	r->Next = NULL;  
	
	return L;   
}
 
void Print( List L ) {
	List p = L->Next;    //将p指向第一个结点，L是头结点，它的下一个结点才是第一个结点。
	if ( p ) {    //链表非空。
		List r = L;    //建立一个临时指针r，指向L.
		while ( r->Next ) {    //当r是最后一个结点的时候，r->Next刚好是NULL退出循环。
			r = r->Next;    //每轮更新r.
			printf("%d ", r->Data);    //打印当前结点的数据域。
		}
	} 
	else	printf("NULL");    //链表为空，直接输出NULL.
	printf("\n");
}
 
List Merge( List L1, List L2 ) {
	List pa, pb, pc, L;
	L = (List)malloc(sizeof(struct Node));    //申请一个头结点L.
	pa = L1->Next;    //指针pa指向L1的第一个结点。
	pb = L2->Next;    //指针pb指向L2的第一个结点。
	pc = L;    //指针pc指向上面创立的头结点L.
	while ( pa && pb ) {    //当L1和L2链表都没有遍历完成的时候。
		if ( pa->Data <= pb->Data ) {    //若pa结点的数据小。
			pc->Next = pa;    //把pa串入L中。
			pc = pa;    //pc移向当前最后一个结点pa，这也是尾插。
			pa = pa->Next;    //在L1链表中，更新pa位置。
		} else {
			pc->Next = pb;
			pc = pb;
			pb = pb->Next;
		}
	}
    /*如果L1未遍历完，将L1全部串入L，如果L2未遍历完，将L2全部串入L*/
	pc->Next = pa ? pa : pb;
	L1->Next = NULL;
	L2->Next = NULL;
	
	return L;
} 

