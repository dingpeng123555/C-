/*
Name:�ı��༭ 
Time��2020-6-28
Author:Ding
Function:
��1��	����һҳ���֣�ÿ����಻����80���ַ�����N��(N>=5)���������ݵ���ʽ�ͷ�Χ�����������д��Сд��Ӣ����ĸ���κ����ּ������š�
��2��	�ֱ�ͳ�Ƴ�����Ӣ����ĸ���Ϳո�������ƪ������������
��3��	ͳ��ĳһ�ַ����������г��ֵĴ�����������ô�����
��4��	ɾ��ĳһ�Ӵ�������������ַ�ǰ��, ���ɾ��ĳһ�ַ���������£�
��5�������ʽ��
       a����������û�����ĸ����ַ���
       b����4�����"ȫ����ĸ��"��"���ָ���"��"�ո����"��"����������"����Ϣ��
Else��
	1-��ȫ��
	2-ʵ����
	3-�����Ѻ� 
*/
#include<stdio.h>   
#include<stdlib.h> 
#include<string.h> 
#include<malloc.h> 
#include<windows.h>
#define MAXSIZE 1000 
#define SIZE 100
#define OVERFLOW -1
#define OK 1
#define ZERO 0

typedef char DataType;
typedef int Elemtype;
typedef struct node
{
    DataType data[MAXSIZE];
    struct node *next;
}LNode,*LinkList;

void InitLinkedList(LinkList &L)//��ʼ��
{
     //����һ��ͷ���
	L = (LinkList)malloc(sizeof(LNode));//ͷ��������ַ
	if (L == NULL)
		printf("����ռ�ʧ�ܣ������ڴ�");
	L->next = NULL;
}

LinkList InputKeyboard()//���̵���༭
{
    LinkList p,head;
    char str[SIZE];
    int i=0;
    printf("-----------------------------------------\n");
    printf("|�밴��������Ҫ�޸ĵ����£�#��ʾ�������|\n");
    printf("-----------------------------------------\n");
    printf("|ÿ���������80���ַ���������������뻻��|\n");
    printf("-----------------------------------------\n");
    InitLinkedList(p);
    head=p;
    p->next=NULL;
    while(1)
    {
        gets(str);
        if(strlen(str)>80)
        {
            printf("\n");
            printf("ÿ���������80���ַ�������������");break;
        }
        if(str[0]==35)
        {
            str[0]='\0';
            p->next=NULL;
            break;
        }
        p->next=(LinkList)malloc(sizeof(LNode));
        strcpy(p->data,str);
        if(str[strlen(str)-1]==35)
        {
            p->data[strlen(str)-1]='\0';
            break;
        }
        p=p->next;
    }
    p->next=NULL;
    return head;
}
LinkList InputText()//�ı�����༭
{
    LinkList p,head;
    FILE *fp;
    char str[SIZE][SIZE];
    if(!(fp=fopen("test.txt","r")))//���ļ�
    {
        printf("�ļ���ʧ�ܣ������ļ��Ƿ���ڡ�");
        exit(OVERFLOW);
    }
    InitLinkedList(p);//�����׵�ַ��ʼ��
    head=p;
    p->next=NULL;//β�巨
    int i=0;
    for(;fgets(str[i],SIZE,fp)!=NULL;i++)//��ȡÿһ�е�����
    {
        if(strlen(str[i])>80)
        {
            printf("\n");
            printf("��ǰ��%d�г�����80���ַ�",i);
            break;
        }
        strcpy(p->data,str[i]);
        p->next=(LinkList)malloc(sizeof(LNode));
        p=p->next;
    }
    free(p);//�ͷ�pָ�룬��֤���ݰ�ȫ
    return head;
}

LinkList OutPut(LinkList head)//�ı����
{
    LinkList p=head;//pָ��ʼ�ڵ�
    while(p!=NULL)
    {
        printf("%s\n",p->data);//���p��ֵ
        p=p->next;
    }
    printf("\n");
    return p;
}

Elemtype Out_Alpha(LinkList head)//��ĸ���
{
    LinkList p=head;
    int count=0;
    int len;
    while(p!=NULL)
    {
        len=strlen(p->data);
        for(int i=0;i<len;i++)
        {
            if(p->data[i]>='a'&&p->data[i]<='z'||p->data[i]>='A'&&p->data[i]<='Z')
                count++;
        }
        p=p->next;
    }
    return count;
}

