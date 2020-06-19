#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define MaxSize 100    //˳����ʼ��ʱ����Ĵ洢�ռ䳤�� 
typedef struct {
	int elem[MaxSize];    		//ָʾ��̬���������ָ��
	int length;           //˳���ĵ�ǰ����
} SqList;                 //˳�������Ͷ���
//��������--��ʼ��һ��˳���
void InitList(SqList &L) {
	for(int i=0; i<MaxSize; i++)
		L.elem[i]=0;    //����������Ԫ������ΪĬ�ϳ�ʼֵ
	L.length=0;         //˳����ʼ����Ϊ0
}
//��˳���L��������ݣ�������ʹ��[1,100]�ڵ�����������˳���L������n��ʾҪ�������� ��������
void CreateList(SqList &L,int n) {
	int i;
	srand(time(0));//�����������
	for(i=0; i<n; i++) { //��˳���L�����n��[1,100]�ڵ��������
		L.elem[i]=rand()%100+1;
	}
	L.length=n;//�޸�˳���L�ĳ���
}
//���˳���L�е�Ԫ��
void PrintList(SqList L) {
	int i;
	for(i=0; i<L.length; i++) {
		cout<<L.elem[i]<<" ";
	}
	cout<<endl;
}
//ȡָ��Ԫ�أ���λ����
int GetElem(SqList L,int i) {
	return L.elem[i-1];
}

//��˳���L�в���Ԫ��e��λ�ã����ҳɹ�������e��L�е�λ��
int LocateElem(SqList L,int e) {
	int i;
	for(i=0; i<L.length; i++)
		if(L.elem[i]==e)
			return i+1;//�����±�Ϊi��Ԫ��ֵ����e��������λ��i+1
	return 0;		//�˳�ѭ����˵������ʧ��
}

//��˳���L�ĵ�i��Ԫ��ǰ����һ����Ԫ��e������ɹ�������true������ʧ�ܣ�����false
bool ListInsert(SqList &L,int i,int e) {
	if(i<1||i>L.length+1)//�ж�i�ķ�Χ�Ƿ���Ч
		return false;
	if(L.length>=MaxSize)//��ǰ�洢�ռ����������ܲ���
		return false;
	for(int j=L.length; j>=i; j--)
		L.elem[j]=L.elem[j-1];
	L.elem[i-1]=e;		//��λ��i������e
	L.length++;			//���ȼ�һ
	return true;
}
//ɾ����L�е�i��λ�õ�Ԫ��
bool ListDelete(SqList &L,int i,int &e) {
	if(i<1||i>L.length)		//�ж�i�ķ�Χ�Ƿ���Ч
		return false;
	e=L.elem[i-1];			//����ɾ����Ԫ�ظ�ֵ��e
	for(int j=i; j<L.length; j++)
		L.elem[j-1]=L.elem[j];
	L.length--;				//���Ա��ȼ�1
	return true;
}
int main() {
	SqList L;		//����һ��˳��� ����˳������L
	int n,e,pos,flag;
	InitList(L);
	cout<<"˳���L��ʼ���ɹ�"<<endl;
	cout<<"������Ҫ��ɴ�����˳���ĳ���"<<endl;
	cin>>n;
	CreateList(L,n);
	cout<<"˳���L�����ɹ�,����Ԫ��Ϊ��"<<endl;
	PrintList(L);
	cout<<"������Ҫ���ҵ�Ԫ�ص�ֵ";
	cin>>e;
	pos=LocateElem(L,e);
	cout<<"Ԫ��"<<e<<"�ڱ��е�λ��Ϊ"<<pos<<endl;
	cout<<"���������λ�ü������ֵ"<<endl;
	cin>>pos>>e;
	flag=ListInsert(L,pos,e);
	if(flag) {
		cout<<"��������ɹ�������Ԫ��Ϊ��"<<endl;
		PrintList(L);
	} else {
		cout<<"����ʧ�ܣ�"<<endl;
	}

	cout<<"������ɾ��Ԫ�ص�λ��"<<endl;
	cin>>pos;
	flag=ListDelete(L,pos,e);
	if(flag) {
		cout<<"ɾ�������ɹ�����ɾ��Ԫ��Ϊ��"<<e<<"����Ԫ��Ϊ��"<<endl;
		PrintList(L);
	} else
		cout<<"ɾ��λ�ô��󣬲���ʧ�ܣ�"<<endl;
	return 0;
}
