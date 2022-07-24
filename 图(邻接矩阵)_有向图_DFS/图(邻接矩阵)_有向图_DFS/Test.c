#include<stdio.h>
#define OK 1
#define ERROR 0
#define MaxInt 32767	//��ʾ����ֵ������
#define MVNum 100		//��󶥵���
typedef char VerTexType;      //���趥�����������Ϊ�ַ��� 
typedef int ArcType;          //����ߵ�Ȩֵ����Ϊ����
typedef struct {
	VerTexType vexs[MVNum];		//�����
	ArcType arcs[MVNum][MVNum];		//�ڽӾ���
	int vexnum, arcnum;		//�㣬��
}AMGraph;
int visited[MVNum] = { 0 };
int main() {
	printf("************�㷨6.1�����ڽӾ����ʾ����������ͼ(C����)**************\n");
	AMGraph G;     int i, j;
	CreateUDN(&G);

	printf("*****�ڽӾ����ʾ��������������*****\n");

	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			if (j != G.vexnum - 1) {
				if (G.arcs[i][j] != MaxInt)
					printf("%d\t", G.arcs[i][j]);
				else
					printf("��\t");
			}
			else {
				if (G.arcs[i][j] != MaxInt)
					printf("%d\n", G.arcs[i][j]);
				else
					printf("��\n");
			}
		}
	}
	//������ȱ���
	printf("*****�ڽӾ����ʾ������������ͼ��������ȱ���*****\n");
	printf("������������ݵĶ���");
	char c;
	scanf("%c", &c);
	scanf("%c", &c);
	int v = LocateVex(G,c);
	printf("��%cΪ������������ ",c);
	DFS_AL(G, v);
	return 0;

}
int LocateVex(AMGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return -1;
}
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
	}
	return OK;
}
//������ȱ���
int DFS_AL(AMGraph G, int v) {
	printf("%c  ",G.vexs[v]);
	visited[v] = 1;
	for (int w = 0; w < G.vexnum; w++) {
		if ((G.arcs[v][w] != 0) && (!visited[w])) {
			DFS_AL(G,w);
		}
	}
}