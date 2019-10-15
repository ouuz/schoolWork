#include<stdio.h>
#include<stdlib.h>

typedef struct PNode{
    int coef;             //系数
    int exp;              //指数
    struct PNode* link;
}PNode;

typedef struct{
    struct PNode *head;
}polynominal;



void Create(polynominal *p){
    PNode *pn,*pre,*q;
    p->head = (PNode*)malloc(sizeof(PNode));
    p->head->exp = -1;
    p->head->link = p->head;                    
    for(;;){
        pn=(PNode*)malloc(sizeof(PNode));
        printf("coef:\n");
        scanf("%d",&pn->coef);
        printf("exp:\n");
        scanf("%d",&pn->exp);
        if(pn->exp<0) break;
        pre = p->head;
        q = p->head->link;
        while(q && q->exp > pn->exp){
            pre = q;
            q = q->link;
        }
        pn->link = q;
        pre->link = pn;
    }
}


void Output(polynominal p){
    PNode *q;
    int flag = 1;                                 
    q = p.head->link;
    if (!q){
        return;
    }
    while(q != p.head){
        if (!flag && (q->coef > 0)) printf("+");	
        flag = 0;                                  
        if(q->coef == 0){                          
            return;
        }
        printf("%d",q->coef);                       
        switch(q->exp){                            
            case 0:break;                           
            case 1:printf("X");break;             
            default:printf("X^%d",q->exp);break;
        }
        q = q->link;
    }
}

void Add(polynominal *px,polynominal *qx){
    PNode *q,*q1 = qx->head,*p, *p1,*temp;    
    p = px->head->link;                       
    p1 = px->head;
    q = q1->link;                            
    while(p->exp >= 0){
        while(p->exp < q->exp){              
            q1 = q;
            q = q->link;
        }
        if(p->exp == q->exp){                
            q->coef = q->coef + p->coef;
            if(q->coef == 0){                
                q1->link = q->link;          
                free(q);                    
                q = q1->link;               
                p = p->link;
            } 
            else{
                q1 = q;                       
                q = q->link;
                p = p->link;                
            }
        }
        else{                                 
            temp = (PNode*)malloc(sizeof(PNode));     
            temp->coef = p->coef;
            temp->exp = p->exp;
            temp->link = q1->link;
            q1->link = temp;
            q1 = q1->link;
            p = p->link;
        }
   }
}


void Multiply(polynominal *px,polynominal *qx){
    polynominal qx1,qx2;
    PNode *q1,*q2,*q3,*q4,*pre,*q;
    qx1.head = (PNode*)malloc(sizeof(PNode));       
    qx1.head->exp = -1;
    qx1.head->link = qx1.head;                      
    q1 = px->head->link;                            
    q2 = qx->head->link;                            
    while(q2->exp != -1){                           
        q3 = (PNode*)malloc(sizeof(PNode));         
        q3->coef = q1->coef * q2->coef;
        q3->exp = q1->exp + q2->exp;
        if(qx1.head->link->exp == -1){            
            q3->link = qx1.head->link;
            qx1.head->link = q3;
            pre = qx1.head->link;
        }
        else{
            q3->link = qx1.head;
            pre->link = q3;
            pre = pre->link;
        }
        q2 = q2->link;
    }
    q1 = q1->link;                                 
    while(q1->exp != -1){                         
        q2 = q2->link;
        qx2.head = (PNode*)malloc(sizeof(PNode)); 
        qx2.head->exp = -1;
        qx2.head->link = qx2.head;
        while(q2->exp != -1){   	
            q4 = (PNode*)malloc(sizeof(PNode));
            q4->coef = q1->coef * q2->coef;
            q4->exp = q1->exp + q2->exp;
            if(qx2.head->link->exp == -1){
                q4->link = qx2.head->link;
                qx2.head->link = q4;
                pre = qx2.head->link;
            }
            else{
                q4->link = qx2.head;
                pre->link = q4;
                pre = pre->link;
            }
            q2 = q2->link;
        }
        Add(&qx2,&qx1);                            
        q1 = q1->link;
    }
    Output(qx1);
}

void Destroy(polynominal *p){
	PNode *pn;
	while(p->head->link)
	{
		pn = p->head->link; 
		free(p->head);
		p->head = pn;
	}
}



int main(){
    polynominal p,q;
    int x;
    printf("请输入第一个多项式为：\n");
    Create(&p);
    printf("\n\n请输入第二个多项式为\n");
    Create(&q);
    
	printf("\n现在第一个一元多项式为：");
	Output(p);
	printf("\n现在第二个一元多项式为：");
	Output(q);
	
    printf("\n\n请选择你要进行的操作：（0为加法，1为乘法）\n");
    scanf("%d",&x);
    switch(x){
        case 0:printf("Add:\n");
        Add(&p,&q);
        Output(q);
        break;
        case 1:printf("Multiply:\n");
        Multiply(&p,&q);
        default:break;
    }
    return 0;
}
