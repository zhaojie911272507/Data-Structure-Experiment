#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define MaxInt 32767    //权值的最大值
#define MVNum 100       //最大顶点数

//邻接矩阵存储结构定义
typedef struct{
	char vexs[MVNum];         //存放顶点的数组
	int arcs[MVNum][MVNum];    //存放邻接矩阵的数组
	int vexnum,arcnum;         //顶点数和边（弧）数
}AMGraph;    

//边（弧）结点结构定义
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	int weight;	
}ArcNode;

//顶点类型定义
typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum];    //顶点数组类型定义

//邻接表结构定义
typedef struct{
	AdjList vertices;    //顶点数组
	int vexnum,arcnum;   //顶点数和边（弧）数
}ALGraph;

//顺序队列结构定义
typedef struct{
	int front;      //队头
	int rear;       //队尾
	char base[MVNum];   //存放队列元素的数组
}SqQueue;

bool visited[MVNum];   //存放图中顶点访问标志的数组

//初始化队列
void InitQueue(SqQueue &Q)
{
	Q.front=Q.rear=0;
}

//判断队列Q是否为空，为空返回true，非空返回false
bool QueueEmpty(SqQueue Q)
{
	if(Q.rear==Q.front )
		return true;
	else
		return false;
}

//入队操作，将n插入顺序队列Q的尾部
void EnQueue(SqQueue &Q,int n)
{
	if(Q.rear-Q.front==MVNum)  //队满时，不能执行入队操作
		exit(-1);
	else
	{
		Q.base[Q.rear]=n;
		Q.rear++;
	}
}

//出队操作，删除队列Q的队头元素，被删元素用n返回
void DeQueue(SqQueue &Q,int &n)
{
	if(QueueEmpty(Q))     //若队列为空，不能执行出队操作
		exit(-1);
	else
	{
		n=Q.base [Q.front];
		Q.front++;
	}
}

//在以邻接表方式存储的图G中，查找值为ch的顶点的位置
int LocateVex(ALGraph G,char ch)
{
	//请同学们在此处补充该操作
	for(int i=0;i<G.arcnum;i++)
		if(G.vertices[i].data==ch) return i;
	return -1;//代码补充完整后，请修改此行代码，返回值为ch的顶点的位置
}

//以邻接表为存储结构，创建无向图G
void CreateUDG_AL(ALGraph &G)
{
	//请同学们在此处补充完整该操作
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

//输出图G的邻接表 
void PrintALGraph(ALGraph G)
{
	//请同学们在此处补充完整该操作
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

//在以邻接矩阵方式存储的图G中，查找值为ch的顶点的位置
int LocateVex1(AMGraph G,char ch)
{
	//请同学们在此处补充该操作
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vexs[i]==ch) return i;
	return -1;//代码补充完整后，请修改此行代码，返回值为ch的顶点的位置
}

//以邻接矩阵为存储结构，创建有向图G
void CreateDG_AM(AMGraph &G)
{
	//请同学们在此处补充该操作
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

//输出有向图G的信息，包括顶点数，弧数，顶点集合及邻接矩阵 
void PrintGraphInfo(AMGraph G)
{
	cout<<"顶点数、边数为:";
	cout<<G.vexnum<<"  "<<G.arcnum<<endl;       
	cout<<"顶点集合为:"<<endl;
	cout<<"{ "; 
	for(int i=0;i<G.vexnum;i++)
	{
		cout<<G.vexs[i]<<"  ";
	}
	cout<<"}"<<endl;
	cout<<"邻接矩阵为:"<<endl;
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

//从图中的第v个顶点出发，深度遍历图G（以邻接表为存储结构）
void DFS(ALGraph G,int v)
{
	//请同学们在此处补充该操作
	
	
	

}

//深度遍历图G
void DFSTraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vexnum ;v++)   //初始化所有顶点的访问标志位false
		visited[v]=false;
	for(v=0;v<G.vexnum ;v++)   //逐一检查每个顶点的访问标志，找一个未被访问过的顶点v为出发点，对图G进行深度遍历
	{
		if(visited[v]==false)
			DFS(G,v);
	}
}

//从图中的第v个顶点出发，广度遍历图G（以邻接表为存储结构）
void BFS(ALGraph G,int v)
{
	SqQueue Q;      //Q为顺序队列
	ArcNode *p;
	int w,u;
	InitQueue(Q);     //初始化队列Q
	cout<<G.vertices[v].data<<" ";    //输出第v个顶点
	visited[v]=true;                   //设置第v个顶点的访问标志
	EnQueue(Q,v);                      //将第v个顶点入队
	
	while(!QueueEmpty(Q))
	{
		//请同学们在此处补充剩余操作
		
		
		

	}	
}

//广度遍历图G
void BFSTraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vexnum ;v++)     //初始化所有顶点的访问标志位false
		visited[v]=false;
	for(v=0;v<G.vexnum ;v++)     //逐一检查每个顶点的访问标志，找一个未被访问过的顶点v为出发点，对图G进行广度遍历
	{
		if(visited[v]==false)
			BFS(G,v);
	}
}


