/******************
date:2020-05-15
author:段鹏辉
categories: 数据结构
*******************/

#include "head.h"
#include <iostream>
#include <iomanip>
//采用邻接矩阵法表示有向图
Status CreateDigraph(AMGraph& G)
{
	cout << "输入最大顶点数和最大边数：" << endl;
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << "输入顶点信息：";
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	VerTexType v1, v2; //VerTexType为顶点的默认数据类型
	int w;     //设权值为int
	for (int k = 0; k < G.arcnum; k++)
	{
		cout << "分别输入有向边的起点和终点以及权值：";
		cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);  //确定v1,v2在G中的位置，即在顶点数组中的下标
		G.arcs[i][j] = w;
	}
	//对矩阵做输出
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			cout <<setw(10)<< left << G.arcs[i][j];
		}
		cout << endl;
	}
	return 1;
}
//采用邻接矩阵表示法创建无向网
Status CreateUDN(AMGraph& G)
{//采用邻接矩阵表示法,创建无向网G
	cout << "输入最大顶点数和最大边数：" << endl;
	cin >> G.vexnum >> G.arcnum;  //输入最大顶点数和最大边数
	for (int i = 0; i < G.vexnum; ++i)
	{
		cout << "输入顶点信息：";
		cin >> G.vexs[i];   //依次输入点的信息
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = MaxInt;           //初始化邻接矩阵，边的权值均置为极大值MaxInt
		}
	}
	VerTexType v1, v2;//VerTexType为顶点的默认数据类型
	int w;    
	for (int k = 0; k < G.vexnum; k++)
	{
		cout << "输入v1,v2,w：";
		cin >> v1 >> v2 >> w; //输入一条边依附的顶点及权值
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);  //确定v1,v2在G中的位置，即在顶点数组中的下标
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
	//对矩阵做输出
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			cout << setw(10) << left << G.arcs[i][j];
		}
		cout << endl;
	}
	return OK;
}
//确定点在顶点数组中的位置
//存在返回下标，不存在则返回-1
Status LocateVex(AMGraph G, VerTexType v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (v == G.vexs[i])
			return i;
	}
	cout << v << "不在G中" << endl;
	return -1;
}


//采用邻接表创建有向图
Status CreateDigraph(ALGraph& G)
{
	cout << "输入总的顶点数和边数：" << endl;
	cin >> G.vexnum >> G.arcnum; //输入总的顶点数和边数
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << "请输入顶点：" << endl;
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; k++)
	{
		VerTexType v1, v2;
		int w;
		cout << "请输入边的两点和边权：";
		cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		ArcNode* p1 = new ArcNode;
		p1->adjvex = j;
		p1->info = w;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;
	}
	return OK;
}

//利用邻接表表示法创建无向图
Status CreateUDG(ALGraph& G)
{
	cout << "输入总的顶点数和边数：" << endl;
	cin >> G.vexnum >> G.arcnum; //输入总的顶点数和边数
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << "请输入顶点：" << endl;
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; k++)
	{
		char v1, v2;
		cout << "请输入边的两点：";
		cin >> v1 >> v2;
		int i =LocateVex(G, v1);
		int j = LocateVex(G, v2);
		ArcNode *p1 = new ArcNode;
		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;
		ArcNode* p2 = new ArcNode;
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return OK;
}
//确定点在顶点数组中的位置
//存在返回下标，不存在则返回-1
Status LocateVex(ALGraph G, VerTexType v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (v == G.vertices[i].data)
			return i;
	}
	cout << v << "不在G中" << endl;
	return -1;
}
/**********************
*     图的遍历		***
**********************/
bool visted[MVNum];
//深度遍历连通图
//用于邻接矩阵
void DFS_AM(AMGraph G, int v)
{//从第v个顶点出发
	cout << G.vexs[v];
	visted[v] = true;
	for (int w = 0; w < G.vexnum; w++)
	{
		if ((G.arcs[v][w] != 0) && (!visted[w])) DFS_AM(G, w);
	}
}
//用于邻接表
void DFS_AL(ALGraph G, int v)
{
	cout << G.vertices[v].data;
	visted[v] = true;
	ArcNode *p = G.vertices[v].firstarc;
	while (p != NULL)
	{
		int w = p->adjvex;
		if(!visted[w]) DFS_AL(G, w);
		p = p->nextarc;
	}
}

//广度优先
void BFS_AM()
{

}
//Dijkstra最短路径算法
void ShortestPath_DIJ(AMGraph G, int v0)
{
	int n = G.vexnum;
	bool *S = new bool[MVNum];
	int* D = new int;
	int* Path = new int;
	for (int  v = 0; v < n; v++)
	{
		S[v] = false;
		D[v] = G.arcs[v0][v];
		if (D[v] < MaxInt) Path[v] = v0;
		else Path[v] = -1;  //如果v0和v之间无弧，则将v的前驱置为-1
	}
	S[v0] = true;
	D[v0] = 0;
	
	for (int i = 1; i < n; ++i)
	{
		int min = MaxInt;
		int v;
		for (int w = 0; w < n;++w)
		{
			if (!S[w] && D[w] < min) {
				v = w;
				min = D[w];
			}
		}
		S[v] = true;
		for (int w = 0; w < n; w++)
		{
			if (!S[w] && (D[v] + G.arcs[v][w] < D[w]))
			{
				D[w] = D[v] + G.arcs[v][w];
				Path[w] = v;
			}
		}

	}
}