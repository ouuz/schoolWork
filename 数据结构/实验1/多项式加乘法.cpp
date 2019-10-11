#include <stdio.h>
#include <stdlib.h>
typedef struct pNode{
	int coef;
	int exp;
	struct pNode *link;
}pNode;

typedef struct{
	struct pNode *head;
}polynominal;

void create(polynominal *p);
void Add(polynominal *px, polynominal *qx);
int Multiply(polynominal px, polynominal qx, polynominal *temp); 
void Output(polynominal p);

int main(){
	polynominal p, q, temp;
	
	printf("�����������һ��һԪ����ʽ��Ԫ�ص�ϵ����ָ����");
	create(&p);
	printf("����������ڶ���һԪ����ʽ��Ԫ�ص�ϵ����ָ����");
	create(&q);
	
	printf("\n���ڵ�һ��һԪ����ʽΪ��");
	Output(p);
	printf("\n���ڵڶ���һԪ����ʽΪ��");
	Output(q);
	
	Multiply(p, q, &temp);
	printf("\n��������ʽ��˹���õ��Ľ��Ϊ��");
	Output(temp);
	
	Add(&p, &q);
	printf("\n��������ʽ��ӹ���õ��Ľ��Ϊ��");
	Output(q);
	
	return 0;
}

void create(polynominal *p){
	pNode *pn, *q, *r;
	p -> head = (pNode*) malloc(sizeof(pNode));
	p -> head -> exp = -1;
	p -> head -> link = NULL;
	for(;;){
		pn = (pNode*)malloc(sizeof(pNode));
		printf("coef:");
		scanf("%d", &pn -> coef);
		printf("exp:");
		scanf("%d", &pn -> exp);
		if(pn -> exp < 0)
		break;
		q = p -> head;
		r = p -> head -> link;
		while(r && r -> exp > pn -> exp){
			q = r;
			r = r -> link;
		}
		pn -> link = r;
		q -> link = pn; 
	} 
}

void Add(polynominal *px, polynominal *qx)
{
    pNode *ph = px->head, *qh = qx->head, *p1, *q1, *pre;

    pNode *tail;
    tail = qx->head;
    pNode *tailNode;
    tailNode = (pNode *)malloc(sizeof(pNode));
    tailNode->exp = -1;
    tailNode->coef = 0;
    tailNode->link = NULL;
    while (tail->link)
    {
        tail = tail->link;
    }
    tail->link = tailNode;

    p1 = ph->link;
    q1 = qh->link;
    pre = qh;
    while (p1)
    {
        while (p1->exp < q1->exp)
        {
            pre = q1;
            q1 = q1->link;
        }
        if (p1->exp > q1->exp)
        {
            pNode *tmp;
            tmp = (pNode *)malloc(sizeof(pNode));
            tmp->coef = p1->coef;
            tmp->exp = p1->exp;
            tmp->link = q1;
            pre->link = tmp;
            pre = pre->link;
            p1 = p1->link;
        }
        else if (p1->exp == q1->exp)
        {
            q1->coef = q1->coef + p1->coef;
            if (q1->coef == 0)
            {
                pre->link = q1->link;
                free(q1);
                q1 = pre->link;
            }
            p1 = p1->link;
        }
    }
    free(tail->link);
    tail->link = NULL;
}


int Multiply(polynominal px, polynominal qx, polynominal *temp)
{ //��������ص�temp��
    pNode *p1, *q1, *ph, *qh, *tmp, *tp, *tailNode;
    tmp = (pNode *)malloc(sizeof(pNode));
    tmp->coef = 0;
    tmp->exp = -1;
    tmp->link = NULL;
    temp->head = tmp;
    tailNode = (pNode *)malloc(sizeof(pNode));
    //ͬAdd����һ������Ӹ�����β��㣬�������ƺ�׺���ʽĩβ��#
    tailNode->coef = 0;
    tailNode->exp = -1;
    tailNode->link = NULL;
    tmp->link = tailNode;
    ph = px.head;
    qh = qx.head;
    p1 = ph->link;
    q1 = qh->link;
    while (q1)
    {
        while (p1)
        {
            pNode *p; //��ǰ��˻�
            p = (pNode *)malloc(sizeof(pNode));
            p->coef = p1->coef * q1->coef;
            p->exp = p1->exp + q1->exp;
            
            
            printf("!!!!!\n");
            
            pNode *ptr; //ָ����
            pNode *pre;
            ptr = temp->head->link;
            pre = temp->head;
            if (tmp->link == tailNode)
            { //������������������ж�ֱ�����
                tmp->link = p;
                p->link = tailNode;
            }
            else
            { //���˻���ո���ָ����С��������
                while (p->exp < ptr->exp)
                {
                    pre = ptr;
                    ptr = ptr->link;
                }
                if (p->exp > ptr->exp)
                {
                    pre->link = p;
                    p->link = ptr;
                }
                else if (p->exp == ptr->exp)
                {
                    ptr->coef = p->coef + ptr->coef;
                    if (ptr->coef == 0)
                    {
                        pre->link = ptr->link;
                        free(ptr);
                    }
                }
            }
            p1 = p1->link;
        }
        q1 = q1->link;
    }
    pNode *tail;
    tail = temp->head;
    while (tail->link)
    {
        tail = tail->link;
    }
    free(tail->link);
    tail->link = NULL; //��������tailNodeɾ�����ͷſռ�
    return 1;
}





void Output(polynominal p){
	pNode *q ;
	q = p.head -> link;
	while(q){
		q -> coef >= 0?
			printf("+%d",q -> coef)
		:
			printf("%d",q -> coef);
		printf("*x^%d",q -> exp);
		q = q -> link;
	}
}



