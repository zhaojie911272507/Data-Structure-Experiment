#include <iostream.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 5    //循环队列初始化时分配的存储空间长度

typedef struct{
	char *base;   //存储空间基址，队列中存储的元素是字符
	int front;    //队头指针
	int rear;   //队尾指针
}SqQueue;       //循环队列结构

//初始化循环队列Q
void InitQueue(SqQueue &Q)
{
	Q.base  =(char *)malloc(MAXSIZE*sizeof(char));   //为Q分配存储空间,也可以使用下面注释掉的语句
	//Q.base =new char[MAXSIZE];
	if(!Q.base  ) exit(-1);
	Q.front =Q.rear =0;        //空队时，front和rear均为0
}

//入队操作，向循环队列Q的队尾插入新元素e，插入成功，返回true,插入失败，返回false
bool EnQueue(SqQueue &Q, char e)
{
	//请同学们在此处把该操作补充完整，并调试
	




	return true;
}

//出队操作，删除循环队列Q的队头元素，被删元素用参数e返回，删除成功，函数返回true,删除失败，函数返回false
bool DeQueue(SqQueue &Q,char &e)
{
	//请同学们在此处把该操作补充完整，并调试





	return true;
}

//取循环队列Q的队头元素，用参数e返回取得的队头元素
bool GetHead(SqQueue Q,char &e)
{
	//请同学们在此处把该操作补充完整，并调试
	





	return true;
}

//取循环队列Q的队尾元素，用参数e返回取得的队尾元素
bool GetTail(SqQueue Q,char &e)
{
	//请同学们在此处把该操作补充完整，并调试
	





	return true;
}


//输出循环队列Q中的元素（从队头到队尾的顺序输出）
void PrintQueue(SqQueue Q)
{
	int i;
	if(Q.front <=Q.rear )   //若front<=rear,则队列元素在下标front~rear-1范围内
	{
		for(i=Q.front ;i<Q.rear ;i++)
		{
			cout<<Q.base [i]<<"  ";   //元素之间用两个空格分隔
		}
		cout<<endl;
	}
	else   //若front>rear,则队列元素在下标front~MAXSIZE-1和0~rear-1范围内
	{
		for(i=Q.front ;i<MAXSIZE;i++)
			cout<<Q.base [i]<<"  ";
		for(i=0;i<Q.rear ;i++)
			cout<<Q.base [i]<<"  ";
		cout<<endl;
	}
}

//求循环队列Q的长度
int QueueLength(SqQueue Q)
{
	

	return 1;
}

//操作菜单
void showmenu()
{	
	cout<<"*****************************************************************"<<endl;
	cout<<"1、入队          2、出队         3、输出队列元素"<<endl;
	cout<<"4、取队头元素    5、取队尾元素   6、退出"<<endl;
}

int main()
{
	SqQueue Q;       //定义循环队列Q
	int k; 
	char e;
	bool flag;
	InitQueue(Q);    //初始化循环队列Q
	cout<<"循环队列Q初始化成功"<<endl;
	
	//循环显示菜单，完成循环队列的一系列操作
	do{
		showmenu();    
		cout<<"请选择要执行的操作序号"<<endl;
		cin>>k;    //k表示用户选择的操作序号
		switch(k)
		{
		case 1:    //执行入队操作
			cout<<"请输入入队元素的值"<<endl;
			cin>>e;      //输入要插入到队尾处的值
			flag=EnQueue(Q,e);   //执行入队操作，,flag表示入栈操作结果，或为true,或为false
			if(flag)       //若入队操作成功
				cout<<"入队操作成功"<<endl;
			else
				cout<<"队列已满，入队操作失败！"<<endl;
			break;
		case 2:   //执行出队操作
			flag=DeQueue(Q,e);     //执行出队操作，被删队头元素的值用e返回，flag表示出栈操作结果，或为true,或为false
			if(flag)       //若出队操作成功
				cout<<"出队操作成功，被删队头元素为："<<e<<endl;  //输出被删队头元素的值
			else
				cout<<"队列已空，不能执行出队操作！"<<endl;
			break;
		case 3:   //输出队列的长度及队列中的元素
			cout<<"当前队列长度为："<<QueueLength(Q)<<",队中元素为（从队头到队尾方向）："<<endl;
			PrintQueue(Q);      //输出循环队列Q中的元素
			break;

		case 4:    //输出队头元素
			if(GetHead(Q,e))
				cout<<"队头元素为："<<e<<endl;
			else
				cout<<"当前队列为空队列，没有队头元素"<<endl;
			break;
		case 5:   //输出队尾元素
			if(GetTail(Q,e))
				cout<<"队尾元素为："<<e<<endl;
			else
				cout<<"当前队列为空队列，没有队尾元素"<<endl;
			break;
		}//switch

	}while(k<6);	
	return 1;
}
