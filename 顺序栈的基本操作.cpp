#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define MaxSize 10//定义栈中元素的最大个数
typedef struct{
	int data[MaxSize];//静态数组存放栈中的元素
	int top; 		  //栈顶元素 
}SqStack;
 //初始化栈
 void InitStack(SqStack &S){
 	S.top=-1;		//也可以S.top=0 
 } 
 //判断栈空
 bool StackEmpty(SqStack S){
 	if(S.top==-1)	//栈空
	 return true;
	else			//不空 
	 return false; 
 } 
 //新元素入栈
 bool Push(SqStack &S,ElemType x){
 	if(S.top==MaxSize-1)	//栈满，报错
	 return  false;
	 S.top=S.top+1;		//指针先加1
	 S.data[S.top]=x;	//新元素入栈
	 					//上两句等价S.data[++S.top]=x 
	 return true; 
 } 
 //出栈操作
 bool Pop(SqStack &S,int &x){
 	if(S.top==-1)	//栈空，报错 
	 return false;
	x=S.data[S.top];//栈顶元素先出栈
	S.top=S.top-1;//指针再减 1
				  //上两句等价x=S.data[S.top--] 
	return true; 
 } 
 //读栈顶元素
 bool GetTop(SqTack S,ElemType &x){
 	if(S.top==-1)	//栈空，报错 
 		return false;
 	x=S.data[S.top];//x记录栈顶元素 
 	return true;
 } 
