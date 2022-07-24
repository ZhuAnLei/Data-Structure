#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
typedef struct
{
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;
typedef char **HuffmanCode;
typedef struct {
	int bit[100];
	int start;
}HCodeType;
int main() {
	HuffmanTree HT;
	int n;
	printf("������Ҷ�ӽ��ĸ�����\n");
	scanf("%d", &n);
	CreateHuffmanTree(&HT, n);
	printf("��������������ϣ�\n");
	for (int i = 1; i < 2*n; i++) {
		printf("��㣺%-4d,weight:%-5d,parent:%-5d,lchild:%-5d,rchild:%-5d\n",i,HT[i].weight,HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	CreatHuffmanCode(&HT, n);
}

int Select(HuffmanTree *HT, int len, int *s1, int *s2)
{
	int min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;//�ȸ������ֵ
	for (int i = 1; i <= len; i++)
	{
		if ((*HT)[i].weight<min1&& (*HT)[i].parent == 0)
		{
			min1 = (*HT)[i].weight;
			*s1 = i;
		}
	}
	int temp = (*HT)[*s1].weight;//��ԭֵ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��
	(*HT)[*s1].weight = 0x3f3f3f3f;
	for (int i = 1; i <= len; i++)
	{
		if ((*HT)[i].weight<min2&& (*HT)[i].parent == 0)
		{
			min2 = (*HT)[i].weight;
			*s2 = i;
		}
	}
	(*HT)[*s1].weight = temp;//�ָ�ԭ����ֵ
}

int CreateHuffmanTree(HuffmanTree *HT, int n) {
	if (n <= 1) {
		return ERROR;
	}
	/*��ʼ������*/
	int m = 2 * n - 1;
	*HT = (HTNode *)malloc((m+1) * sizeof(HTNode));
	for (int i = 1; i <= m; i++) {
		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0;
	}
	printf("������Ҷ�ӽ���Ȩֵ��\n");
	for (int i = 1; i <= n; i++) {
		printf("�������%d��Ҷ����Ȩֵ\n", i);
		scanf("%d", &((*HT)[i].weight));
	}
	/*��ʼ�����շ�����*/
	for (int i = n + 1; i <= m; i++) {
		int s1, s2=0;
		Select(HT, i - 1, &s1, &s2);
		(*HT)[s1].parent = i;
		(*HT)[s2].parent = i;
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
}

int CreatHuffmanCode(HuffmanTree *HT, int n) {
	HCodeType HuffCode[100], cd;
	for (int i = 1; i <= n; i++) {
		cd.start = n - 1;
		int c = i;
		int p = (*HT)[c].parent;
		while (p != 0) {
			if ((*HT)[p].lchild == c) {
				cd.bit[cd.start] = 0;
			}
			else {
				cd.bit[cd.start] = 1;
			}
			cd.start--;
			c = p;
			p = (*HT)[c].parent;
		}
		for (int j = cd.start + 1; j < n; j++) {
			HuffCode[i].bit[j] = cd.bit[j];
		}
		HuffCode[i].start = cd.start;
	}
	printf("����������Ϊ��\n");
	for (int i = 1; i <= n; i++) {
		printf("%-5d�Ĺ���������Ϊ��", (*HT)[i].weight);
		for (int j = HuffCode[i].start + 1; j < n; j++) {
			printf("%d", HuffCode[i].bit[j]);
		}
		printf("\n");
	}
}