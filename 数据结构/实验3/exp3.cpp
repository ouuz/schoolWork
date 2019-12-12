#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5
typedef int ElemType;
typedef int Status;
typedef struct ENode
{
    int adjVex;
    ElemType w;
    struct ENode *nextArc;
} ENode;
typedef struct
{
    int n;
    int e;
    ENode **a;
} LGraph;
Status Init(LGraph *lg, int nSize)
{
    int i;
    lg->n = nSize;
    lg->e = 0;
    lg->a = (ENode **)malloc(nSize * sizeof(ENode *));
    if (!lg->a)
        return ERROR;
    else
    {
        for (i = 0; i < lg->n; i++)
        {
            lg->a[i] = NULL;
        }
        return OK;
    }
}
int Destroy(LGraph *lg)
{
    int i;
    ENode *p, *q;
    for (i = 0; i < lg->n; i++)
    {
        p = lg->a[i];
        q = p;
        while (p)
        {
            p = p->nextArc;
            free(q);
            q = p;
        }
    }
    free(lg->a);
    return 1;
}
Status Exist(LGraph *lg, int u, int v)
{
    ENode *p;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
        return ERROR;
    p = lg->a[u];
    while (p != NULL && p->adjVex != v)
    {
        p = p->nextArc;
    }
    if (!p)
        return ERROR;
    else
        return OK;
}
Status Insert(LGraph *lg, int u, int v, ElemType w)
{
    ENode *p;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
        return ERROR;
    if (Exist(lg, u, v))
        return Duplicate;
    p = (ENode *)malloc(sizeof(ENode));
    p->adjVex = v;
    p->w = w;
    p->nextArc = lg->a[u];
    lg->a[u] = p;
    lg->e++;
    return OK;
}
Status Remove(LGraph *lg, int u, int v)
{
    ENode *p, *q;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
        return ERROR;
    p = lg->a[u];
    q = NULL;
    while (p && p->adjVex != v)
    {
        q = p;
        p = p->nextArc;
    }
    if (!p)
        return NotPresent;
    if (q)
        q->nextArc = p->nextArc;
    else
        lg->a[u] = p->nextArc;
    free(p);
    lg->e--;
    return OK;
}
int main()
{
    LGraph g;
    int i, u, v, enode, edge;
    ElemType w;
    printf("size:");
    scanf("%d", &enode);
    Init(&g, enode);
    printf("�ߵ�����:");
    scanf("%d", &edge);
    for (i = 0; i < edge; i++)
    {
        printf("%d/%d:", i + 1, edge);
        scanf("%d%d%d", &u, &v, &w);
        Insert(&g, u, v, w);
    }
    printf("u v:");
    scanf("%d%d", &u, &v);
    printf("���еĲ����ǣ� ����\n");
    if (Exist(&g, u, v))
        printf("���еĲ����ǣ� ����\n");
    else
        printf("Error     :����\n");
    printf("���еĲ����ǣ� ɾ��\n");
    if (Remove(&g, u, v))
        printf("���еĲ����ǣ� ɾ��\n");
    else
        printf("Error     :ɾ��\n");
    printf("���еĲ����ǣ� ����\n");
    Destroy(&g);
    printf("���еĲ����ǣ� ����");
    return 0;
}

