#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MVNum 100     //��󶥵��� 
typedef char VerTexType;	//������Ϣ
typedef int OtherInfo;	 //�ͱ���ص���Ϣ

//- - - - -ͼ���ڽӱ�洢��ʾ- - - - - 
typedef struct ArcNode {     //�߽�� 
	int adjvex;     //�ñ���ָ��Ķ����λ�� 
	struct ArcNode *nextarc;    //ָ����һ���ߵ�ָ�� 
	OtherInfo info;    //�ͱ���ص���Ϣ 
}ArcNode;

typedef struct VNode {
	VerTexType data;     //������Ϣ 
	ArcNode *firstarc;    //ָ���һ�������ö���ıߵ�ָ�� 
}VNode, AdjList[MVNum];    //AdjList��ʾ�ڽӱ����� 

typedef struct {
	AdjList vertices;    //�ڽӱ� 
	int vexnum, arcnum;    //ͼ�ĵ�ǰ�������ͱ��� 
}ALGraph;
int visited[MVNum] = { 0 };
int main() {
	printf("************�㷨6.2�������ڽӱ��ʾ����������ͼ**************\n");
	ALGraph G;
	CreateUDG(&G);
	printf("*****�ڽӱ��ʾ������������ͼ*****\n");
	for (int i = 0; i < G.vexnum; ++i) {
		ArcNode *p = G.vertices[i].firstarc;
		if (p == NULL) {
			printf("%c", G.vertices[i].data);
		}
		else {
			printf("%c", G.vertices[i].data);
			while (p) {
				printf("->");
				printf("%d", p->adjvex);
				p = p->nextarc;
			}
		}
		printf("\n");
	}
	printf("*****�ڽӱ��ʾ������������ͼ��������ȱ���*****\n");
	printf("������������ݵĶ���");
	char c;
	scanf("%c", &c);
	scanf("%c", &c);
	int v = LocateVex(G, c);
	printf("��%cΪ������������ ", c);
	DFS_AL(G, v);
	return 0;
}
int LocateVex(ALGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vertices[i].data == v)
			return i;
	return -1;
}
int CreateUDG(ALGraph *G) {
	printf("�������ܶ��������ܱ����м��Կո����:\n");
	scanf("%d",&(G->vexnum));
	scanf("%d",&(G->arcnum));
	printf("���������ƣ��� a \n");
	for (int i = 0; i < G->vexnum; i++) {
		printf("�������%d���������:",i+1);
		scanf("%c",&(G->vertices[i].data));
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	printf("������һ���������Ķ���,�� a b \n");
	for (int k = 0; k < G->arcnum; k++) {
		VerTexType v1, v2;
		printf("�������%d���������Ķ���:",k+1);
		scanf("%c", &v1);
		scanf("%c", &v1);
		scanf("%c", &v2);
		scanf("%c", &v2);
		int i = LocateVex(*G,v1);
		int j = LocateVex(*G,v2);
		ArcNode *p1 =(ArcNode *) malloc(sizeof(ArcNode));
		p1->adjvex = j;
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;
	}
	return OK;
}
//������ȱ���
int DFS_AL(ALGraph G, int v) {
	printf("%c  ", G.vertices[v].data);
	visited[v] = 1;
	ArcNode *p = G.vertices[v].firstarc;
	while (p != NULL) {
		int w = p->adjvex;
		if (!visited[w]) {
			DFS_AL(G, w);
		}
		p = p->nextarc;
	}
}
