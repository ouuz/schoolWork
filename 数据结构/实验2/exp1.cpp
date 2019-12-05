#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct BinTree
{
    ElemType data;
    struct BinTree *lchild, *rchild;
} BinTree, *BiTree;
void PreCreateBt(BiTree *T)
{
    ElemType c;
    scanf("%c", &c);
    if ('#' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BinTree *)malloc(sizeof(BinTree));
        (*T)->data = c;
        PreCreateBt(&(*T)->lchild);
        PreCreateBt(&(*T)->rchild);
    }
}
void PreOrderTransverse(BiTree T)
{
    if (T)
    {
        printf("%c", T->data);
        PreOrderTransverse(T->lchild);
        PreOrderTransverse(T->rchild);
    }
}
void InOrderTransverse(BiTree T)
{
    if (T)
    {
        PreOrderTransverse(T->lchild);
        printf("%c", T->data);
        PreOrderTransverse(T->rchild);
    }
}
void PostOrderTransverse(BiTree T)
{
    if (T)
    {
        PreOrderTransverse(T->lchild);
        PreOrderTransverse(T->rchild);
        printf("%c", T->data);
    }
}
int main()
{
    BiTree T = NULL;
    printf("���򴴽���");
    PreCreateBt(&T);
    printf("���������");
    PreOrderTransverse(T);
    printf("\n���������");
    InOrderTransverse(T);
    printf("\n���������");
    PostOrderTransverse(T);
    return 0;
}