//                        以下内容为选作（求最短路径，课下完成）
//*********************************************************************************************

//以邻接矩阵为存储结构，创建有向网G
void CreateDN_AM(AMGraph &G)
{
	//请同学们在此处补充该操作
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

//使用迪杰斯特拉算法求第v0个顶点到其它顶点的最短路径
void ShortestPath_DIJ(AMGraph G,int v0)
{
	int D[MVNum],Path[MVNum],i,v,w,min;  //数组D存储源点到其它顶点的最短路径长度,Path数组存放每个顶点的前驱顶点
	bool S[MVNum];    //每个顶点是否已求得最短路径的标志存放在数组S中
	//初始化三个数组
	for(v=0;v<G.vexnum ;v++)
	{
		//请同学们在此处根据注释，补充该循环




	}
	//将第v0个顶点设置为源点
	S[v0]=true;
	D[v0]=0;
	//循环G.vexnum-1次,求第v0个顶点到图中其它顶点的最短距离
	for(i=1;i<G.vexnum ;i++)
	{
		//寻找距离源点最近的第v个顶点
		//请同学们在此处根据注释，补充该操作





		
		S[v]=true;      //将第v个顶点加入到S中，S表示已求得最短路径的顶点集合
		//更新源点到其它顶点的最短距离
		for(w=0;w<G.vexnum ;w++)
		{
			//请同学们在此处根据注释，补充该循环




		}//for(w)
	}//for(i)
	
	//输出源点到其它顶点的最短路径及路径长度
	for(i=1;i<G.vexnum ;i++)
	{
		cout<<"顶点"<<G.vexs [v0]<<"到顶点"<<G.vexs [i]<<"的最短路径长度为"<<D[i]<<",路径为：";
		//从第i个顶点回溯，输出第i个顶点到源点的最短路径
		//请同学们在此处根据注释，补充该操作，输出源点到其它顶点的最短路径





	}
}


int main() 
{
	ALGraph G;   //图G使用邻接表为存储结构 
	AMGraph G1,G2;   //G1为有向网，G2为有向图，均使用邻接矩阵为存储结构 
	char ch;
	int k;
    //以下操作完成无向图G的创建(基于邻接表存储方式)、输出G的信息 
	cout<<"以下操作完成无向图G的创建(基于邻接表存储方式)、输出G的信息"<<endl;
	CreateUDG_AL(G);     //创建无向图G
	cout<<"无向图G的邻接表为："<<endl; 
	PrintALGraph(G);
	
	cout<<"图G的深度遍历序列为:";
	DFSTraverse(G);       //深度优先遍历图G
	cout<<endl;
	cout<<"图G的广度遍历序列为:";
	BFSTraverse(G);        //广度优先遍历图G
	cout<<endl<<endl;
	
	//以下操作完成有向图G2的创建(基于邻接矩阵存储方式)、输出G2的信息（包括顶点信息和邻接矩阵等） 
	cout<<"以下操作完成有向图G2的创建(基于邻接矩阵存储方式)、输出G2的信息"<<endl;
	rewind(stdin);
	CreateDG_AM(G2);     //创建有向图G2
	cout<<"有向图G2的信息为："<<endl;
	PrintGraphInfo(G2); 
	  	

	//以下操作完成有向网G1的创建(基于邻接矩阵存储方式),并在G1中求最短路径
	cout<<endl<<"****************************************************************************"<<endl;
	cout<<"以下操作完成有向网G1的创建(基于邻接矩阵存储方式),并在G1中求最短路径"<<endl;
	CreateDN_AM(G1);    //创建有向网G1
	cout<<"请输入源点："<<endl;
	cin>>ch;                  //输入源点     
	k=LocateVex1(G1,ch);       //求源点在G1中的位置k
	ShortestPath_DIJ(G1,k);    //使用迪杰斯特拉算法求第k个顶点到其它顶点的最短路径
	return 0;
}

