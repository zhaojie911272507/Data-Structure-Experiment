#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
using namespace std;
//��������ṹ
typedef struct BiTNode {
	char data;      //������,��Ž��ֵ
	struct BiTNode *lchild,*rchild;  //���Һ���ָ��
} BiTNode,*BiTree; // ��������

//���������������������У��������ַ�","��ʾ����������������
void creatbitree(BiTree &T) {
	//���ڴ˴�����ò���
	char chr;
	T=new BiTNode();
	T->lchild=NULL;
	T->rchild=NULL;

	cin>>chr;
	if(chr==',') {
		T=NULL;
		return;
	} else T->data=chr;
	creatbitree(T->lchild);
	creatbitree(T->rchild);
}

//�������������T
void inorder(BiTree T) {
	if(T) {
		//�����ע�����ݣ������油�����
		//�������T��������
		inorder(T->lchild);
		//���ʽ��T������ý���ֵ��
		cout<<T->data;
		//�������T��������
		inorder(T->rchild);
	}
}

//�������������T
void preorder(BiTree T) {
	if(T) {
		//�����ע�����ݣ������油�����
		//���ʽ��T������ý���ֵ��
		cout<<T->data;
		//�������T��������
		preorder(T->lchild);
		//�������T��������
		preorder(T->rchild);
	}
}

//�������������T
void postorder(BiTree T) {
	if(T) {
		//�����ע�����ݣ������油�����
		//�������T��������
		postorder(T->lchild);
		//�������T��������
		postorder(T->rchild);
		//���ʽ��T������ý���ֵ��
		cout<<T->data;
	}
}


//�ڶ�����T�в���ֵΪch�Ľ�㣬���ҳɹ�����������true,����������false
bool searchtree(BiTree T,char ch,BiTree &p) {
	if(T==NULL) {
		p=NULL;
		return false;
	} else {
		if(T->data ==ch) { //����ǰ���T��ֵ����ch�����ҳɹ�
			p=T;
			return true;
		} else {
			//��T���������в���ֵΪch�Ľ�㣬�����ҳɹ�������true
			//�����ע�Ͳ���˴�����
			if(searchtree(T->lchild,ch,p)==true) return true;

			//��T���������в�����ֵΪch�Ľ�㣬�������T���������в��ң����������������еĲ��ҽ��
			//�����ע�Ͳ���˴�����
			else if(searchtree(T->rchild,ch,p)==true) return true;

		}
	}
	return false;
}

//�������T�ĸ߶�
int Depth(BiTree T) {
	//���ڴ˴�����ò���
	if(T==NULL) return 0;
	else return(Depth(T->lchild)+1>Depth(T->rchild)+1?Depth(T->lchild):Depth(T->rchild)+1);
	return 0;  //����������Ϻ���ɾ�����д���
}

//�������T�н������
int NodeCount(BiTree T) {
	//���ڴ˴�����ò���
	if(T==NULL) return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
	//����������Ϻ���ɾ�����д���
}

//�������T��Ҷ�ӽ������
int LeafCount(BiTree T) {
	//���ڴ˴�����ò���
	if(T==NULL) return 0;
	else if(T->lchild==NULL&&T->rchild==NULL) return 1;
	else {
		int m,n;
		m=LeafCount(T->lchild);
		n=LeafCount(T->rchild);
		return m+n;
	}

	//return 0;  //����������Ϻ���ɾ�����д���
}

//�������T�ж�Ϊ1�ķ�֧�������
int Count(BiTree T) {
	//���ڴ˴�����ò���
	if(T==NULL) return 0;
	else if(T->lchild==NULL&&T->rchild!=NULL)
		return Count(T->rchild)+1;
	else if(T->lchild!=NULL&&T->rchild==NULL)
		return Count(T->lchild)+1;
	else return Count(T->lchild)+Count(T->rchild);
	//return 0;  //����������Ϻ���ɾ�����д���
}

