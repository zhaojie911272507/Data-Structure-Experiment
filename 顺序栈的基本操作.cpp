#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define MaxSize 10//����ջ��Ԫ�ص�������
typedef struct{
	int data[MaxSize];//��̬������ջ�е�Ԫ��
	int top; 		  //ջ��Ԫ�� 
}SqStack;
 //��ʼ��ջ
 void InitStack(SqStack &S){
 	S.top=-1;		//Ҳ����S.top=0 
 } 
 //�ж�ջ��
 bool StackEmpty(SqStack S){
 	if(S.top==-1)	//ջ��
	 return true;
	else			//���� 
	 return false; 
 } 
 //��Ԫ����ջ
 bool Push(SqStack &S,ElemType x){
 	if(S.top==MaxSize-1)	//ջ��������
	 return  false;
	 S.top=S.top+1;		//ָ���ȼ�1
	 S.data[S.top]=x;	//��Ԫ����ջ
	 					//������ȼ�S.data[++S.top]=x 
	 return true; 
 } 
 //��ջ����
 bool Pop(SqStack &S,int &x){
 	if(S.top==-1)	//ջ�գ����� 
	 return false;
	x=S.data[S.top];//ջ��Ԫ���ȳ�ջ
	S.top=S.top-1;//ָ���ټ� 1
				  //������ȼ�x=S.data[S.top--] 
	return true; 
 } 
 //��ջ��Ԫ��
 bool GetTop(SqTack S,ElemType &x){
 	if(S.top==-1)	//ջ�գ����� 
 		return false;
 	x=S.data[S.top];//x��¼ջ��Ԫ�� 
 	return true;
 } 
