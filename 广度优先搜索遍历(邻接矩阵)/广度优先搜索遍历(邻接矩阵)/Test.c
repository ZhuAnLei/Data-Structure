#include<stdio.h>
#define MVNum 100                       	//��󶥵���
#define MAXQSIZE 100						//�����г���
#define Status int
#define OK 1
#define ERROR 0

typedef int QElemType;
int visited[MVNum] = {0};           	    //���ʱ�־���飬���ֵΪ"false" 
typedef struct {		//���нṹ��
	QElemType *base;							//��ʼ���Ķ�̬����洢�ռ�
	int front;								//ͷָ�룬�����в��գ�ָ���ͷԪ��
	int rear;								//βָ�룬�����в��գ�ָ���βԪ�ص���һ��λ��
}SqQueue;

#define MaxInt 32767		  //��ʾ����ֵ������
typedef char VerTexType;      //���趥�����������Ϊ�ַ��� 
typedef int ArcType;          //����ߵ�Ȩֵ����Ϊ����
typedef struct {
	VerTexType vexs[MVNum];		//�����
	ArcType arcs[MVNum][MVNum];		//�ڽӾ���
	int vexnum, arcnum;		//�㣬��
}AMGraph;
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

int LocateVex(AMGraph G, VerTexType v) {
	//ȷ����v��G�е�λ��
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vexs[i] == v)
			return i;
	return -1;
}//LocateVex
Status BFS(AMGraph G, int v) {
	SqQueue Q;
	QElemType u,w;
	printf("%c  ", G.vexs[v]);
	visited[v] = 1;
	InitQueue(&Q);
	EnQueue(&Q,v);
	while (!QueueEmpty(Q)) {
		DeQueue(&Q,&u);
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
			if (!visited[w]) {
				printf("%c  ", G.vexs[w]);
				visited[w] = 1;
				EnQueue(&Q,w);
			}
		}
	}
}
int FirstAdjVex(AMGraph G, int v) {
	//����v�ĵ�һ���ڽӵ�
	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (G.arcs[v][i] != MaxInt && visited[i] == 0)
			return i;
	}
	return -1;
}//FirstAdjVex
int NextAdjVex(AMGraph G, int u, int w) {
	//����v�����w����һ���ڽӵ�
	int i;
	for (i = w; i < G.vexnum; ++i) {
		if (G.arcs[u][i] != MaxInt && visited[i] == 0)
			return i;
	}
	return -1;
}//NextAdjVex
int CreateUDN(AMGraph *G) {
	printf("�����ܶ��������ܱ���(�ո����)\n");
	scanf("%d", &(G->vexnum));
	scanf("%d", &(G->arcnum));

	printf("���������ƣ���a\n");
	for (int i = 0; i < G->vexnum; i++) {
		printf("�����%d����ĵ�����:", i + 1);
		G->vexs[i] = getchar();
		scanf("%c", &(G->vexs[i]));
	}
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j] = MaxInt;
		}
	}
	printf("����������Ķ��㼰Ȩֵ���� a b 5\n");
	for (int k = 0; k < G->arcnum; k++) {
		VerTexType v1, v2;
		ArcType w;
		printf("�������%d���������Ķ��㼰Ȩֵ:", k + 1);
		scanf("%c", &v1);
		scanf("%c", &v1);
		scanf("%c", &v2);
		scanf("%c", &v2);
		scanf("%d", &w);
		printf("\n");
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		G->arcs[i][j] = w;
		G->arcs[j][i] = G->arcs[i][j];
	}
	return OK;
}
int main() {
	AMGraph G;
	CreateUDN(&G);
	printf("---------���������������---------\n");
	printf("������������ݵĶ��㣺");
	char c;
	scanf("%c",&c); scanf("%c", &c);
	int v = LocateVex(G, c);
	printf("��%cΪ������������ ", c);
	BFS(G,v);
}