Elemtype Out_NUm(LinkList head)//�������
{
    LinkList p=head;
    int count=0;
    int length;
    while(p!=NULL)
    {
        length=strlen(p->data);
        for(int i=0;i<length;i++)
        {
            if(p->data[i]>='0'&&p->data[i]<='9')
            count++;
        }
        p=p->next;
    }
    return count;
}

Elemtype Out_Space(LinkList head)//�ո����
{
    LinkList p=head;
    int count=0;
    int length;
    while (p!=NULL)
    {
       length=strlen(p->data);
       for(int i=0;i<length;i++)
       {
           if(p->data[i]==32)
           count++;
       }
       p=p->next;
    }
    return count;
}

Elemtype Out_Text(LinkList head)//�����ı����
{
    LinkList p=head;
    int count=0;
    while (p!=NULL)
    {
        count+=strlen(p->data);
        p=p->next;
    }
    return count;
}

Elemtype Del_Words(char *s,char *str)//ɾ������ϸ���� 
{
	char *p;  
	int count=0,length,i,j; 
	char a[SIZE]; 
	if(s!=NULL)
	{
		p=strstr(s,str);  // �ҵ���ͬ�ַ��� 
		length=strlen(s); 
		i=length-strlen(p);
		j=i+strlen(str); 
		for(int n=j;n<length;n++)
		{
			a[count++]=s[n];//��������ַ�������Ϊ��   
			a[count]='\0';  
			strcpy(p,a); //��ʣ���ַ������� 
		}
		return OK; 
	}
	else
    {
        printf("������û�и��ַ��������������롣");
        return ZERO;
    }
} 
LinkList Del_Strings(LinkList head,char *str)//ɾ���ַ��� 
{
    LinkList p=head;
    while(p!=NULL)
    {
		while(strstr(p->data,str)!=NULL)  //���û�и��ַ�����ѭ������һ�� 
		Del_Words(p->data,str); 
		p=p->next;
    }
    return head;
}

