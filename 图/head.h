#ifndef _HEAD_H_
#define _HEAD_H_

using namespace std;
/************************
* 图的邻接矩阵存储表示 **
************************/
const int MaxInt = 32767; //表示极大值，即无穷
const int  MVNum = 100;   //表示最大的点个数
typedef char VerTexType;       //假定顶点的数据类型为char
typedef int ArcType;       //假定为int
typedef int Status;
#define OK 1;
typedef struct
{
	VerTexType vexs[MVNum];         //顶点表
	ArcType arcs[MVNum][MVNum];		//邻接矩阵
	int vexnum;		//图的当前点数
	int arcnum;		//图的当前边数
}AMGraph;

//采用邻接矩阵表示法创建无向网
Status CreateUDN(AMGraph &G);
//确定点在顶点数组中的位置
Status LocateVex(AMGraph G, VerTexType v1);
#endif // !_HEAD_H_
//采用邻接矩阵法表示有向图
Status CreateDigraph(AMGraph& G);

/*********************
* 图的邻接表表示法 ***
**********************/
//定义最大顶点数 const int MVNum = 100;
//定义其他信息类型 
typedef int OtherInfo;
typedef struct ArcNode    //边结点
{
	int adjvex;			//存Vi的相关结点在顶点数组中的下标
	struct ArcNode* nextarc;  //指向这个结点的下一个结点
	OtherInfo info;			 //存边权之类的信息,默认为int类型
}ArcNode;
typedef struct VNode      //顶点信息
{
	VerTexType data;      //
	ArcNode* firstarc;    //指向边表第一个结点
}VNode,AdjList[MVNum];
typedef struct
{
	AdjList vertices;    //里边存表的结点
	int vexnum;		//图的当前顶点数
	int arcnum;    //图的当前边数
}ALGraph;
//利用邻接表表示法创建无向图
Status CreateUDG(ALGraph& G);
//确定点在顶点数组中的位置
//存在返回下标，不存在则返回-1
Status LocateVex(ALGraph G, VerTexType v1);

//采用邻接表创建有向图
Status CreateDigraph(ALGraph &G);

/**********************
*     图的遍历		***
**********************/
//深度优先遍历
void DFS_AM(AMGraph G, int v);
void DFS_AL(ALGraph G, int v);
//广度优先遍历
//..............................
