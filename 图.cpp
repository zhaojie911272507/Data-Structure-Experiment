#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define MaxInt 32767    //Ȩֵ�����ֵ
#define MVNum 100       //��󶥵���

//�ڽӾ���洢�ṹ����
typedef struct{
	char vexs[MVNum];         //��Ŷ��������
	int arcs[MVNum][MVNum];    //����ڽӾ��������
	int vexnum,arcnum;         //�������ͱߣ�������
}AMGraph;    

//�ߣ��������ṹ����
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	int weight;	
}ArcNode;

//�������Ͷ���
typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum];    //�����������Ͷ���

//�ڽӱ�ṹ����
typedef struct{
	AdjList vertices;    //��������
	int vexnum,arcnum;   //�������ͱߣ�������
}ALGraph;

//˳����нṹ����
typedef struct{
	int front;      //��ͷ
	int rear;       //��β
	char base[MVNum];   //��Ŷ���Ԫ�ص�����
}SqQueue;

bool visited[MVNum];   //���ͼ�ж�����ʱ�־������

//��ʼ������
void InitQueue(SqQueue &Q)
{
	Q.front=Q.rear=0;
}

//�ж϶���Q�Ƿ�Ϊ�գ�Ϊ�շ���true���ǿշ���false
bool QueueEmpty(SqQueue Q)
{
	if(Q.rear==Q.front )
		return true;
	else
		return false;
}

//��Ӳ�������n����˳�����Q��β��
void EnQueue(SqQueue &Q,int n)
{
	if(Q.rear-Q.front==MVNum)  //����ʱ������ִ����Ӳ���
		exit(-1);
	else
	{
		Q.base[Q.rear]=n;
		Q.rear++;
	}
}

//���Ӳ�����ɾ������Q�Ķ�ͷԪ�أ���ɾԪ����n����
void DeQueue(SqQueue &Q,int &n)
{
	if(QueueEmpty(Q))     //������Ϊ�գ�����ִ�г��Ӳ���
		exit(-1);
	else
	{
		n=Q.base [Q.front];
		Q.front++;
	}
}

//�����ڽӱ�ʽ�洢��ͼG�У�����ֵΪch�Ķ����λ��
int LocateVex(ALGraph G,char ch)
{
	//��ͬѧ���ڴ˴�����ò���
	for(int i=0;i<G.arcnum;i++)
		if(G.vertices[i].data==ch) return i;
	return -1;//���벹�����������޸Ĵ��д��룬����ֵΪch�Ķ����λ��
}

//���ڽӱ�Ϊ�洢�ṹ����������ͼG
void CreateUDG_AL(ALGraph &G)
{
	//��ͬѧ���ڴ˴����������ò���
	char v1,v2;
	int i,j,k;
	ArcNode *p1,*p2;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;i++){
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}
	for(k=0;k<G.arcnum;k++){
		cin>>v1>>v2;
		i=LocateVex(G,v1);j=LocateVex(G,v2);
		if(i==-1||j==-1) continue;
		p1=new ArcNode;
		p1->adjvex=j;
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;
		
		p2=new ArcNode;
		p2->adjvex=i;
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;
	}
}

//���ͼG���ڽӱ� 
void PrintALGraph(ALGraph G)
{
	//��ͬѧ���ڴ˴����������ò���
	ArcNode *p;
	for(int i=0;i<G.vexnum;i++){
		cout<<G.vertices[i].data<<"->";
		p=G.vertices[i].firstarc;
		while(p!=NULL){
			cout<<p->adjvex<<"->";
			p=p->nextarc;
		}
		cout<<"NULL\n";
	}
}

//�����ڽӾ���ʽ�洢��ͼG�У�����ֵΪch�Ķ����λ��
int LocateVex1(AMGraph G,char ch)
{
	//��ͬѧ���ڴ˴�����ò���
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==ch) return i;
	return -1;//���벹�����������޸Ĵ��д��룬����ֵΪch�Ķ����λ��
}

