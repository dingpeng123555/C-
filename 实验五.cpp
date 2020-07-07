/*算法1：采用顺序存储结构创建静态查找表，对查找表进行顺序查找和改进的顺序查找，并对其查找效率进行比较；
算法2：采用顺序存储结构创建静态查找表--有序表，对有序表进行二分查找
*/
#include<stdio.h>
#include<stdlib.h>
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
typedef int KeyType;
typedef struct{
 	KeyType key;
}ElemType;
typedef struct{
	ElemType *elem; 
	int length;
}SSTable;
int create(SSTable *ST)
{//创建静态表
 int i,n;
 printf("请输入你要创建的表的长度：\n");
 scanf("%d",&n);
 ST->elem =(ElemType *)malloc((n+1)*sizeof(ElemType));
 if(!ST->elem )
 return 0;
 printf("请输入%d个数据(若采用二分法查找关键字，则顺序输入)。\n",n);
 for(i=1;i<=n;i++)
 {
  scanf("%d",&ST->elem [i].key);
 }
 ST->length =n;
 return 1;
 } 
int search_seq(SSTable ST,KeyType key)
{
	int i=1;
	ElemType *p;
	while(i<=ST.length&&!EQ(ST.elem[i].key,key))
	++i;
	if(i<=ST.length)
	return i;
	else
	return 0;
	}
int search_seq2(SSTable ST,KeyType key)
{
	int i;
	ST.elem[0].key=key;
	for(i=ST.length;!EQ(ST.elem[i].key,key);--i);
	return i;
}
int search_bin(SSTable ST,KeyType key)
{
	int low=1;
	int high=ST.length;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(EQ(key,ST.elem[mid].key))
		return mid;
		else if(LT(key,ST.elem[mid].key))
			high=mid-1;
		else low=mid+1;
		
	}
	return 0;
}//search_bin
int main()
 {
  int i,time;
  SSTable ST;
  KeyType key;
  printf("请输入创建表的类型（0.无序表，1.有序表）：\n");
  scanf("%d",&time);
  create(&ST); 
  printf("创建成功！\n");
  printf("请输入需查找的关键字：\n");
  scanf("%d",&key);
  if(time==0)
  {
   printf("顺序查找关键字结果为：\n");
   i=search_seq(ST,key);
   if(i==0)
   {
    printf("查找失败,表中无此元素\n");
   }
   else
   {
    printf("查找成功！\n");
    printf("位置是%d\n",i);
   }
   printf("改进算法顺序查找关键字结果为：\n");
   i=search_seq2(ST,key);
   if(i==0)
   {
    printf("查找失败,表中无此元素\n");
   }
   else
   {
    printf("查找成功！\n");
    printf("位置是%d\n",i);
   }
  }
  else
  {
  printf("二分查找关键字结果为：\n");
   i=search_bin(ST,key);
   if(i==0)
   {
    printf("查找失败,表中无此元素\n");
   }
   else
   {
    printf("查找成功！\n");
    printf("位置是%d\n",i);
   } 
  }
 }
