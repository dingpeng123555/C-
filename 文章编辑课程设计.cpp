/*
Name:文本编辑 
Time：2020-6-28
Author:Ding
Function:
（1）	输入一页文字，每行最多不超过80个字符，共N行(N>=5)；输入数据的形式和范围：可以输入大写、小写的英文字母、任何数字及标点符号。
（2）	分别统计出其中英文字母数和空格数及整篇文章总字数；
（3）	统计某一字符串在文章中出现的次数，并输出该次数；
（4）	删除某一子串，并将后面的字符前移, 输出删除某一字符串后的文章；
（5）输出形式：
       a）分行输出用户输入的各行字符；
       b）分4行输出"全部字母数"、"数字个数"、"空格个数"、"文章总字数"等信息。
Else：
	1-安全性
	2-实用性
	3-界面友好 
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

void InitLinkedList(LinkList &L)//初始化
{
     //定义一个头结点
	L = (LinkList)malloc(sizeof(LNode));//头结点申请地址
	if (L == NULL)
		printf("分配空间失败，请检查内存");
	L->next = NULL;
}

LinkList InputKeyboard()//键盘导入编辑
{
    LinkList p,head;
    char str[SIZE];
    int i=0;
    printf("-----------------------------------------\n");
    printf("|请按行输入想要修改的文章，#表示输入完成|\n");
    printf("-----------------------------------------\n");
    printf("|每行最多输入80个字符，如需输入更多请换行|\n");
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
            printf("每行最多输入80个字符，请重新输入");break;
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
LinkList InputText()//文本导入编辑
{
    LinkList p,head;
    FILE *fp;
    char str[SIZE][SIZE];
    if(!(fp=fopen("test.txt","r")))//打开文件
    {
        printf("文件打开失败，请检查文件是否存在。");
        exit(OVERFLOW);
    }
    InitLinkedList(p);//分配首地址初始化
    head=p;
    p->next=NULL;//尾插法
    int i=0;
    for(;fgets(str[i],SIZE,fp)!=NULL;i++)//读取每一行的内容
    {
        if(strlen(str[i])>80)
        {
            printf("\n");
            printf("当前第%d行超过了80个字符",i);
            break;
        }
        strcpy(p->data,str[i]);
        p->next=(LinkList)malloc(sizeof(LNode));
        p=p->next;
    }
    free(p);//释放p指针，保证数据安全
    return head;
}

LinkList OutPut(LinkList head)//文本输出
{
    LinkList p=head;//p指向开始节点
    while(p!=NULL)
    {
        printf("%s\n",p->data);//输出p的值
        p=p->next;
    }
    printf("\n");
    return p;
}

Elemtype Out_Alpha(LinkList head)//字母输出
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

Elemtype Out_NUm(LinkList head)//数字输出
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

Elemtype Out_Space(LinkList head)//空格输出
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

Elemtype Out_Text(LinkList head)//所有文本输出
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

Elemtype Del_Words(char *s,char *str)//删除的详细步骤 
{
	char *p;  
	int count=0,length,i,j; 
	char a[SIZE]; 
	if(s!=NULL)
	{
		p=strstr(s,str);  // 找到相同字符串 
		length=strlen(s); 
		i=length-strlen(p);
		j=i+strlen(str); 
		for(int n=j;n<length;n++)
		{
			a[count++]=s[n];//如果存在字符串则置为空   
			a[count]='\0';  
			strcpy(p,a); //将剩余字符串复制 
		}
		return OK; 
	}
	else
    {
        printf("文章中没有该字符串，请重新输入。");
        return ZERO;
    }
} 
LinkList Del_Strings(LinkList head,char *str)//删除字符串 
{
    LinkList p=head;
    while(p!=NULL)
    {
		while(strstr(p->data,str)!=NULL)  //如果没有该字符串则循环到下一个 
		Del_Words(p->data,str); 
		p=p->next;
    }
    return head;
}

Elemtype  Search_Tools(char *s,char *str)
{
	int count;
	if(Del_Words(s,str)!= NULL)//巧借删除 
	{
		count++;
	}
    return count;    
}
Elemtype Search_Strings(LinkList &head,char *str)//查询字符串 
{
    LinkList p=head;
    Elemtype num=0,counts=0;
    Elemtype i,j;
    if(p==NULL)
    {
        printf("文本有误。");
        return ZERO;
    }
    else
    {
	while(p!=NULL)
    {
		while(strstr(p->data,str)!=NULL)  //该字符串在总字符串中不为空 
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
    printf("****|***********|************|欢迎来到文本编辑系统|************|***********|****\n"); 
    printf("*|*****************|*********|--------------------|*********|*****************|*\n");
    printf("*|-Class:19130410--|****************************************|-----------------|*\n");	
	char st[SIZE],ss[SIZE]; 
	int x,y;
    LinkList head;
    printf("*|-Date:2020-07-01-|****************************************|---Author:Ding---|*\n");
    printf("**|**************|**      ***|--------------------|***      ***|***********|****\n");
    printf("****|**********|****      ***|--请您选择输入方式--|***      *****|*******|******\n");
    printf("*******|*****|******      ***|**1#使用键盘输入****|***      *******|***|********\n");
    printf("**********|*********      ***|**2#使用文件导入****|***      *********|**********\n");
    printf("********************      ***|**3#退出该系统  ****|***      ********************\n");
    printf("********************      ***|--------------------|***      ********************\n");
	printf("********************—————————R E A D M E———————————*********\n");
	printf("****          *****本系统支持统计文本的空格数，字母数，数字数，文本总数***   ***\n");
	printf("****          *****———————删除，查找相应字符串出现的次数————***   ***\n");
	printf("********************************************************************************\n");
	while(1)
	{
		printf("-----------请输入您的选择：-----------\n"); 
	    scanf("%d",&x);
	    switch(x)
	    {
	    	case 1:    
				head = InputKeyboard();
				printf("-----------您输入的是：-----------\n"); 
		    	OutPut(head);
	    	break;
	    	case 2:
	    		head = InputText();
	    		printf("-----------您导入的是：-----------\n");
	    		OutPut(head);
	    	break;
	    	case 3:
				printf("非常感谢使用本系统，欢迎再次使用。"); 
				exit(-1);
	    		break;
	    	default:printf("-----您的输入不合法,请重新输入!------\n"); continue;	
		}
		printf("**********************************************\n");
		printf("*********------------------------*************\n");
		printf("*********|------欢迎选择功能-----|************\n");
		printf("**     **|1、输出当前文本的空格数|**      ****\n");
		printf("**     **|2、输出当前文本的字母数|**      ****\n");
		printf("**     **|3、输出当前文本的数字数|**      ****\n");
		printf("**     **|4、输出当前文本的总字数|**      ****\n"); 
		printf("**     **|5、查询相应字符出现次数|**      ****\n"); 
		printf("**     **|6、删除当前文本相应字符|**      ****\n");
		printf("**     **|7、退出功能重新录入文字|**      ****\n"); 
		printf("*********|-----------------------|************\n"); 
		printf("**********************************************\n");
		while(1)
		{
			printf("-----------请输入您的选择：-----------\n"); 
			scanf("%d",&y);
			switch(y)
			{
				case 1:
					printf("本文的全部空格数为: %d \n",Out_Space(head));
				break;
				case 2:
					printf("本文的全部字母数为: %d \n",Out_Alpha(head));
				break;
				case 3:
					printf("本文的全部数字数为: %d \n",Out_NUm(head)); 
				break;
				case 4:
					printf("本文的全部总字数为: %d \n",Out_Text(head));
				break;
				case 5:
					printf("请输入统计的字符串:\n");
					scanf("%s",&st); 
					printf("%s在文本中出现的次数为: %d \n",st,Search_Strings(head,st));
					printf("\n");
				break;
				case 6:
					printf("请输入删除的字符串：\n"); 
					scanf("%s",&ss);
					head = Del_Strings(head,ss);
					printf("删除%s后的文本为:\n",ss);
					OutPut(head);
				break;
				case 7:
					printf("-----请选择文本的输入方式------\n"); 
				break;
				default:printf("-----您的输入不合法,请重新输入!------\n"); continue;
			}
		break;
		}
	}
}