//���ڽӾ���Ϊ�洢�ṹ����������ͼG
void CreateDG_AM(AMGraph &G)
{
	//��ͬѧ���ڴ˴�����ò���
	int i,j,k,w;
	char v1,v2;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;i++)
		cin>>G.vexs[i];
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=MaxInt;
	for(k=0;k<G.arcnum;k++){
		cin>>v1>>v2;
		i=LocateVex1(G,v1);
		j=LocateVex1(G,v2);
		if(i!=-1&&j!=-1)
			G.arcs[i][j]=1;
	}
}

//�������ͼG����Ϣ�����������������������㼯�ϼ��ڽӾ��� 
void PrintGraphInfo(AMGraph G)
{
	cout<<"������������Ϊ:";
	cout<<G.vexnum<<"  "<<G.arcnum<<endl;       
	cout<<"���㼯��Ϊ:"<<endl;
	cout<<"{ "; 
	for(int i=0;i<G.vexnum;i++)
	{
		cout<<G.vexs[i]<<"  ";
	}
	cout<<"}"<<endl;
	cout<<"�ڽӾ���Ϊ:"<<endl;
	for(int i=0;i<G.vexnum;i++)
	{
	
		for(int j=0;j<G.vexnum;j++)
		{
			printf("%-8d",G.arcs[i][j]);
			//cout<<G.arcs[i][j]<<"   ";
		}
		cout<<endl;
	}
	     
}

//��ͼ�еĵ�v�������������ȱ���ͼG�����ڽӱ�Ϊ�洢�ṹ��
void DFS(ALGraph G,int v)
{
	//��ͬѧ���ڴ˴�����ò���
	
	
	

}

//��ȱ���ͼG
void DFSTraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vexnum ;v++)   //��ʼ�����ж���ķ��ʱ�־λfalse
		visited[v]=false;
	for(v=0;v<G.vexnum ;v++)   //��һ���ÿ������ķ��ʱ�־����һ��δ�����ʹ��Ķ���vΪ�����㣬��ͼG������ȱ���
	{
		if(visited[v]==false)
			DFS(G,v);
	}
}

//��ͼ�еĵ�v�������������ȱ���ͼG�����ڽӱ�Ϊ�洢�ṹ��
void BFS(ALGraph G,int v)
{
	SqQueue Q;      //QΪ˳�����
	ArcNode *p;
	int w,u;
	InitQueue(Q);     //��ʼ������Q
	cout<<G.vertices[v].data<<" ";    //�����v������
	visited[v]=true;                   //���õ�v������ķ��ʱ�־
	EnQueue(Q,v);                      //����v���������
	
	while(!QueueEmpty(Q))
	{
		//��ͬѧ���ڴ˴�����ʣ�����
		
		
		

	}	
}

//��ȱ���ͼG
void BFSTraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vexnum ;v++)     //��ʼ�����ж���ķ��ʱ�־λfalse
		visited[v]=false;
	for(v=0;v<G.vexnum ;v++)     //��һ���ÿ������ķ��ʱ�־����һ��δ�����ʹ��Ķ���vΪ�����㣬��ͼG���й�ȱ���
	{
		if(visited[v]==false)
			BFS(G,v);
	}
}


//                        ��������Ϊѡ���������·����������ɣ�
//*********************************************************************************************

//���ڽӾ���Ϊ�洢�ṹ������������G
void CreateDN_AM(AMGraph &G)
{
	//��ͬѧ���ڴ˴�����ò���
	int i,j,k,w;
	char v1,v2;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;i++)
		cin>>G.vexs[i];
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=MaxInt;
	for(k=0;k<G.arcnum;k++){
		cin>>v1>>v2>>w;
		i=LocateVex1(G,v1);
		j=LocateVex1(G,v2);
		if(i!=-1&&j!=-1)
			G.arcs[i][j]=w;
	}
}

