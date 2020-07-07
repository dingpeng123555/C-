#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
//���� 
typedef int Elemtype;
typedef struct LNode{
	Elemtype data;
	struct LNode *next;
}LNode,*Linklist;
//��ȡԪ�� ����ѯ�� 
Elemtype GetElem(Linklist L,Elemtype i,Elemtype &e)
{
	Linklist p;
	int j;
	p=L->next;
	j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i){
		return ERROR;
	}
	e=p->data;
	return OK;
}
//����Ԫ��
Elemtype ListInsert(Linklist &L,Elemtype i,Elemtype e)
{
	LNode *p,*s;
	int j;
	p=L;
	j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	 }
	if(!p||j>i-1)
	return ERROR;
	s=(Linklist)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
//ɾ��Ԫ��
Elemtype  ListDelete(Linklist &L,Elemtype i)
{
	LNode *p,*q;
	int j; 
	p=L,j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p->next==NULL||j>i-1)
	return ERROR;
	q=p->next;
	p->next=q->next;
	free(q);
	return OK;
} 
//��ӡ������ 
void print_list(Linklist &L){
       Linklist p;
       for(p=L->next;p!=NULL;)
       { 
          printf("%d ",p->data);
          p=p->next;
       }
       printf("\n");
    }
//����������
void CreatList(Linklist &L,int n) 
  {
    Linklist p,q;
	int i; 
    p=L;
    printf("data:");
    for(i=1;i<=n;i++)
	{ 
    	q=(Linklist)malloc(sizeof(LNode));
    	scanf("%d",&q->data);
    	q->next=NULL;
		p->next=q;
		p=q;
    } 
    print_list(L);
}
//�ϲ��������� 
void mergelist_L(Linklist &la,Linklist &lb,Linklist &lc)
{
	Linklist pa,pb,pc;
	pa=la->next;
	pb=lb->next;
	pc=lc=la;
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
			
	if(pa)
	pc->next=pa;
	else
	pc->next=pb;
}
	
}
int main()
{
	int i;
	int n;
	int flag;
	char s;
	int e;
	int x;
	int a;
	Linklist La,Lb,Lc;
	while(1)
	{ 
	printf("*******************************\n");
	printf("1��������Ĵ�����2��������Ĳ��룬3���������ɾ����4��������Ĳ��ң�5�����������ʾ,6���˳�\n");
	printf("*******************************\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:{
				La=(Linklist)malloc(sizeof(LNode));
				La->next=NULL;
				printf("������A����Ľ�����n=\n");
				scanf("%d",&n);
				CreatList(La,n);
				Lb=(Linklist)malloc(sizeof(LNode));
				Lb->next=NULL;
				printf("������B����Ľ�����n=\n");
				scanf("%d",&n);
				CreatList(Lb,n);
				Lc=(Linklist)malloc(sizeof(LNode));
				Lc->next=NULL;
				mergelist_L(La,Lb,Lc);
				print_list(Lc);
			break;
		}
		case 2:{
			printf("������Lc�����λ����ֵ\n");
			scanf("%d%d",&i,&e);
			flag=ListInsert(Lc,i,e);if(flag)
			{
			printf("�Ѳ���\n");
			print_list(Lc);
			}
			else
			{
				printf("����ʧ��\n"); 
			}
			break;
		}
		case 3:{
			printf("������Lcɾ����λ��");
			scanf("%d",&i);
			flag=ListDelete(Lc,i);
			if(flag)
			{
			printf("��ɾ��\n");
			print_list(Lc);
			}
			else
			{
				printf("ɾ��ʧ��\n"); 
			}
			break;
		}
		case 4:{
				printf("������Lc��ѯ��λ��\n");
				scanf("%d",&i);
				flag=ListInsert(Lc,i,a);
				if(flag)
				{
				printf("�Ѳ�ѯ��\n");
				printf("%d\n",a);
				}
				else
				{
					printf("��ѯʧ��\n"); 
				}
			break;
		}
		case 5:{
			printf("�������ѯ��������1-LA,2-LB,,3-LC");
			scanf("%d",&i);
			if(i==1)
			 print_list(La);
			 if(i==2)
			 print_list(Lb);
			 if(i==3)
			 print_list(Lc);
			break;
		}
		case 6:{
			free(La);
			free(Lb);
			free(Lc);
			exit(OVERFLOW);
			break;
		}
	}
	}
	return 0;
}
