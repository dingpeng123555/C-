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

//树节点
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree; 
//栈结构
typedef struct{
	BiTNode *base;
	BiTNode *top;
	int stacksize;
}SqStack;
//1初始化栈
Status InitStack(SqStack &s)
{
	s.base=(BiTNode *)malloc(STACK_INIT_SIZE*sizeof(BiTNode));
	if(!s.base) exit(OVERFLOW);
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return OK;
} 
//2取栈顶元素 
BiTNode *Top(SqStack s)
{
	if(s.top==s.base)return ERROR;
	return s.top-1;
 } 
//3入栈
Status Push(SqStack &s,BiTree e)
{
	if((s.top-s.base)>=s.stacksize)
	{
		printf("内存不足\n");
		return ERROR;
	}
	s.top->data=e->data;
	s.top->lchild=e->lchild;
	s.top->rchild=e->rchild;
	s.top++;
	return OK;
 } 
//4出栈 
Status Pop(SqStack &s)
{
	if((s.top==s.base))return ERROR;
	--s.top;
	return OK;
}
//5判断栈空
int StackEmpty(SqStack S)
{
	if(S.top==S.base)
	return 1;
	else
	return 0;
} 
//先序创建二叉树
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
//使用栈的前序遍历的非递归算法
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
 //使用栈的中序遍历非递归算法
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
{//先序遍历二叉树 
	if(T){
		printf("%c",T->data);//访问节点
		PreOrderTraverse(T->lchild);//遍历左
		PreOrderTraverse(T->rchild);//遍历右 
	}	
}
void (BiTree T)
{//中序遍历InOrderTraverse二叉树 
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
//主函数
int main()
{
	BiTree T;
	SqStack S;
	printf("请按先序次序输入二叉树结点的值（一个字符），用#表示空树：\n");
	T=Create(T);
	printf("\n二叉树先序非递归遍历结果是：");
	PreOrderNoRec(T);

	return 0;
 } 
