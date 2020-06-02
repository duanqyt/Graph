/******************
date:2020-05-15
author:������
categories: ���ݽṹ
*******************/

#include "head.h"
#include <iostream>
#include <iomanip>
//�����ڽӾ��󷨱�ʾ����ͼ
Status CreateDigraph(AMGraph& G)
{
	cout << "������󶥵�������������" << endl;
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << "���붥����Ϣ��";
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	VerTexType v1, v2; //VerTexTypeΪ�����Ĭ����������
	int w;     //��ȨֵΪint
	for (int k = 0; k < G.arcnum; k++)
	{
		cout << "�ֱ���������ߵ������յ��Լ�Ȩֵ��";
		cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);  //ȷ��v1,v2��G�е�λ�ã����ڶ��������е��±�
		G.arcs[i][j] = w;
	}
	//�Ծ��������
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
//�����ڽӾ����ʾ������������
Status CreateUDN(AMGraph& G)
{//�����ڽӾ����ʾ��,����������G
	cout << "������󶥵�������������" << endl;
	cin >> G.vexnum >> G.arcnum;  //������󶥵�����������
	for (int i = 0; i < G.vexnum; ++i)
	{
		cout << "���붥����Ϣ��";
		cin >> G.vexs[i];   //������������Ϣ
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = MaxInt;           //��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt
		}
	}
	VerTexType v1, v2;//VerTexTypeΪ�����Ĭ����������
	int w;    
	for (int k = 0; k < G.vexnum; k++)
	{
		cout << "����v1,v2,w��";
		cin >> v1 >> v2 >> w; //����һ���������Ķ��㼰Ȩֵ
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);  //ȷ��v1,v2��G�е�λ�ã����ڶ��������е��±�
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
	//�Ծ��������
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
//ȷ�����ڶ��������е�λ��
//���ڷ����±꣬�������򷵻�-1
Status LocateVex(AMGraph G, VerTexType v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (v == G.vexs[i])
			return i;
	}
	cout << v << "����G��" << endl;
	return -1;
}


//�����ڽӱ�������ͼ
Status CreateDigraph(ALGraph& G)
{
	cout << "�����ܵĶ������ͱ�����" << endl;
	cin >> G.vexnum >> G.arcnum; //�����ܵĶ������ͱ���
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << "�����붥�㣺" << endl;
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; k++)
	{
		VerTexType v1, v2;
		int w;
		cout << "������ߵ�����ͱ�Ȩ��";
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

//�����ڽӱ��ʾ����������ͼ
Status CreateUDG(ALGraph& G)
{
	cout << "�����ܵĶ������ͱ�����" << endl;
	cin >> G.vexnum >> G.arcnum; //�����ܵĶ������ͱ���
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << "�����붥�㣺" << endl;
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; k++)
	{
		char v1, v2;
		cout << "������ߵ����㣺";
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
//ȷ�����ڶ��������е�λ��
//���ڷ����±꣬�������򷵻�-1
Status LocateVex(ALGraph G, VerTexType v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (v == G.vertices[i].data)
			return i;
	}
	cout << v << "����G��" << endl;
	return -1;
}
/**********************
*     ͼ�ı���		***
**********************/
bool visted[MVNum];
//��ȱ�����ͨͼ
//�����ڽӾ���
void DFS_AM(AMGraph G, int v)
{//�ӵ�v���������
	cout << G.vexs[v];
	visted[v] = true;
	for (int w = 0; w < G.vexnum; w++)
	{
		if ((G.arcs[v][w] != 0) && (!visted[w])) DFS_AM(G, w);
	}
}
//�����ڽӱ�
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

//�������
void BFS_AM()
{

}
//Dijkstra���·���㷨
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
		else Path[v] = -1;  //���v0��v֮���޻�����v��ǰ����Ϊ-1
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