//�������T�Ŀ�ȣ��������Ŀ��ָ���Ƕ����������н���������ֵ
int Width(BiTree T) {
	//���ڴ˴�����ò���
	int max=0;
	int wid=0;
	BiTree p;
	stack<BiTree> stc,s;
	stc.push(T);

	while(1) {
		if(stc.empty()) break;
		wid=0;
		while(!stc.empty()) {
			p=stc.top();
			if(p!=NULL) wid++;
			stc.pop();
			if(p->lchild!=NULL) s.push(p->lchild);
			if(p->rchild!=NULL) s.push(p->rchild);
		}
		if(wid>max) max=wid;
		while(!s.empty()) {
			p=s.top();
			s.pop();
			if(p!=NULL)
				stc.push(p);
		}
	}
	return max;
	//return 0;  //����������Ϻ���ɾ�����д���
}

//���㷨�Բ����˳������������еĽ�㣬�ս�����ַ�#��ʾ��������Ӧ�Ķ�������
//��ͬѧ�ǲ��Ĵ��㷨
BiTree CreateBiTree1() {
	BiTree root=NULL;
	int c=0,p=0;
	BiTNode *q[100],*s;
	char ch;
	cin>>ch;
	while(ch!='@') {
		if(ch!='#') {
			s=new BiTNode;
			if(!s) exit(-1);
			s->data =ch;
			s->lchild =NULL;
			s->rchild =NULL;
		} else
			s=NULL;
		q[c]=s;
		if(c==0) {
			root=s;
			c++;
		} else {
			if(q[p]==NULL) {
				p++;
				c++;
				cin>>ch;
				q[c]=NULL;
				c++;
			} else {
				if(c%2==1) {
					q[p]->lchild =s;
					c++;
				} else {
					q[p]->rchild =s;
					c++;
					p++;
				}//if(c%2==1)
			}//if(q[p]==NULL)
		}//if(c==0)
		cin>>ch;
	}//while
	return root;
}


int main() {
	BiTree T,p;       //TΪ��������Ҫ�����Ķ�������
	char ch;    //ch��ch1�ֱ��ʾ�ڶ�������������������Ҫ��ѯ�Ľ��
	bool t;
	p=new BiTNode;
	cout<<"������Ҫ�����Ķ��������������������룬�������ַ�','����"<<endl;
	creatbitree(T);  //��������Ķ������������У�������������T
	cout<<endl<<"����������Ϊ��";
	inorder(T);      //���������T�������������
	cout<<endl<<"����������Ϊ��";
	preorder(T);     //���������T�������������
	cout<<endl<<"����������Ϊ��";
	postorder(T);    //���������T�ĺ����������
	cout<<endl<<"�������ڶ�������Ҫ���ҵĽ�㣺";
	rewind(stdin);   //������뻺����
	cin>>ch;
	t=searchtree(T,ch,p);   //�ڶ�����T�в���ֵΪch1�Ľ��
	if(t) {
		cout<<endl<<"�ڶ������в��ҳɹ�";
		cout<<endl<<"�ý������Һ��ӷֱ�Ϊ��";
		if(p->lchild!=NULL&&p->rchild!=NULL)
			cout<<p->lchild->data<<"  "<<p->rchild->data;
		else if(p->lchild!=NULL&&p->rchild==NULL)
			cout<<p->lchild->data<<"  "<<",";
		else if(p->lchild==NULL&&p->rchild!=NULL)
			cout<<"��"<<" "<< p->rchild->data;
		else cout<<","<<" "<<",";
		//���ڴ˴��������ֵΪch�Ľ�㺢�ӵĲ���



	} else cout<<endl<<"�������в�����ֵΪ"<<ch<<"�Ľ��";
	cout<<endl<<"�ö������н������Ϊ"<<NodeCount(T);
	cout<<endl<<"Ҷ�ӽ�����Ϊ"<<LeafCount(T);
	cout<<endl<<"��Ϊ1�Ľ�����Ϊ"<<Count(T);
	cout<<endl<<"��Ϊ2�Ľ�����Ϊ"<<NodeCount(T)-Count(T)-LeafCount(T);
	cout<<endl<<"�������ĸ߶�Ϊ"<<Depth(T);


	return 0;

}

