#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAXQSIZE 100
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
//-------------------------------------
typedef int Status;
typedef int QElemType;
int visited[MVNum] = { 0 };           	    //���ʱ�־���飬���ֵΪ"false" 
typedef struct {		//���нṹ��
	QElemType *base;							//��ʼ���Ķ�̬����洢�ռ�
	int front;								//ͷָ�룬�����в��գ�ָ���ͷԪ��
	int rear;								//βָ�룬�����в��գ�ָ���βԪ�ص���һ��λ��
}SqQueue;
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
	printf("*****�ڽӱ��ʾ������������ͼ�Ĺ�����ȱ���*****\n");
	printf("������������ݵĶ���");
	char c;
	scanf("%c", &c);
	scanf("%c", &c);
	int v = LocateVex(G, c);
	printf("��%cΪ������������ ", c);
	BFS(G, v);
	return 0;
}
int LocateVex(ALGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vertices[i].data == v)
			return i;
	return -1;
}
int FirstAdjVex(ALGraph G, int v) {
	//����v�ĵ�һ���ڽӵ�
	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (visited[i] == 0)
			return i;
	}
	return -1;
}//FirstAdjVex
Status BFS(ALGraph G, int v) {
	SqQueue Q;
	QElemType u, w;
	printf("%c  ", G.vertices[v]);
	visited[v] = 1;
	InitQueue(&Q);
	EnQueue(&Q, v);
	while (!QueueEmpty(Q)) {
		DeQueue(&Q, &u);
		ArcNode *temp = G.vertices[u].firstarc;
		while (temp) {
			if (!visited[temp->adjvex]) {
				printf("%c  ", G.vertices[temp->adjvex]);
				EnQueue(&Q, temp->adjvex);
				visited[temp->adjvex] = 1;
			}
			temp = temp->nextarc;
		}
	}
}
int CreateUDG(ALGraph *G) {
	printf("�������ܶ��������ܱ����м��Կո����:\n");
	scanf("%d", &(G->vexnum));
	scanf("%d", &(G->arcnum));
	printf("���������ƣ��� a \n");
	for (int i = 0; i < G->vexnum; i++) {
		printf("�������%d���������:", i + 1);
		scanf("%c", &(G->vertices[i].data));
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	printf("������һ���������Ķ���,�� a b \n");
	for (int k = 0; k < G->arcnum; k++) {
		VerTexType v1, v2;
		printf("�������%d���������Ķ���:", k + 1);
		scanf("%c", &v1);
		scanf("%c", &v1);
		scanf("%c", &v2);
		scanf("%c", &v2);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
		p1->adjvex = j;
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;

		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
		p2->adjvex = i;
		p2->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = p2;
	}
	return OK;
}
//-----���в���start-----
Status InitQueue(SqQueue *Q) {
	Q->base = (QElemType *)malloc(sizeof(MAXQSIZE));
	if (!Q->base) {
		exit(0);
	}
	Q->front = Q->rear = 0;
	return OK;
}
Status EnQueue(SqQueue *Q, QElemType e) {
	if ((Q->rear + 1) % MAXQSIZE == Q->front) {
		printf("���ʧ�ܣ���������\n");
		return ERROR;
	}
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}
Status DeQueue(SqQueue *Q, QElemType *e) {
	if (Q->front == Q->rear) {
		printf("�ӿգ�\n");
		return ERROR;
	}
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}
Status QueueEmpty(SqQueue Q) {
	//�ж��Ƿ�Ϊ�ն�
	if (Q.rear == Q.front)
		return 1;
	return 0;
}//QueueEmpty
 //-----���в���end-----
