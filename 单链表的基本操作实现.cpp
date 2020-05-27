#include <iostream.h>
#include <stdlib.h>
#include <time.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;       //单链表表结构

//初始化单链表L
void InitList(LinkList &L)
{
	L =(LNode *)malloc(sizeof(LNode));   //分配头结点存储空间
	if(!L) exit(-1);
	L->next=NULL;   //初始化L的长度为0
}

//后插法建表，本例中使用[1,100]内的随机整数填充单链表L,参数n表示要向表中填充几个数据
void CreateList(LinkList &L,int n)
{
	int i;
	LNode *s,*r;
	r=L;
	srand(time(0));   //设置随机数种子
	for(i=0;i<n;i++)   //向单链表L中填充n个[1,100]内的随机整数
	{
		s=new LNode;
		s->data =rand()%100+1;
		r->next =s;
		r=s;
	}
	r->next =NULL;   //最后一个结点指针域置为空
}
//判断单链表是否为空（带头结点） 
bool Empty(LinkList){
	if(L->next==NULL)
		return true;
	else
		return false;
}
 
//选做
//创建一个值递增有序的单链表
void CreateList1(LinkList &L,int n)
{

}

//选做
//前插法建表，本例中使用[1,100]内的随机整数填充单链表L,参数n表示要向表中填充几个数据
void CreateList2(LinkList &L,int n)
{
	LNodee *s;int x;
	L=(LinkList)malloc(sizeof(LNode));//创建头结点
	L->next=NULL;//初始为空链表
	srand(time(0));   //设置随机数种子
	for(i=0;i<n;i++)   //向单链表L中填充n个[1,100]内的随机整数
	{
		s=new LNode;
		s->data =rand()%100+1;
		s->next =L->next;//将新结点插入表中，L为头指针 
		L->next=s;
	}
	return L; 
}

//输出单链表L 中的元素
void PrintList(LinkList L)
{
	LNode *p=L->next ;
	while(p)
	{
		cout<<p->data <<"  ";
		p=p->next ;
	}
	cout<<endl;
}


//在单链表L 中查找元素e的位置，查找成功，返回指向e的指针
LNode *LocateElem(LinkList L,int e)
{
	LNode *p;
	for(int r=p;r->next!=NULL;r++){
		if(r->next==e)
			return r->next;
	}

}


//在单链表L的第i个结点前插入一个新元素e，插入成功，返回true,插入失败，返回false
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

//删除单链表L中第i 个结点，被删元素用参数e返回，删除成功，函数返回true,删除失败，函数返回false
bool ListDelete(LinkList &L,int i,int &e)
{
	if(i<1)
		return false;
	LNode *p;	//指针p指向当前扫描到的结点
	int j=0;//当前p指向的是第几个结点
	p=L;//L指向头结点，头结点是第0个结点(不存数据) 
	while(p!=NULL && j<i-1){//循环找到第i-1个结点 
		p=p->next;
		j++;
	}
	if(p==NULL)//i值不合法
		return false;
	if(p->next==NULL)//第i-1个结点之后已无其他结点
	{
		return false;
	  }  
	LNode *q=p->next;//令q指向被删除结点
	e=q->data; 		 //用e返回元素的值 
	p->next=q->next;//将*q结点从链中“断开” 
	free(q);	//释放结点的存储空间 
	return true;//删除成功 
}

int main()
{
	LinkList L;       //定义单链表的头指针L
	int n,e,pos,flag; 
	LNode *p;
	InitList(L);    //初始化单链表L
	cout<<"单链表L初始化成功"<<endl;
	cout<<"请输入要创建的单链表的长度"<<endl;
	cin>>n;        //变量n表示要输入到单链表中的元素个数
	CreateList(L,n);   //向L中填充n个随机整数
	cout<<"单链表L创建成功，表中元素为："<<endl;
	PrintList(L);      //输出顺序表L中的元素
	cout<<"请输入要查找的元素的值"<<endl;
	cin>>e;           //变量e表示要查找的元素
	p=LocateElem(L,e);   //在L中查找元素e的位置，p表示查找结果，或为NULL，或为非NULL
	if(p) cout<<"查找成功"<<endl;
	else cout<<"表中没有值为"<<e<<"的结点"<<endl;

	cout<<"请输入插入位置及插入的值"<<endl;
	cin>>pos>>e;      //输入向L中插入元素的位置及值
	flag=ListInsert(L,pos,e);   //在单链表L的第pos个位置插入值e,flag表示插入操作结果，或为true,或为false
	if(flag)       //判断插入操作是否成功
	{
		cout<<"插入操作成功，表中元素为："<<endl;
		PrintList(L);     //输出插入操作成功后，L中的值
	}
	else
		cout<<"插入失败！"<<endl;

	cout<<"请输入删除元素的位置"<<endl;
	cin>>pos;       //输入删除位置
	flag=ListDelete(L,pos,e);     //删除单链表L中第pos个元素，被删元素的值用e返回，flag表示删除操作结果，或为true,或为false
	if(flag)       //判断删除操作是否成功
	{
		cout<<"删除操作成功，被删元素为："<<e<<"表中元素为："<<endl;  //输出被删元素的值
		PrintList(L);   //输出删除操作成功后，L中的值
	}
	else
		cout<<"删除位置错误，操作失败！"<<endl;
	
	return 1;
}