//ʹ�õϽ�˹�����㷨���v0�����㵽������������·��
void ShortestPath_DIJ(AMGraph G,int v0)
{
	int D[MVNum],Path[MVNum],i,v,w,min;  //����D�洢Դ�㵽������������·������,Path������ÿ�������ǰ������
	bool S[MVNum];    //ÿ�������Ƿ���������·���ı�־���������S��
	//��ʼ����������
	for(v=0;v<G.vexnum ;v++)
	{
		//��ͬѧ���ڴ˴�����ע�ͣ������ѭ��




	}
	//����v0����������ΪԴ��
	S[v0]=true;
	D[v0]=0;
	//ѭ��G.vexnum-1��,���v0�����㵽ͼ�������������̾���
	for(i=1;i<G.vexnum ;i++)
	{
		//Ѱ�Ҿ���Դ������ĵ�v������
		//��ͬѧ���ڴ˴�����ע�ͣ�����ò���





		
		S[v]=true;      //����v��������뵽S�У�S��ʾ��������·���Ķ��㼯��
		//����Դ�㵽�����������̾���
		for(w=0;w<G.vexnum ;w++)
		{
			//��ͬѧ���ڴ˴�����ע�ͣ������ѭ��




		}//for(w)
	}//for(i)
	
	//���Դ�㵽������������·����·������
	for(i=1;i<G.vexnum ;i++)
	{
		cout<<"����"<<G.vexs [v0]<<"������"<<G.vexs [i]<<"�����·������Ϊ"<<D[i]<<",·��Ϊ��";
		//�ӵ�i��������ݣ������i�����㵽Դ������·��
		//��ͬѧ���ڴ˴�����ע�ͣ�����ò��������Դ�㵽������������·��





	}
}


int main() 
{
	ALGraph G;   //ͼGʹ���ڽӱ�Ϊ�洢�ṹ 
	AMGraph G1,G2;   //G1Ϊ��������G2Ϊ����ͼ����ʹ���ڽӾ���Ϊ�洢�ṹ 
	char ch;
	int k;
    //���²����������ͼG�Ĵ���(�����ڽӱ�洢��ʽ)�����G����Ϣ 
	cout<<"���²����������ͼG�Ĵ���(�����ڽӱ�洢��ʽ)�����G����Ϣ"<<endl;
	CreateUDG_AL(G);     //��������ͼG
	cout<<"����ͼG���ڽӱ�Ϊ��"<<endl; 
	PrintALGraph(G);
	
	cout<<"ͼG����ȱ�������Ϊ:";
	DFSTraverse(G);       //������ȱ���ͼG
	cout<<endl;
	cout<<"ͼG�Ĺ�ȱ�������Ϊ:";
	BFSTraverse(G);        //������ȱ���ͼG
	cout<<endl<<endl;
	
	//���²����������ͼG2�Ĵ���(�����ڽӾ���洢��ʽ)�����G2����Ϣ������������Ϣ���ڽӾ���ȣ� 
	cout<<"���²����������ͼG2�Ĵ���(�����ڽӾ���洢��ʽ)�����G2����Ϣ"<<endl;
	rewind(stdin);
	CreateDG_AM(G2);     //��������ͼG2
	cout<<"����ͼG2����ϢΪ��"<<endl;
	PrintGraphInfo(G2); 
	  	

	//���²������������G1�Ĵ���(�����ڽӾ���洢��ʽ),����G1�������·��
	cout<<endl<<"****************************************************************************"<<endl;
	cout<<"���²������������G1�Ĵ���(�����ڽӾ���洢��ʽ),����G1�������·��"<<endl;
	CreateDN_AM(G1);    //����������G1
	cout<<"������Դ�㣺"<<endl;
	cin>>ch;                  //����Դ��     
	k=LocateVex1(G1,ch);       //��Դ����G1�е�λ��k
	ShortestPath_DIJ(G1,k);    //ʹ�õϽ�˹�����㷨���k�����㵽������������·��
	return 0;
}

