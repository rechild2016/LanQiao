#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct Node {
    struct Node *lchild,*rchild;
    ElemType data;
} *BinTree, BinNode;

//创建二叉树，前序遍历方式输入
void CreateBinTree(BinTree *T)
{
	ElemType c;
	scanf(" %c", &c);

	if('#' == c) {
		*T = NULL;
	} 
	else {
		*T = (BinNode *)malloc(sizeof(BinNode));
		(*T) -> data = c;
		printf("Input lchild:");
		CreateBinTree(&(*T) -> lchild);
		printf("Input rchild:");
		CreateBinTree(&(*T) -> rchild);
	}
}

void visit(ElemType data, int level)
{
	printf("in %d layer:%c \n", level, data);
}

//前序遍历
void PreOrderTraverse(BinTree T,int level)
{
	if( T ){
		visit(T -> data, level);
		PreOrderTraverse(T -> lchild, level + 1);
		PreOrderTraverse(T -> rchild, level + 1);
	}
}

int main()
{
	printf("Input root-Node:\n");
	BinTree T = NULL;

	CreateBinTree(&T);
	PreOrderTraverse(T,1);
	// system("paluse");
	return 0;
}
