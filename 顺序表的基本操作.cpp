#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define MaxSize 100    //顺序表初始化时分配的存储空间长度 
typedef struct {
	int elem[MaxSize];    		//指示动态分配数组的指针
	int length;           //顺序表的当前长度
} SqList;                 //顺序表的类型定义
//基本操作--初始化一个顺序表
void InitList(SqList &L) {
	for(int i=0; i<MaxSize; i++)
		L.elem[i]=0;    //将所有数据元素设置为默认初始值
	L.length=0;         //顺序表初始长度为0
}
//向顺序表L中填充数据，本例中使用[1,100]内的随机整数填充顺序表L，参数n表示要向表中填充 几个数据
void CreateList(SqList &L,int n) {
	int i;
	srand(time(0));//设置随机种子
	for(i=0; i<n; i++) { //向顺序表L中填充n个[1,100]内的随机整数
		L.elem[i]=rand()%100+1;
	}
	L.length=n;//修改顺序表L的长度
}
//输出顺序表L中的元素
void PrintList(SqList L) {
	int i;
	for(i=0; i<L.length; i++) {
		cout<<L.elem[i]<<" ";
	}
	cout<<endl;
}
//取指定元素，按位查找
int GetElem(SqList L,int i) {
	return L.elem[i-1];
}

//在顺序表L中查找元素e的位置，查找成功，返回e在L中的位序
int LocateElem(SqList L,int e) {
	int i;
	for(i=0; i<L.length; i++)
		if(L.elem[i]==e)
			return i+1;//数组下标为i的元素值等于e，返回其位序i+1
	return 0;		//退出循环，说明查找失败
}

//在顺序表L的第i个元素前插入一个新元素e，插入成功，返回true，插入失败，返回false
bool ListInsert(SqList &L,int i,int e) {
	if(i<1||i>L.length+1)//判断i的范围是否有效
		return false;
	if(L.length>=MaxSize)//当前存储空间已满，不能插入
		return false;
	for(int j=L.length; j>=i; j--)
		L.elem[j]=L.elem[j-1];
	L.elem[i-1]=e;		//在位置i处放入e
	L.length++;			//长度加一
	return true;
}
//删除表L中第i个位置的元素
bool ListDelete(SqList &L,int i,int &e) {
	if(i<1||i>L.length)		//判断i的范围是否有效
		return false;
	e=L.elem[i-1];			//将被删除的元素赋值给e
	for(int j=i; j<L.length; j++)
		L.elem[j-1]=L.elem[j];
	L.length--;				//线性表长度减1
	return true;
}
int main() {
	SqList L;		//声明一个顺序表 或定义顺序表变量L
	int n,e,pos,flag;
	InitList(L);
	cout<<"顺序表L初始化成功"<<endl;
	cout<<"请输入要完成创建的顺序表的长度"<<endl;
	cin>>n;
	CreateList(L,n);
	cout<<"顺序表L创建成功,表中元素为："<<endl;
	PrintList(L);
	cout<<"请输入要查找的元素的值";
	cin>>e;
	pos=LocateElem(L,e);
	cout<<"元素"<<e<<"在表中的位序为"<<pos<<endl;
	cout<<"请输入插入位置及插入的值"<<endl;
	cin>>pos>>e;
	flag=ListInsert(L,pos,e);
	if(flag) {
		cout<<"插入操作成功，表中元素为："<<endl;
		PrintList(L);
	} else {
		cout<<"插入失败！"<<endl;
	}

	cout<<"请输入删除元素的位置"<<endl;
	cin>>pos;
	flag=ListDelete(L,pos,e);
	if(flag) {
		cout<<"删除操作成功，被删除元素为："<<e<<"表中元素为："<<endl;
		PrintList(L);
	} else
		cout<<"删除位置错误，操作失败！"<<endl;
	return 0;
}
