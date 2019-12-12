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
typedef struct
{
    int front;
    int rear;
    int maxSize;
    ElemType *element;
} Queue;
void Create(Queue *Q, int mSize)
{
    Q->maxSize = mSize;
    Q->element = (ElemType *)malloc(sizeof(ElemType) * mSize);
    Q->front = Q->rear = 0;
}
bool IsEmpty(Queue *Q)
{
    return Q->front == Q->rear;
}
bool IsFULL(Queue *Q)
{
    return (Q->rear + 1) % Q->maxSize == Q->front;
}
bool Front(Queue *Q, ElemType *x)
{
    if (IsEmpty(Q))
        return false;
    *x = Q->element[(Q->front + 1) % Q->maxSize];
    return true;
}
bool EnQueue(Queue *Q, ElemType x)
{
    if (IsFULL(Q))
        return false;
    Q->rear = (Q->rear + 1) % Q->maxSize;
    Q->element[Q->rear] = x;
    return true;
}
bool DeQueue(Queue *Q)
{
    if (IsEmpty(Q))
    {
        return false;
    }
    Q->front = (Q->front + 1) % Q->maxSize;
    return true;
}
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
void DFS(int v, int visited[], LGraph g)
{
    ENode *w;
    printf("%d ", v);
    visited[v] = 1;
    for (w = g.a[v]; w; w = w->nextArc)
    {
        if (!visited[w->adjVex])
        {
            DFS(w->adjVex, visited, g);
        }
    }
}
void DFSGraph(LGraph g)
{
    int i;
    int *visited = (int *)malloc(g.n * sizeof(int));
    for (i = 0; i < g.n; i++)
    {
        visited[i] = 0;
    }
    for (i = 0; i < g.n; i++)
    {
        if (!visited[i])
        {
            DFS(i, visited, g);
        }
    }
    free(visited);
}
void BFS(int v, int visited[], LGraph g)
{
    ENode *w;
    Queue q;
    Create(&q, g.n);
    visited[v] = 1;
    printf("%d ", v);
    EnQueue(&q, v);
    while (!IsEmpty(&q))
    {
        Front(&q, &v);
        DeQueue(&q);
        for (w = g.a[v]; w; w = w->nextArc)
        {
            if (!visited[w->adjVex])
            {
                visited[w->adjVex] = 1;
                printf("%d ", w->adjVex);
                EnQueue(&q, w->adjVex);
            }
        }
    }
}
void BFSGraph(LGraph g)
{
    int i;
    int *visited = (int *)malloc(g.n * sizeof(int));
    for (i = 0; i < g.n; i++)
    {
        visited[i] = 0;
    }
    for (i = 0; i < g.n; i++)
    {
        if (!visited[i])
        {
            BFS(i, visited, g);
        }
    }
    free(visited);
}
int main()
{
    LGraph g;
    int i, u, v, enode, edge;
    ElemType w;
    printf("size:");
    scanf("%d", &enode);
    Init(&g, enode);
    printf("±ßµÄÊýÁ¿:");
    scanf("%d", &edge);
    for (i = 0; i < edge; i++)
    {
        printf("%d/%d:", i + 1, edge);
        scanf("%d%d%d", &u, &v, &w);
        Insert(&g, u, v, w);
    }
    printf("DFS:");
    DFSGraph(g);
    printf("\nBFS:");
    BFSGraph(g);
    return 0;
}
