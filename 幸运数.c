#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct Node {
	ElemType data;
	struct Node *next;
}Node,*pNode;
 
typedef struct {
	pNode head;
	pNode rear;
	int ListSize;//�洢�ռ��С
}List;

//�����ʼ��
void initList(List *list)
{
	list->head = list->rear = (pNode)malloc(sizeof(Node));
	if (list->head != NULL)
	{
		list->ListSize = 0;
		list->head->data = 0;//��ֵΪ0
		list->head->next = NULL;
	}
}

//������ĩ������һ���ڵ�
void addRear(List *list,ElemType e)
{
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = NULL;
	list->rear->next = p;
	list->rear = p;
	list->ListSize++;
}

//��ĳһָ��λ����ӽڵ�
int addList(List *list, int add, ElemType e)
{
	Node *p,*q;
	int i;
	add--;
	if (add <= list->ListSize && add >=0)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = e;
		p->next = NULL;
		q = list->head;
		for (i = 0; i < add; i++)
		{
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
		//q = p;
		list->ListSize++;
		return 1;
	}
	else
	{
		puts("���ʧ�ܣ�");
		return 0;
	}
}

//ɾ��ָ��λ�ýڵ�
int deleteList(List *list, int add)
{
	Node *p, *q;
	int i;
	if (add <= list->ListSize && add >0)
	{
		q = list->head;
		for (i = 1; i < add; i++)
		{
			q = q->next;
		}
		p = q->next;
		q->next = p->next;
		list->ListSize--;
		free(p);
		return 1;
	}
	else
	{
	//	puts("ɾ��ʧ�ܣ�");
		return 0;
	}
}

void traverList(List *list)
{
	Node *p;
	int i = 1;
	p = list->head->next;
	while (p != NULL)
	{
		printf_s("��%d��Ԫ��Ϊ��%d\n", i, p->data);
		i++;
		p = p->next;
	}
	free(p);
}

//�������ֵ��ȡ��������
void pickList(List *list, ElemType *a)
{
	Node *p;
	int i = 0;
	p = list->head->next;
	while (p != NULL)
	{
		//printf_s("��%d��Ԫ��Ϊ��%d\n", i, p->data);
		a[i] = p->data;
		i++;
		p = p->next;
	}
	free(p);
}
int main()
{
	List alist;//�ȶ���һ��ʵ��
	List *list = &alist;
	int i,j,flag=0;
	int m, n,len=0;
	ElemType *a;
	scanf("%d %d", &m, &n);
	a = (ElemType*)malloc(n*sizeof(ElemType));
	initList(list);
	for (i = 1; i <= n; i++)
	{
		addRear(list, i);
	}
	
	for (i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			deleteList(list, i - flag);
			flag++;
		}
	}
	for ( j = 1; j < n; j++)
	{
		flag = 0;
		pickList(list, a);

		for (i = 1; i <= n; i++)
		{
			if (i % (a[j]) == 0)
			{
				deleteList(list, i - flag);
				flag++;
			}
		}

	}

	pickList(list, a);
	
	for(i = 0; i < alist.ListSize; i++)
	{
		if (a[i] > m && a[i] < n)
		{
			len++;
		}
	}
	printf("%d", len);
	free(a); 
	for(i=1;i<=alist.ListSize; i++)
	{
		deleteList(list, 1);
	}
	return 0;
}

