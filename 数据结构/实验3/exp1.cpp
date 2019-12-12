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
int main()
{
    mGraph g;
    int nSize, edge, u, v, i, j;
    ElemType w;
    printf("size:");
    scanf("%d", &nSize);
    Init(&g, nSize, -1);
    printf("�ߵ�����:");
    scanf("%d", &edge);
    printf("    u v w\n");
    for (i = 0; i < edge; i++)
    {
        printf("%d/%d:", i + 1, edge);
        scanf("%d%d%d", &u, &v, &w);
        Insert(&g, u, v, w);
    }
    printf("u v:");
    scanf("%d%d", &u, &v);
    printf("���еĲ�����: ����\n");
    if (Exist(&g, u, v))
        printf("���еĲ�����: ����\n");
    else
        printf("Error     :����\n");
    printf("P���еĲ�����: ɾ��\n");
    if (Remove(&g, u, v))
        printf("���еĲ�����: ɾ��\n");
    else
        printf("Error     :ɾ��\n");
    printf("���еĲ�����: ����\n");
    Destroy(&g);
    printf("���еĲ�����: ����");
    return 0;
}

