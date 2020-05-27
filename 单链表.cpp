#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;			//定义单链表的结点类型 
	struct LNode *next;	//每个结点存放一个数据元素 
}LNode,*LinkList;		//指针指向下一个结点
//初始化一个单链表(带头结点)
bool InitList(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));//分配一个头结点
	if(L==NULL)		//内存不足，分配失败
		return false;
	L->next=NULL;	//头结点之后暂时还没有结点 
	return true;	 
} 

//在第i个位置插入元素e（带头结点)
bool ListInsert(LinkList &L,int i,ElemType e){
	if(i<1)
		return false;
	LNode *p;//指针p指向当前扫描到的结点
	int j=0; //当前p指向的是第几个结点 
	p=L;	 //L指向头结点，头结点是第0个结点
	while(P!-NULL && j<i-1){//循环找到第i-1个结点
		p=p->next;
		j++; 
	}
	if(p==NULL)//i值不合法
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s-next=p->next;
	p->next=s;//将结点s连到p
	return true; 
} 
