#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
using namespace std;
//二叉链表结构
typedef struct BiTNode {
	char data;      //数据域,存放结点值
	struct BiTNode *lchild,*rchild;  //左右孩子指针
} BiTNode,*BiTree; // 二叉链表

//输入二叉树的先序遍历序列（空树用字符","表示），创建二叉链表
void creatbitree(BiTree &T) {
	//请在此处补充该操作
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

//中序遍历二叉树T
void inorder(BiTree T) {
	if(T) {
		//请根据注释内容，在下面补充代码
		//中序遍历T的左子树
		inorder(T->lchild);
		//访问结点T（输出该结点的值）
		cout<<T->data;
		//中序遍历T的右子树
		inorder(T->rchild);
	}
}

//先序遍历二叉树T
void preorder(BiTree T) {
	if(T) {
		//请根据注释内容，在下面补充代码
		//访问结点T（输出该结点的值）
		cout<<T->data;
		//先序遍历T的左子树
		preorder(T->lchild);
		//先序遍历T的右子树
		preorder(T->rchild);
	}
}

//后序遍历二叉树T
void postorder(BiTree T) {
	if(T) {
		//请根据注释内容，在下面补充代码
		//后序遍历T的左子树
		postorder(T->lchild);
		//后序遍历T的右子树
		postorder(T->rchild);
		//访问结点T（输出该结点的值）
		cout<<T->data;
	}
}


//在二叉树T中查找值为ch的结点，查找成功，函数返回true,否则函数返回false
bool searchtree(BiTree T,char ch,BiTree &p) {
	if(T==NULL) {
		p=NULL;
		return false;
	} else {
		if(T->data ==ch) { //若当前结点T的值等于ch，查找成功
			p=T;
			return true;
		} else {
			//在T的左子树中查找值为ch的结点，若查找成功，返回true
			//请根据注释补充此处代码
			if(searchtree(T->lchild,ch,p)==true) return true;

			//若T的左子树中不存在值为ch的结点，则继续在T的右子树中查找，并返回在右子树中的查找结果
			//请根据注释补充此处代码
			else if(searchtree(T->rchild,ch,p)==true) return true;

		}
	}
	return false;
}

//求二叉树T的高度
int Depth(BiTree T) {
	//请在此处补充该操作
	if(T==NULL) return 0;
	else return(Depth(T->lchild)+1>Depth(T->rchild)+1?Depth(T->lchild):Depth(T->rchild)+1);
	return 0;  //操作补充完毕后，请删除该行代码
}

//求二叉树T中结点总数
int NodeCount(BiTree T) {
	//请在此处补充该操作
	if(T==NULL) return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
	//操作补充完毕后，请删除该行代码
}

//求二叉树T中叶子结点总数
int LeafCount(BiTree T) {
	//请在此处补充该操作
	if(T==NULL) return 0;
	else if(T->lchild==NULL&&T->rchild==NULL) return 1;
	else {
		int m,n;
		m=LeafCount(T->lchild);
		n=LeafCount(T->rchild);
		return m+n;
	}

	//return 0;  //操作补充完毕后，请删除该行代码
}

//求二叉树T中度为1的分支结点总数
int Count(BiTree T) {
	//请在此处补充该操作
	if(T==NULL) return 0;
	else if(T->lchild==NULL&&T->rchild!=NULL)
		return Count(T->rchild)+1;
	else if(T->lchild!=NULL&&T->rchild==NULL)
		return Count(T->lchild)+1;
	else return Count(T->lchild)+Count(T->rchild);
	//return 0;  //操作补充完毕后，请删除该行代码
}

//求二叉树T的宽度，二叉树的宽度指的是二叉树各层中结点数的最大值
int Width(BiTree T) {
	//请在此处补充该操作
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
	//return 0;  //操作补充完毕后，请删除该行代码
}

//该算法以层序的顺序输入二叉树中的结点，空结点用字符#表示，创建对应的二叉链表
//请同学们参阅此算法
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
	BiTree T,p;       //T为本程序中要操作的二叉链表
	char ch;    //ch和ch1分别表示在二叉树和线索二叉树中要查询的结点
	bool t;
	p=new BiTNode;
	cout<<"请输入要创建的二叉树，按先序序列输入，空树用字符','代替"<<endl;
	creatbitree(T);  //根据输入的二叉树先序序列，创建二叉链表T
	cout<<endl<<"中序遍历结果为：";
	inorder(T);      //输出二叉树T的中序遍历序列
	cout<<endl<<"先序遍历结果为：";
	preorder(T);     //输出二叉树T的先序遍历序列
	cout<<endl<<"后序遍历结果为：";
	postorder(T);    //输出二叉树T的后序遍历序列
	cout<<endl<<"请输入在二叉树中要查找的结点：";
	rewind(stdin);   //清空输入缓冲区
	cin>>ch;
	t=searchtree(T,ch,p);   //在二叉树T中查找值为ch1的结点
	if(t) {
		cout<<endl<<"在二叉树中查找成功";
		cout<<endl<<"该结点的左右孩子分别为：";
		if(p->lchild!=NULL&&p->rchild!=NULL)
			cout<<p->lchild->data<<"  "<<p->rchild->data;
		else if(p->lchild!=NULL&&p->rchild==NULL)
			cout<<p->lchild->data<<"  "<<",";
		else if(p->lchild==NULL&&p->rchild!=NULL)
			cout<<"，"<<" "<< p->rchild->data;
		else cout<<","<<" "<<",";
		//请在此处补充输出值为ch的结点孩子的操作



	} else cout<<endl<<"二叉树中不存在值为"<<ch<<"的结点";
	cout<<endl<<"该二叉树中结点总数为"<<NodeCount(T);
	cout<<endl<<"叶子结点个数为"<<LeafCount(T);
	cout<<endl<<"度为1的结点个数为"<<Count(T);
	cout<<endl<<"度为2的结点个数为"<<NodeCount(T)-Count(T)-LeafCount(T);
	cout<<endl<<"二叉树的高度为"<<Depth(T);


	return 0;

}