Elemtype  Search_Tools(char *s,char *str)
{
	int count;
	if(Del_Words(s,str)!= NULL)//�ɽ�ɾ�� 
	{
		count++;
	}
    return count;    
}
Elemtype Search_Strings(LinkList &head,char *str)//��ѯ�ַ��� 
{
    LinkList p=head;
    Elemtype num=0,counts=0;
    Elemtype i,j;
    if(p==NULL)
    {
        printf("�ı�����");
        return ZERO;
    }
    else
    {
	while(p!=NULL)
    {
		while(strstr(p->data,str)!=NULL)  //���ַ��������ַ����в�Ϊ�� 
		counts=Search_Tools(p->data,str); 
		p=p->next;
    }
        return counts;
    }
}
main()
{
    int  i, j, k, l, m;    
    char c = '*';  
    for (i=1; i<=3; i++)        
	    printf("\n");    
    for (i=1; i<=3; i++) 
    {    
        for (j=1; j<=32-2*i; j++)        
            printf(" ");     
        for (k=1; k<=4*i+1; k++)        
            printf("%c", c);
        for (l=1; l<=13-4*i; l++)        
            printf(" ");    
        for (m=1; m<=4*i+1; m++)        
            printf("%c", c);
        printf("\n");        
    }
    Sleep(1000); 
    for (i=1; i<=3; i++) 
    {    
        for (j=1; j<=24+1; j++)            
            printf(" ");    
        for (k=1; k<=29; k++)            
            printf("%c", c);
        printf("\n");        
    }
    Sleep(1000); 
    for (i=7; i>=1; i--) 
    {   
        for (j=1; j<=40-2*i; j++)        
            printf(" ");   
        for (k=1; k<=4*i-1; k++)        
            printf("%c", c);
        printf("\n");        
    }
    Sleep(1000); 
    for (i=1; i<=39; i++)                
        printf(" "); 
    printf("%c\n", c);
    Sleep(1000); 
    for (i=1; i<=3; i++)        
	    printf("\n");  
    printf("**********|**********************************************************|**********\n");
	printf("*******|*****|***************|--------------------|***************|*****|*******\n");
    printf("****|***********|************|��ӭ�����ı��༭ϵͳ|************|***********|****\n"); 
    printf("*|*****************|*********|--------------------|*********|*****************|*\n");
    printf("*|-Class:19130410--|****************************************|-----------------|*\n");	
	char st[SIZE],ss[SIZE]; 
	int x,y;
    LinkList head;
    printf("*|-Date:2020-07-01-|****************************************|---Author:Ding---|*\n");
    printf("**|**************|**      ***|--------------------|***      ***|***********|****\n");
    printf("****|**********|****      ***|--����ѡ�����뷽ʽ--|***      *****|*******|******\n");
    printf("*******|*****|******      ***|**1#ʹ�ü�������****|***      *******|***|********\n");
    printf("**********|*********      ***|**2#ʹ���ļ�����****|***      *********|**********\n");
    printf("********************      ***|**3#�˳���ϵͳ  ****|***      ********************\n");
    printf("********************      ***|--------------------|***      ********************\n");
	printf("********************������������������R E A D M E����������������������*********\n");
	printf("****          *****��ϵͳ֧��ͳ���ı��Ŀո�������ĸ�������������ı�����***   ***\n");
	printf("****          *****��������������ɾ����������Ӧ�ַ������ֵĴ�����������***   ***\n");
	printf("********************************************************************************\n");
	while(1)
	{
		printf("-----------����������ѡ��-----------\n"); 
	    scanf("%d",&x);
	    switch(x)
	    {
	    	case 1:    
				head = InputKeyboard();
				printf("-----------��������ǣ�-----------\n"); 
		    	OutPut(head);
	    	break;
	    	case 2:
	    		head = InputText();
	    		printf("-----------��������ǣ�-----------\n");
	    		OutPut(head);
	    	break;
	    	case 3:
				printf("�ǳ���лʹ�ñ�ϵͳ����ӭ�ٴ�ʹ�á�"); 
				exit(-1);
	    		break;
	    	default:printf("-----�������벻�Ϸ�,����������!------\n"); continue;	
		}
		printf("**********************************************\n");
		printf("*********------------------------*************\n");
		printf("*********|------��ӭѡ����-----|************\n");
		printf("**     **|1�������ǰ�ı��Ŀո���|**      ****\n");
		printf("**     **|2�������ǰ�ı�����ĸ��|**      ****\n");
		printf("**     **|3�������ǰ�ı���������|**      ****\n");
		printf("**     **|4�������ǰ�ı���������|**      ****\n"); 
		printf("**     **|5����ѯ��Ӧ�ַ����ִ���|**      ****\n"); 
		printf("**     **|6��ɾ����ǰ�ı���Ӧ�ַ�|**      ****\n");
		printf("**     **|7���˳���������¼������|**      ****\n"); 
		printf("*********|-----------------------|************\n"); 
		printf("**********************************************\n");
		while(1)
		{
			printf("-----------����������ѡ��-----------\n"); 
			scanf("%d",&y);
			switch(y)
			{
				case 1:
					printf("���ĵ�ȫ���ո���Ϊ: %d \n",Out_Space(head));
				break;
				case 2:
					printf("���ĵ�ȫ����ĸ��Ϊ: %d \n",Out_Alpha(head));
				break;
				case 3:
					printf("���ĵ�ȫ��������Ϊ: %d \n",Out_NUm(head)); 
				break;
				case 4:
					printf("���ĵ�ȫ��������Ϊ: %d \n",Out_Text(head));
				break;
				case 5:
					printf("������ͳ�Ƶ��ַ���:\n");
					scanf("%s",&st); 
					printf("%s���ı��г��ֵĴ���Ϊ: %d \n",st,Search_Strings(head,st));
					printf("\n");
				break;
				case 6:
					printf("������ɾ�����ַ�����\n"); 
					scanf("%s",&ss);
					head = Del_Strings(head,ss);
					printf("ɾ��%s����ı�Ϊ:\n",ss);
					OutPut(head);
				break;
				case 7:
					printf("-----��ѡ���ı������뷽ʽ------\n"); 
				break;
				default:printf("-----�������벻�Ϸ�,����������!------\n"); continue;
			}
		break;
		}
	}
}
