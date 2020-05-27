#include <iostream.h>
#include <stdlib.h>
#include <time.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;       //�������ṹ

//��ʼ��������L
void InitList(LinkList &L)
{
	L =(LNode *)malloc(sizeof(LNode));   //����ͷ���洢�ռ�
	if(!L) exit(-1);
	L->next=NULL;   //��ʼ��L�ĳ���Ϊ0
}

//��巨����������ʹ��[1,100]�ڵ����������䵥����L,����n��ʾҪ�������伸������
void CreateList(LinkList &L,int n)
{
	int i;
	LNode *s,*r;
	r=L;
	srand(time(0));   //�������������
	for(i=0;i<n;i++)   //������L�����n��[1,100]�ڵ��������
	{
		s=new LNode;
		s->data =rand()%100+1;
		r->next =s;
		r=s;
	}
	r->next =NULL;   //���һ�����ָ������Ϊ��
}
//�жϵ������Ƿ�Ϊ�գ���ͷ��㣩 
bool Empty(LinkList){
	if(L->next==NULL)
		return true;
	else
		return false;
}
 
//ѡ��
//����һ��ֵ��������ĵ�����
void CreateList1(LinkList &L,int n)
{

}

//ѡ��
//ǰ�巨����������ʹ��[1,100]�ڵ����������䵥����L,����n��ʾҪ�������伸������
void CreateList2(LinkList &L,int n)
{
	LNodee *s;int x;
	L=(LinkList)malloc(sizeof(LNode));//����ͷ���
	L->next=NULL;//��ʼΪ������
	srand(time(0));   //�������������
	for(i=0;i<n;i++)   //������L�����n��[1,100]�ڵ��������
	{
		s=new LNode;
		s->data =rand()%100+1;
		s->next =L->next;//���½�������У�LΪͷָ�� 
		L->next=s;
	}
	return L; 
}

//���������L �е�Ԫ��
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


//�ڵ�����L �в���Ԫ��e��λ�ã����ҳɹ�������ָ��e��ָ��
LNode *LocateElem(LinkList L,int e)
{
	LNode *p;
	for(int r=p;r->next!=NULL;r++){
		if(r->next==e)
			return r->next;
	}

}


//�ڵ�����L�ĵ�i�����ǰ����һ����Ԫ��e������ɹ�������true,����ʧ�ܣ�����false
bool ListInsert(LinkList &L,int i,ElemType e){
	if(i<1)
		return false;
	LNode *p;//ָ��pָ��ǰɨ�赽�Ľ��
	int j=0; //��ǰpָ����ǵڼ������ 
	p=L;	 //Lָ��ͷ��㣬ͷ����ǵ�0�����
	while(P!-NULL && j<i-1){//ѭ���ҵ���i-1�����
		p=p->next;
		j++; 
	}
	if(p==NULL)//iֵ���Ϸ�
		return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s-next=p->next;
	p->next=s;//�����s����p
	return true; 
} 

//ɾ��������L�е�i ����㣬��ɾԪ���ò���e���أ�ɾ���ɹ�����������true,ɾ��ʧ�ܣ���������false
bool ListDelete(LinkList &L,int i,int &e)
{
	if(i<1)
		return false;
	LNode *p;	//ָ��pָ��ǰɨ�赽�Ľ��
	int j=0;//��ǰpָ����ǵڼ������
	p=L;//Lָ��ͷ��㣬ͷ����ǵ�0�����(��������) 
	while(p!=NULL && j<i-1){//ѭ���ҵ���i-1����� 
		p=p->next;
		j++;
	}
	if(p==NULL)//iֵ���Ϸ�
		return false;
	if(p->next==NULL)//��i-1�����֮�������������
	{
		return false;
	  }  
	LNode *q=p->next;//��qָ��ɾ�����
	e=q->data; 		 //��e����Ԫ�ص�ֵ 
	p->next=q->next;//��*q�������С��Ͽ��� 
	free(q);	//�ͷŽ��Ĵ洢�ռ� 
	return true;//ɾ���ɹ� 
}

int main()
{
	LinkList L;       //���嵥�����ͷָ��L
	int n,e,pos,flag; 
	LNode *p;
	InitList(L);    //��ʼ��������L
	cout<<"������L��ʼ���ɹ�"<<endl;
	cout<<"������Ҫ�����ĵ�����ĳ���"<<endl;
	cin>>n;        //����n��ʾҪ���뵽�������е�Ԫ�ظ���
	CreateList(L,n);   //��L�����n���������
	cout<<"������L�����ɹ�������Ԫ��Ϊ��"<<endl;
	PrintList(L);      //���˳���L�е�Ԫ��
	cout<<"������Ҫ���ҵ�Ԫ�ص�ֵ"<<endl;
	cin>>e;           //����e��ʾҪ���ҵ�Ԫ��
	p=LocateElem(L,e);   //��L�в���Ԫ��e��λ�ã�p��ʾ���ҽ������ΪNULL����Ϊ��NULL
	if(p) cout<<"���ҳɹ�"<<endl;
	else cout<<"����û��ֵΪ"<<e<<"�Ľ��"<<endl;

	cout<<"���������λ�ü������ֵ"<<endl;
	cin>>pos>>e;      //������L�в���Ԫ�ص�λ�ü�ֵ
	flag=ListInsert(L,pos,e);   //�ڵ�����L�ĵ�pos��λ�ò���ֵe,flag��ʾ��������������Ϊtrue,��Ϊfalse
	if(flag)       //�жϲ�������Ƿ�ɹ�
	{
		cout<<"��������ɹ�������Ԫ��Ϊ��"<<endl;
		PrintList(L);     //�����������ɹ���L�е�ֵ
	}
	else
		cout<<"����ʧ�ܣ�"<<endl;

	cout<<"������ɾ��Ԫ�ص�λ��"<<endl;
	cin>>pos;       //����ɾ��λ��
	flag=ListDelete(L,pos,e);     //ɾ��������L�е�pos��Ԫ�أ���ɾԪ�ص�ֵ��e���أ�flag��ʾɾ�������������Ϊtrue,��Ϊfalse
	if(flag)       //�ж�ɾ�������Ƿ�ɹ�
	{
		cout<<"ɾ�������ɹ�����ɾԪ��Ϊ��"<<e<<"����Ԫ��Ϊ��"<<endl;  //�����ɾԪ�ص�ֵ
		PrintList(L);   //���ɾ�������ɹ���L�е�ֵ
	}
	else
		cout<<"ɾ��λ�ô��󣬲���ʧ�ܣ�"<<endl;
	
	return 1;
}

