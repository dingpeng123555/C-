#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 50

typedef int Status;
typedef char ElemType;

//���ڵ�
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree; 
//ջ�ṹ
typedef struct{
	BiTNode *base;
	BiTNode *top;
	int stacksize;
}SqStack;
//1��ʼ��ջ
Status InitStack(SqStack &s)
{
	s.base=(BiTNode *)malloc(STACK_INIT_SIZE*sizeof(BiTNode));
	if(!s.base) exit(OVERFLOW);
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return OK;
} 
//2ȡջ��Ԫ�� 
BiTNode *Top(SqStack s)
{
	if(s.top==s.base)return ERROR;
	return s.top-1;
 } 
//3��ջ
Status Push(SqStack &s,BiTree e)
{
	if((s.top-s.base)>=s.stacksize)
	{
		printf("�ڴ治��\n");
		return ERROR;
	}
	s.top->data=e->data;
	s.top->lchild=e->lchild;
	s.top->rchild=e->rchild;
	s.top++;
	return OK;
 } 
//4��ջ 
Status Pop(SqStack &s)
{
	if((s.top==s.base))return ERROR;
	--s.top;
	return OK;
}
//5�ж�ջ��
int StackEmpty(SqStack S)
{
	if(S.top==S.base)
	return 1;
	else
	return 0;
} 
//���򴴽�������
BiTree Create(BiTree T)
{
	ElemType ch;
	ch=getchar();
	if(ch=='#')
	 T=NULL;
	else
	{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->data=ch;
		T->lchild=Create(T->lchild);
		T->rchild=Create(T->rchild);
	}
	return T;
} 
//ʹ��ջ��ǰ������ķǵݹ��㷨
void PreOrderNoRec(BiTree BT)
{
	SqStack S;
	InitStack(S);
	BiTree p=BT;
	while((NULL!=p)||StackEmpty(S))
	{
		if(NULL!=p)
		{
			printf("%c",p->data);
			Push(S,p);
			p=p->lchild;
		}
		else{
			p=Top(S);
			Pop(S);
			p=p->rchild;
		}
	}
 } 
 //ʹ��ջ����������ǵݹ��㷨
 void IneOrderNoRec(BiTree BT)
 {
 	SqStack S;
 	InitStack(S);
 	BiTree p=BT;
 	while((NULL!=p)||!StackEmpty(S))
 	{
 		if(NULL!=p)
 		{
 			Push(S,p);
 			p=p->lchild;
		 }
		 else{
		 	p=Top(S);
		 	Pop(S);
		 	printf("%c",p->data);
		 	p=p->rchild;
		 }
	 }
  } 
void PreOrderTraverse(BiTree T)
{//������������� 
	if(T){
		printf("%c",T->data);//���ʽڵ�
		PreOrderTraverse(T->lchild);//������
		PreOrderTraverse(T->rchild);//������ 
	}	
}
void (BiTree T)
{//�������InOrderTraverse������ 
	if(T){
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
 } 
void PostOrderTraverse(BiTree T)
{
 	if(T){
 		PostOrderTraverse(T->lchild);
 		PostOrderTraverse(T->rchild);
 		printf("%c",T->data);
	 }
}
//������
int main()
{
	BiTree T;
	SqStack S;
	printf("�밴��������������������ֵ��һ���ַ�������#��ʾ������\n");
	T=Create(T);
	printf("\n����������ǵݹ��������ǣ�");
	PreOrderNoRec(T);

	return 0;
 } 
