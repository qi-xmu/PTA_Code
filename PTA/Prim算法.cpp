#include<iostream>
#include<stack>
using namespace std;

#define Max_Vertex_Num 505

typedef struct ArcNode {
	int adjvex;	// 弧指向定点；
	int distance;
	int price;
}ArcNode;
typedef struct VNode
{
	int top=0;
	ArcNode arclist[505];	// 第一条弧

}VNode,AdjList[Max_Vertex_Num];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;	// 顶点个数，弧的个数
}ALGraph;

void pushNode(VNode& node, int adjvex, int distance, int price)
{
	node.arclist[node.top].adjvex=adjvex;
	node.arclist[node.top].distance = distance;
	node.arclist[node.top].price = price;
	node.top++;
}

ALGraph G;
ArcNode minArc(VNode v)
{
	int min = 501;
	int arc = 0;
	for (int i = 0; i < v.top; i++)
	{
		if (v.arclist[i].distance < min)
		{
			min = v.arclist[i].distance;
			arc = i;
		}
	}
	return v.arclist[arc];	// 返回最小弧
}
void mergeNode(int S, ArcNode minNode)
{
	VNode node = G.vertices[minNode.adjvex];
	for (int i = 0; i < node.top; i++)
	{
		// 将minNode中距离存到S中
		if (node.arclist[i].adjvex == S)
			continue;
		ArcNode arc = node.arclist[i];
		pushNode(G.vertices[S], arc.adjvex, arc.distance+ minNode.distance, arc.price+minNode.price);
	}
}

int minPath(int S,int D)
{
	ArcNode minNode=minArc(G.vertices[S]);
	mergeNode(S, minNode);

}
int main()
{
	int S, D;
	cin >> G.vexnum >> G.arcnum >> S >> D;
	for (int i = 0; i < G.arcnum; i++)
	{
		int vex,adjvex, distance, price;
		cin >> vex >> adjvex >> distance >> price;
		pushNode(G.vertices[vex], adjvex, distance, price);
		pushNode(G.vertices[adjvex], vex, distance, price);
	}
	minPath(S, D);


	return 0;
}