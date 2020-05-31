#include<iostream.h>
#include<stdlib.h>
 
#define MAXSIZE 100 //顺序栈初始时分配的存储空间长度

typedef struct {
	char *base;		//栈底指针，栈中元素为字符
	char *top;		//栈顶指针
	int stacksize;	//栈可用的最大容量 
}SqStack;

//初始化顺序栈S
void InitStack(SqStack &S){
	S.base=(char *)malloc(MAXSIZE*sizeof(char));//为S分配存储空间，也可以使用下面注释掉的语句 、 
	//S.base=new char[MAXSIZE];
	if(!S.base) exit(-1);
	S.top=S.base;//空栈时，s.top和 s.base均指向栈底
	S.stacksize=MAXSIZE;//初始化栈的最大容量为MAXSIZE 

} 
//入栈操作，向顺序栈S的栈顶S的栈顶插入新元素e，插入成功，返回true， 插入失败，返回false
bool Push(SqStack &S,char e){
	
	return true; 
} 

//出栈操作，删除顺序栈S的栈顶元素，被删元素用参数e返回，删除成功。函数返回true，删除失败，函数返回false
bool Pop(SqStack &S,char &e){
	
	
	return true;
} 

//取顺序栈S的栈顶元素，用参数e返回取得的栈顶元素
bool GetTop(SqStack S,char &e){
	
	
	return true;
} 
//求顺序栈S的长度
int StackLength(SqStack S){
	
	return 1;

}

//输出顺序栈S中的元素（从栈顶到栈顶的顺序输出）
void PrintStack(SqStack S){
	char *p;
	for(p=S.base;p<S.top;p++){
		cout<<*p<<" ";//元素之间用两个空格分隔 
	}
	cout<<endl; 
} 
//操作菜单
void showmenu(){
	cout<<"*******************************"<<endl;
	cout<<"1、入栈 		2、出栈 	3、输出栈中的元素"<<endl;
	cout<<"4、取栈顶元素 	5、退出"<<endl; 
} 

int main(){
	SqStack S;//定义顺序栈变量S
	int k;
	char e; 
	bool flag;
	InitStack(S);//初始化顺序栈S
	cout<<"顺序栈S初始化成功"<<endl;
	
	//循环显示菜单，完成顺序栈的一系列操作
	do{
		showmenu();
		cout<<"请选择要执行的操作序号"<<endl;
		cin>>k;//k表示用户选择的操作序号
		switch(k){
			case 1:		//执行入栈操作 
				cout<<"请输入入栈元素的值"endl;
				cin>>e;	//输入要插入到栈顶处的值
				flag=Push(S,e);//执行入栈操作，flag表示入栈操作结果，或为true，或为false
				if(flag)	//若入栈操作成功
					cout<<"入栈操作成功"<<endl; 
				 else 
				 	cout<<"栈已满，入栈操作失败"<<endl;
				break;
				case 2://执行出栈操作 
					flag=Pop(S,e);//执行出栈操作，被删栈顶元素的值用e返回，flag表示出栈操作结果，或为true，或为false；
				if(flag)	//若出栈操作成功
					cout<<"出栈操作成功，被删栈顶元素为："<<endl;
				else
					cout<<"栈已空，不能执行出栈操作"<<endl;	 
		 		break; 
		 		case 3://输出顺序栈的长度及栈中的元素
				 	cout<<"当前栈的长度为："<<StackLength(S)<<",栈中元素为（从栈底到栈顶方向）："<<endl;
					 PrintStack(S);//输出循环队列Q中的元素
					 break; 
				case 4://输出栈顶元素
					if(GetTop)
						cout<<"栈顶元素为："<<e<<endl;
					else
						cout<<"栈已空，没有栈顶元素"<<endl;
					break; 
		}
	} while(k<5);
	return 1;
}




