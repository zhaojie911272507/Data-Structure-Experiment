#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX_TREE_SIZE 100
typedef struct {
	int data;
	int parent;        //˫��λ����
} PTNode;

/*˫�ױ�ʾ�����ṹ*/
typedef struct {
	PTNode node[MAX_TREE_SIZE];
	int count;        //����λ�úͽڵ����
} PTree;


/*���ĺ����ֵܱ�ʾ���ṹ����*/
typedef struct node {
	int data;
	struct node *firstchild;
	struct node *rightsib;
} BTNode,*BTree;
void init_ptree(PTree *tree) {
	tree->count=-1;
}

//��ʼ�������(�����ֵܱ�ʾ��)
BTNode GetTreeNode(int x) {
	BTNode t;
	t.data=x;
	t.firstchild=t.rightsib=NULL;
	return t;
}

//����ǰ�����(�ݹ�)
void preorder(BTNode *T) {
	if(T!=NULL) {
		printf("%d ",T->data);
		preorder(T->firstchild);
		preorder(T->rightsib);
	}
}

//����ǰ�����(�ǵݹ�)
void preorder2(PTree T) {
	int i;
	for(i=0; i<T.count; i++) {
		printf("%d ",T.node[i]);
	}
}


//���������(�ݹ�)
void inoeder(BTNode *T) {
	if(T!=NULL) {
		inoeder(T->firstchild);
		printf("%d ",T->data);
		inoeder(T->rightsib);
	}
}

//���������(�ǵݹ�)
void inoeder2(PTree T) {
	int i;
	for(i=T.count-1; i>=0; i--) {
		printf("%d ",T.node[i]);
	}

}

//��α���
void level(PTree T) {
	int i;
	for(i=0; i<T.count; i++) {
		printf("%d ",T.node[i]);
	}

}

//ˮƽ���������
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


//�����
void print_ptree(PTree tree) {
	int i;
	printf("    ���    ���    ˫��\n");
	for(i=0; i<=tree.count; i++) {
		printf("%8d%8d%8d",i,tree.node[i].data,tree.node[i].parent);
		printf("\n");
	}
}


/*��˫�ױ�ʾ��������*/
PTree CreatTree(PTree T) {
	int i=1;
	int fa,ch;
	PTNode p;
	for(i=1; ch!=-1; i++) {
		printf("�����%d���:\n",i);
		scanf("%d,%d",&fa,&ch);
		printf("\n");
		p.data=ch;
		p.parent=fa;
		T.count++;
		T.node[T.count].data = p.data;
		T.node[T.count].parent = p.parent;
	}
	printf("\n");
	printf("�������������������:\n");
	print_ptree(T);
	return T;
}
/*һ����ת���ɶ�����*/
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

/*���˵�*/
void Menu() {
	printf("=================���˵�=======================\n");
	printf("***����1-------------��˫�׷�����һ��һ����***\n");
	printf("***����2-------------����ǰ�����(�ݹ�)*******\n");
	printf("***����3-------------���ĺ������(�ݹ�)*******\n");
	printf("***����4-------------����ǰ�����(�ǵݹ�)*****\n");
	printf("***����5-------------���ĺ������(�ǵݹ�)*****\n");
	printf("***����6-------------�����ķǵݹ����*******\n");
	printf("***����0-------------�˳�����*****************\n");
	printf("==============================================\n");
	printf("������ִ�е�ָ��:");
}

/*���˵�*/
void Menu2() {
	printf("*****************���˵�*******************\n");
	printf("***9-------------�������˵���������*******\n");
	printf("***0-------------�˳�����*****************\n");
}

/*������*/
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
			printf("����һ����,�����������������:\n");
			printf("�����㷽ʽ:˫������,��������(��һ�����˫������Ϊ-1�������-1,-1����)\n����:-1,1  1,3\n");
			T=CreatTree(T);
			Tree=change(T);
			printf("һ����ת���ɶ�����������:\n");
			PrintBTree(Tree,i);
			getchar();
			break;

		case  2:
			printf("����ǰ�����(�ݹ�):\n");
			preorder(Tree);
			printf("\n");
			break;

		case  3:
			printf("���ĺ������(�ݹ�):\n");
			inoeder(Tree);
			printf("\n");
			break;

		case  4:
			printf("����ǰ�����(�ǵݹ�):\n");
			preorder2(T);
			printf("\n");
			break;

		case  5:
			printf("���ĺ������(�ǵݹ�):\n");
			inoeder2(T);
			printf("\n");
			break;

		case  6:
			printf("���Ĳ�α���:\n");
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

