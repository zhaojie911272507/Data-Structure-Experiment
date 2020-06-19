#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX_TREE_SIZE 100
typedef struct {
	int data;
	int parent;        //双亲位置域
} PTNode;

/*双亲表示法树结构*/
typedef struct {
	PTNode node[MAX_TREE_SIZE];
	int count;        //根的位置和节点个数
} PTree;


/*树的孩子兄弟表示结点结构定义*/
typedef struct node {
	int data;
	struct node *firstchild;
	struct node *rightsib;
} BTNode,*BTree;
void init_ptree(PTree *tree) {
	tree->count=-1;
}

//初始化树结点(孩子兄弟表示法)
BTNode GetTreeNode(int x) {
	BTNode t;
	t.data=x;
	t.firstchild=t.rightsib=NULL;
	return t;
}

//树的前序遍历(递归)
void preorder(BTNode *T) {
	if(T!=NULL) {
		printf("%d ",T->data);
		preorder(T->firstchild);
		preorder(T->rightsib);
	}
}

//树的前序遍历(非递归)
void preorder2(PTree T) {
	int i;
	for(i=0; i<T.count; i++) {
		printf("%d ",T.node[i]);
	}
}


//树后序遍历(递归)
void inoeder(BTNode *T) {
	if(T!=NULL) {
		inoeder(T->firstchild);
		printf("%d ",T->data);
		inoeder(T->rightsib);
	}
}

//树后序遍历(非递归)
void inoeder2(PTree T) {
	int i;
	for(i=T.count-1; i>=0; i--) {
		printf("%d ",T.node[i]);
	}

}

//层次遍历
void level(PTree T) {
	int i;
	for(i=0; i<T.count; i++) {
		printf("%d ",T.node[i]);
	}

}

//水平输出二叉树
void PrintBTree(BTNode *root,int level) {
	int i;
	if(root!=NULL) {
		PrintBTree(root->rightsib,level+1);
		for(i=1; i<=8*level; i++)
			printf(" ");
		printf("-------%d\n",root->data);
		PrintBTree(root->firstchild,level+1);
	}
}


//输出树
void print_ptree(PTree tree) {
	int i;
	printf("    序号    结点    双亲\n");
	for(i=0; i<=tree.count; i++) {
		printf("%8d%8d%8d",i,tree.node[i].data,tree.node[i].parent);
		printf("\n");
	}
}


/*用双亲表示法创建树*/
PTree CreatTree(PTree T) {
	int i=1;
	int fa,ch;
	PTNode p;
	for(i=1; ch!=-1; i++) {
		printf("输入第%d结点:\n",i);
		scanf("%d,%d",&fa,&ch);
		printf("\n");
		p.data=ch;
		p.parent=fa;
		T.count++;
		T.node[T.count].data = p.data;
		T.node[T.count].parent = p.parent;
	}
	printf("\n");
	printf("创建的树具体情况如下:\n");
	print_ptree(T);
	return T;
}
/*一般树转换成二叉树*/
BTNode *change(PTree T) {
	int i,j=0;
	BTNode p[MAX_TREE_SIZE];
	BTNode *ip,*is,*ir,*Tree;
	ip=(BTNode *)malloc(sizeof(BTNode));
	is=(BTNode *)malloc(sizeof(BTNode));
	ir=(BTNode *)malloc(sizeof(BTNode));
	Tree=(BTNode *)malloc(sizeof(BTNode));
	for(i=0; i<T.count; i++) {
		p[i]=GetTreeNode(T.node[i].data);
	}
	for(i=1; i<T.count; i++) {
		ip=&p[i];
		is=&p[j];
		while(T.node[i].parent!=is->data) {
			j++;
			is=&p[j];

		}
		if(!(is->firstchild)) {
			is->firstchild=ip;
			ir=ip;
		} else {
			ir->rightsib=ip;
			ir=ip;
		}
	}
	Tree=&p[0];
	return Tree;

}

/*主菜单*/
void Menu() {
	printf("=================主菜单=======================\n");
	printf("***输入1-------------以双亲法创建一棵一般树***\n");
	printf("***输入2-------------树的前序遍历(递归)*******\n");
	printf("***输入3-------------树的后序遍历(递归)*******\n");
	printf("***输入4-------------树的前序遍历(非递归)*****\n");
	printf("***输入5-------------树的后序遍历(非递归)*****\n");
	printf("***输入6-------------层次序的非递归遍历*******\n");
	printf("***输入0-------------退出程序*****************\n");
	printf("==============================================\n");
	printf("请输入执行的指令:");
}

/*副菜单*/
void Menu2() {
	printf("*****************副菜单*******************\n");
	printf("***9-------------返回主菜单继续操作*******\n");
	printf("***0-------------退出程序*****************\n");
}

/*主函数*/
int main() {
	int i=0,c1,c2;
	PTree T;
	BTNode *Tree;
	init_ptree(&T);
loop:
	Menu();
	scanf("%d",&c1);
	switch(c1) {
		case  1:
			printf("建立一般树,依次输入各个结点情况:\n");
			printf("输入结点方式:双亲数据,整型数据(第一个结点双亲数据为-1，最后以-1,-1结束)\n例子:-1,1  1,3\n");
			T=CreatTree(T);
			Tree=change(T);
			printf("一般树转换成二叉树后的情况:\n");
			PrintBTree(Tree,i);
			getchar();
			break;

		case  2:
			printf("树的前序遍历(递归):\n");
			preorder(Tree);
			printf("\n");
			break;

		case  3:
			printf("树的后序遍历(递归):\n");
			inoeder(Tree);
			printf("\n");
			break;

		case  4:
			printf("树的前序遍历(非递归):\n");
			preorder2(T);
			printf("\n");
			break;

		case  5:
			printf("树的后序遍历(非递归):\n");
			inoeder2(T);
			printf("\n");
			break;

		case  6:
			printf("树的层次遍历:\n");
			level(T);
			printf("\n");
			break;

		case  0:
			exit(1);
			break;
	}
	Menu2();
	scanf("%d",&c2);
	if(c2==9)
		goto loop;
	else if(c2==0)
		exit(1);

}

