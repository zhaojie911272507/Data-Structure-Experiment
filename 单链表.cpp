#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;			//���嵥����Ľ������ 
	struct LNode *next;	//ÿ�������һ������Ԫ�� 
}LNode,*LinkList;		//ָ��ָ����һ�����
//��ʼ��һ��������(��ͷ���)
bool InitList(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));//����һ��ͷ���
	if(L==NULL)		//�ڴ治�㣬����ʧ��
		return false;
	L->next=NULL;	//ͷ���֮����ʱ��û�н�� 
	return true;	 
} 

//�ڵ�i��λ�ò���Ԫ��e����ͷ���)
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
