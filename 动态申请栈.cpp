#include<iostream.h>
#include<stdlib.h>
 
#define MAXSIZE 100 //˳��ջ��ʼʱ����Ĵ洢�ռ䳤��

typedef struct {
	char *base;		//ջ��ָ�룬ջ��Ԫ��Ϊ�ַ�
	char *top;		//ջ��ָ��
	int stacksize;	//ջ���õ�������� 
}SqStack;

//��ʼ��˳��ջS
void InitStack(SqStack &S){
	S.base=(char *)malloc(MAXSIZE*sizeof(char));//ΪS����洢�ռ䣬Ҳ����ʹ������ע�͵������ �� 
	//S.base=new char[MAXSIZE];
	if(!S.base) exit(-1);
	S.top=S.base;//��ջʱ��s.top�� s.base��ָ��ջ��
	S.stacksize=MAXSIZE;//��ʼ��ջ���������ΪMAXSIZE 

} 
//��ջ��������˳��ջS��ջ��S��ջ��������Ԫ��e������ɹ�������true�� ����ʧ�ܣ�����false
bool Push(SqStack &S,char e){
	
	return true; 
} 

//��ջ������ɾ��˳��ջS��ջ��Ԫ�أ���ɾԪ���ò���e���أ�ɾ���ɹ�����������true��ɾ��ʧ�ܣ���������false
bool Pop(SqStack &S,char &e){
	
	
	return true;
} 

//ȡ˳��ջS��ջ��Ԫ�أ��ò���e����ȡ�õ�ջ��Ԫ��
bool GetTop(SqStack S,char &e){
	
	
	return true;
} 
//��˳��ջS�ĳ���
int StackLength(SqStack S){
	
	return 1;

}

//���˳��ջS�е�Ԫ�أ���ջ����ջ����˳�������
void PrintStack(SqStack S){
	char *p;
	for(p=S.base;p<S.top;p++){
		cout<<*p<<" ";//Ԫ��֮���������ո�ָ� 
	}
	cout<<endl; 
} 
//�����˵�
void showmenu(){
	cout<<"*******************************"<<endl;
	cout<<"1����ջ 		2����ջ 	3�����ջ�е�Ԫ��"<<endl;
	cout<<"4��ȡջ��Ԫ�� 	5���˳�"<<endl; 
} 

int main(){
	SqStack S;//����˳��ջ����S
	int k;
	char e; 
	bool flag;
	InitStack(S);//��ʼ��˳��ջS
	cout<<"˳��ջS��ʼ���ɹ�"<<endl;
	
	//ѭ����ʾ�˵������˳��ջ��һϵ�в���
	do{
		showmenu();
		cout<<"��ѡ��Ҫִ�еĲ������"<<endl;
		cin>>k;//k��ʾ�û�ѡ��Ĳ������
		switch(k){
			case 1:		//ִ����ջ���� 
				cout<<"��������ջԪ�ص�ֵ"endl;
				cin>>e;	//����Ҫ���뵽ջ������ֵ
				flag=Push(S,e);//ִ����ջ������flag��ʾ��ջ�����������Ϊtrue����Ϊfalse
				if(flag)	//����ջ�����ɹ�
					cout<<"��ջ�����ɹ�"<<endl; 
				 else 
				 	cout<<"ջ��������ջ����ʧ��"<<endl;
				break;
				case 2://ִ�г�ջ���� 
					flag=Pop(S,e);//ִ�г�ջ��������ɾջ��Ԫ�ص�ֵ��e���أ�flag��ʾ��ջ�����������Ϊtrue����Ϊfalse��
				if(flag)	//����ջ�����ɹ�
					cout<<"��ջ�����ɹ�����ɾջ��Ԫ��Ϊ��"<<endl;
				else
					cout<<"ջ�ѿգ�����ִ�г�ջ����"<<endl;	 
		 		break; 
		 		case 3://���˳��ջ�ĳ��ȼ�ջ�е�Ԫ��
				 	cout<<"��ǰջ�ĳ���Ϊ��"<<StackLength(S)<<",ջ��Ԫ��Ϊ����ջ�׵�ջ�����򣩣�"<<endl;
					 PrintStack(S);//���ѭ������Q�е�Ԫ��
					 break; 
				case 4://���ջ��Ԫ��
					if(GetTop)
						cout<<"ջ��Ԫ��Ϊ��"<<e<<endl;
					else
						cout<<"ջ�ѿգ�û��ջ��Ԫ��"<<endl;
					break; 
		}
	} while(k<5);
	return 1;
}




