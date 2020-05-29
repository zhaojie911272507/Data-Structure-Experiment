#include <iostream.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 5    //ѭ�����г�ʼ��ʱ����Ĵ洢�ռ䳤��

typedef struct{
	char *base;   //�洢�ռ��ַ�������д洢��Ԫ�����ַ�
	int front;    //��ͷָ��
	int rear;   //��βָ��
}SqQueue;       //ѭ�����нṹ

//��ʼ��ѭ������Q
void InitQueue(SqQueue &Q)
{
	Q.base  =(char *)malloc(MAXSIZE*sizeof(char));   //ΪQ����洢�ռ�,Ҳ����ʹ������ע�͵������
	//Q.base =new char[MAXSIZE];
	if(!Q.base  ) exit(-1);
	Q.front =Q.rear =0;        //�ն�ʱ��front��rear��Ϊ0
}

//��Ӳ�������ѭ������Q�Ķ�β������Ԫ��e������ɹ�������true,����ʧ�ܣ�����false
bool EnQueue(SqQueue &Q, char e)
{
	//��ͬѧ���ڴ˴��Ѹò�������������������
	




	return true;
}

//���Ӳ�����ɾ��ѭ������Q�Ķ�ͷԪ�أ���ɾԪ���ò���e���أ�ɾ���ɹ�����������true,ɾ��ʧ�ܣ���������false
bool DeQueue(SqQueue &Q,char &e)
{
	//��ͬѧ���ڴ˴��Ѹò�������������������





	return true;
}

//ȡѭ������Q�Ķ�ͷԪ�أ��ò���e����ȡ�õĶ�ͷԪ��
bool GetHead(SqQueue Q,char &e)
{
	//��ͬѧ���ڴ˴��Ѹò�������������������
	





	return true;
}

//ȡѭ������Q�Ķ�βԪ�أ��ò���e����ȡ�õĶ�βԪ��
bool GetTail(SqQueue Q,char &e)
{
	//��ͬѧ���ڴ˴��Ѹò�������������������
	





	return true;
}


//���ѭ������Q�е�Ԫ�أ��Ӷ�ͷ����β��˳�������
void PrintQueue(SqQueue Q)
{
	int i;
	if(Q.front <=Q.rear )   //��front<=rear,�����Ԫ�����±�front~rear-1��Χ��
	{
		for(i=Q.front ;i<Q.rear ;i++)
		{
			cout<<Q.base [i]<<"  ";   //Ԫ��֮���������ո�ָ�
		}
		cout<<endl;
	}
	else   //��front>rear,�����Ԫ�����±�front~MAXSIZE-1��0~rear-1��Χ��
	{
		for(i=Q.front ;i<MAXSIZE;i++)
			cout<<Q.base [i]<<"  ";
		for(i=0;i<Q.rear ;i++)
			cout<<Q.base [i]<<"  ";
		cout<<endl;
	}
}

//��ѭ������Q�ĳ���
int QueueLength(SqQueue Q)
{
	

	return 1;
}

//�����˵�
void showmenu()
{	
	cout<<"*****************************************************************"<<endl;
	cout<<"1�����          2������         3���������Ԫ��"<<endl;
	cout<<"4��ȡ��ͷԪ��    5��ȡ��βԪ��   6���˳�"<<endl;
}

int main()
{
	SqQueue Q;       //����ѭ������Q
	int k; 
	char e;
	bool flag;
	InitQueue(Q);    //��ʼ��ѭ������Q
	cout<<"ѭ������Q��ʼ���ɹ�"<<endl;
	
	//ѭ����ʾ�˵������ѭ�����е�һϵ�в���
	do{
		showmenu();    
		cout<<"��ѡ��Ҫִ�еĲ������"<<endl;
		cin>>k;    //k��ʾ�û�ѡ��Ĳ������
		switch(k)
		{
		case 1:    //ִ����Ӳ���
			cout<<"���������Ԫ�ص�ֵ"<<endl;
			cin>>e;      //����Ҫ���뵽��β����ֵ
			flag=EnQueue(Q,e);   //ִ����Ӳ�����,flag��ʾ��ջ�����������Ϊtrue,��Ϊfalse
			if(flag)       //����Ӳ����ɹ�
				cout<<"��Ӳ����ɹ�"<<endl;
			else
				cout<<"������������Ӳ���ʧ�ܣ�"<<endl;
			break;
		case 2:   //ִ�г��Ӳ���
			flag=DeQueue(Q,e);     //ִ�г��Ӳ�������ɾ��ͷԪ�ص�ֵ��e���أ�flag��ʾ��ջ�����������Ϊtrue,��Ϊfalse
			if(flag)       //�����Ӳ����ɹ�
				cout<<"���Ӳ����ɹ�����ɾ��ͷԪ��Ϊ��"<<e<<endl;  //�����ɾ��ͷԪ�ص�ֵ
			else
				cout<<"�����ѿգ�����ִ�г��Ӳ�����"<<endl;
			break;
		case 3:   //������еĳ��ȼ������е�Ԫ��
			cout<<"��ǰ���г���Ϊ��"<<QueueLength(Q)<<",����Ԫ��Ϊ���Ӷ�ͷ����β���򣩣�"<<endl;
			PrintQueue(Q);      //���ѭ������Q�е�Ԫ��
			break;

		case 4:    //�����ͷԪ��
			if(GetHead(Q,e))
				cout<<"��ͷԪ��Ϊ��"<<e<<endl;
			else
				cout<<"��ǰ����Ϊ�ն��У�û�ж�ͷԪ��"<<endl;
			break;
		case 5:   //�����βԪ��
			if(GetTail(Q,e))
				cout<<"��βԪ��Ϊ��"<<e<<endl;
			else
				cout<<"��ǰ����Ϊ�ն��У�û�ж�βԪ��"<<endl;
			break;
		}//switch

	}while(k<6);	
	return 1;
}
