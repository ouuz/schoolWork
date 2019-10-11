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
	
	printf("请依次输入第一个一元多项式内元素的系数和指数：");
	create(&p);
	printf("请依次输入第二个一元多项式内元素的系数和指数：");
	create(&q);
	
	printf("\n现在第一个一元多项式为：");
	Output(p);
	printf("\n现在第二个一元多项式为：");
	Output(q);
	
	Multiply(p, q, &temp);
	printf("\n两个多项式相乘过后得到的结果为：");
	Output(temp);
	
	Add(&p, &q);
	printf("\n两个多项式相加过后得到的结果为：");
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
{ //将结果返回到temp中
    pNode *p1, *q1, *ph, *qh, *tmp, *tp, *tailNode;
    tmp = (pNode *)malloc(sizeof(pNode));
    tmp->coef = 0;
    tmp->exp = -1;
    tmp->link = NULL;
    temp->head = tmp;
    tailNode = (pNode *)malloc(sizeof(pNode));
    //同Add函数一样，添加辅助结尾结点，功能类似后缀表达式末尾的#
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
            pNode *p; //当前项乘积
            p = (pNode *)malloc(sizeof(pNode));
            p->coef = p1->coef * q1->coef;
            p->exp = p1->exp + q1->exp;
            
            
            printf("!!!!!\n");
            
            pNode *ptr; //指针结点
            pNode *pre;
            ptr = temp->head->link;
            pre = temp->head;
            if (tmp->link == tailNode)
            { //若链表中无项，则无需判断直接添加
                tmp->link = p;
                p->link = tailNode;
            }
            else
            { //将乘积项按照各项指数大小存入链表
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
    tail->link = NULL; //将辅助的tailNode删除，释放空间
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



