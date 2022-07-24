#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
typedef struct BiNode {
	char *name;
	int score;
	struct BiNode *lchild, *rchild;
}BiTNode, *BiTree;

int main() {
	BiTree B;
	InitBiTree(&B);
	B = NULL;
	printf("����������������(���롰#��������)��\n");
	while (1) {
		char name[20];
		int score;
		scanf("%s",name);
		scanf("%d",&score);
		if (!strcmp(name,"#")) {
			break;
		}
		creatBiTree(&B, score, name);
	}

	printf("������������\n");
	inBeforeTraverse(B);

	printf("������������\n");
	InOrderTraverse(B);

	printf("������������\n");
	inLastTraverse(B);

	printf("���ٶ�����!\n");
	destroyBiTree(&B);

}

int InitBiTree(BiTree *T) {
	T = (BiTree*)malloc(sizeof(BiTree));
	if (T == NULL) {
		return ERROR;
	}
	printf("��ʼ���ɹ���\n");
	return OK;
}

int creatBiTree(BiTree *T, int score,char name[20]) {
	if (!(*T)) {
		BiTree temp = (BiTree*)malloc(sizeof(BiTNode));
		temp->score = score;
		temp->name = strdup(name);
		temp->lchild = temp->rchild = NULL;
		*T = temp;
		return OK;
	}
	if (score<(*T)->score) {
		creatBiTree(&((*T)->lchild), score, name);
	}
	else {
		creatBiTree(&((*T)->rchild), score, name);
	}
}

int destroyBiTree(BiTree *T) {
	if (*T) {
		destroyBiTree(&((*T)->lchild));
		destroyBiTree(&((*T)->rchild));
		free((*T)->name);
		free(*T);
	}
}

int InOrderTraverse(BiTree T) {		//�������
	if (T) {
		InOrderTraverse(T->lchild);
		printf("%10s", T->name);
		printf("%10d\n", T->score);
		InOrderTraverse(T->rchild);
	}
}

int inBeforeTraverse(BiTree T) {	//�������
	if (T) {
		printf("%10s", T->name);
		printf("%10d\n", T->score);
		inBeforeTraverse(T->lchild);
		inBeforeTraverse(T->rchild);
	}
}

int inLastTraverse(BiTree T) {		//�������
	if (T) {
		inLastTraverse(T->lchild);
		inLastTraverse(T->rchild);
		printf("%10s", T->name);
		printf("%10d\n", T->score);
	}
}
