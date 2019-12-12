#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define OverFlow 2
#define UnderFlow 3
#define NotPresent 4
#define Duplicate 5
typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType **a;
    int n;
    int e;
    ElemType noEdge;
} mGraph;
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
Status Init(mGraph *mg, int nSize, ElemType noEdgeValue)
{
    int i, j;
    mg->n = nSize;
    mg->e = 0;
    mg->noEdge = noEdgeValue;
    mg->a = (ElemType **)malloc(nSize * sizeof(ElemType *));
    if (!mg->a)
        return ERROR;
    for (i = 0; i < mg->n; i++)
    {
        mg->a[i] = (ElemType *)malloc(nSize * sizeof(ElemType));
        for (j = 0; j < mg->n; j++)
            mg->a[i][j] = mg->noEdge;
        mg->a[i][i] = 0;
    }
    return OK;
}
void Destroy(mGraph *mg)
{
    int i;
    for (i = 0; i < mg->n; i++)
        free(mg->a[i]);
    free(mg->a);
}
Status Exist(mGraph *mg, int u, int v)
{
    if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge)
        return ERROR;
    return OK;
}
Status Insert(mGraph *mg, int u, int v, ElemType w)
{
    if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v)
        return ERROR;
    if (mg->a[u][v] != mg->noEdge)
        return Duplicate;
    mg->a[u][v] = w;
    mg->e++;
    return OK;
}
Status Remove(mGraph *mg, int u, int v)
{
    if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v)
        return ERROR;
    if (mg->a[u][v] == mg->noEdge)
        return NotPresent;
    mg->a[u][v] = mg->noEdge;
    mg->e--;
    return OK;
}
void DFS(int v, int visited[], mGraph g)
{
    int j;
    printf("%d ", v);
    visited[v] = 1;
    for (j = 0; j < g.n; j++)
    {
        if (!visited[j] && g.a[v][j] > 0)
        {
            DFS(j, visited, g);
        }
    }
}
void DFSGraph(mGraph g)
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
void BFS(int v, int visited[], mGraph g)
{
    Queue q;
    Create(&q, g.n);
    visited[v] = 1;
    printf("%d ", v);
    EnQueue(&q, v);
    while (!IsEmpty(&q))
    {
        Front(&q, &v);
        DeQueue(&q);
        for (int i = 0; i < g.n; i++)
        {
            if (!visited[i] && g.a[v][i] > 0)
            {
                visited[i] = 1;
                printf("%d ", i);
                EnQueue(&q, i);
            }
        }
    }
}
void BFSGraph(mGraph g)
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
    mGraph g;
    int nSize, edge, u, v, i, j;
    ElemType w;
    printf("size:");
    scanf("%d", &nSize);
    Init(&g, nSize, -1);
    printf("±ßµÄÊýÁ¿:");
    scanf("%d", &edge);
    printf("    u v w\n");
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

