#ifndef _HEAD_H_
#define _HEAD_H_

using namespace std;
/************************
* ͼ���ڽӾ���洢��ʾ **
************************/
const int MaxInt = 32767; //��ʾ����ֵ��������
const int  MVNum = 100;   //��ʾ���ĵ����
typedef char VerTexType;       //�ٶ��������������Ϊchar
typedef int ArcType;       //�ٶ�Ϊint
typedef int Status;
#define OK 1;
typedef struct
{
	VerTexType vexs[MVNum];         //�����
	ArcType arcs[MVNum][MVNum];		//�ڽӾ���
	int vexnum;		//ͼ�ĵ�ǰ����
	int arcnum;		//ͼ�ĵ�ǰ����
}AMGraph;

//�����ڽӾ����ʾ������������
Status CreateUDN(AMGraph &G);
//ȷ�����ڶ��������е�λ��
Status LocateVex(AMGraph G, VerTexType v1);
#endif // !_HEAD_H_
//�����ڽӾ��󷨱�ʾ����ͼ
Status CreateDigraph(AMGraph& G);

/*********************
* ͼ���ڽӱ��ʾ�� ***
**********************/
//������󶥵��� const int MVNum = 100;
//����������Ϣ���� 
typedef int OtherInfo;
typedef struct ArcNode    //�߽��
{
	int adjvex;			//��Vi����ؽ���ڶ��������е��±�
	struct ArcNode* nextarc;  //ָ�����������һ�����
	OtherInfo info;			 //���Ȩ֮�����Ϣ,Ĭ��Ϊint����
}ArcNode;
typedef struct VNode      //������Ϣ
{
	VerTexType data;      //
	ArcNode* firstarc;    //ָ��߱��һ�����
}VNode,AdjList[MVNum];
typedef struct
{
	AdjList vertices;    //��ߴ��Ľ��
	int vexnum;		//ͼ�ĵ�ǰ������
	int arcnum;    //ͼ�ĵ�ǰ����
}ALGraph;
//�����ڽӱ��ʾ����������ͼ
Status CreateUDG(ALGraph& G);
//ȷ�����ڶ��������е�λ��
//���ڷ����±꣬�������򷵻�-1
Status LocateVex(ALGraph G, VerTexType v1);

//�����ڽӱ�������ͼ
Status CreateDigraph(ALGraph &G);

/**********************
*     ͼ�ı���		***
**********************/
//������ȱ���
void DFS_AM(AMGraph G, int v);
void DFS_AL(ALGraph G, int v);
//������ȱ���
//..............................
