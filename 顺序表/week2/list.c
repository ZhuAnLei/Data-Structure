#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define ERROR 0;
#define OK 1;
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SqList;
int main(){
	SqList L;
	IniSqList(&L);
	CreatList(&L);
	TraverseList(L);
	ElemType e;
	GetElem(L, 5, &e);
	printf("%d  \n",e);
	/*ClearList(&L);
	TraverseList(L);*/
	ListEmpty(L);
	printf("����Ԫ�ظ���Ϊ��%d\n", ListLength(L));
	printf("����Ԫ��10λ��%dλ\n",LocateElem(L,21));
	int cur_e=16;
	ElemType pre_e, next_e;
	PriorElem(L, cur_e, &pre_e);
	NextElem(L, cur_e, &next_e);

	int i=4, e2=100;
	ListInsert(&L, i, e2);
	TraverseList(L);
	printf("����Ԫ�ظ���Ϊ��%d\n", ListLength(L));
	ListDelete(&L, i);
	TraverseList(L);
	printf("����Ԫ�ظ���Ϊ��%d\n", ListLength(L));
}
int IniSqList(SqList *L){	//����յ����Ա�
	L->elem = (int *)malloc(MAXSIZE*sizeof(int));
	if (L->elem == NULL){
		printf("�洢����ʧ�ܣ�\n");
		return ERROR;
	}
	else{
		printf("�洢����ɹ���\n");
		L->length = 0;
		return OK;
	}
}
int DestroyList(SqList *L){	//�������Ա�
	L->elem = NULL;
	L->length = 0;
	printf("�������Ա�ɹ���\n");
	return OK;
}
int ClearList(SqList *L){	//�����Ա����
	L->elem = NULL;
	L->length = 0;
	printf("������Ա�ɹ���\n");
	return OK;
}
int ListEmpty(SqList L){	//�ж��Ƿ�Ϊ�ձ�
	if (L.elem != NULL){
		printf("���Ա�Ϊ�ձ�\n");
		return ERROR;
	}else{
		printf("���Ա�Ϊ�ձ�\n");
		return OK;
	}
}
int ListLength(SqList L){	//Ԫ�ظ���
	return L.length;
}
int CreatList(SqList *L){		//�����ݴ���ֵ
	for (int i = 0; i < 10; i++){
		L->elem[i] = i*2;
		L->length++;
	}
	return OK;
}
int GetElem(SqList L, int i, ElemType *e){	//��ȡָ��Ԫ�ص�ֵ
	if (i < 1 || i>L.length){
		printf("�������ݷǷ���\n");
		return ERROR;
	}
	*e = L.elem[i - 1];
	return OK;
}
int LocateElem(SqList L, ElemType e){		//����ֵ����Ԫ��λ�ã������ڷ���0
	for (int i = 0; i < L.length;i++){
		if (L.elem[i] == e){
			return i+1;
		}
	}
	return 0;
}
int PriorElem(SqList L, ElemType cur_e, ElemType *pre_e){	//ǰ��
	for (int i = 0; i < L.length; i++){
		if (L.elem[i] == cur_e){
			if (i - 1 <= 0){
				printf("%d��ǰ��\n",cur_e);
				return ERROR;
			}
			else{
				printf("%dǰ��Ϊ%d\n", cur_e, L.elem[i - 1]);
				return OK;
			}
		}
	}
}
int NextElem(SqList L, ElemType cur_e, ElemType *next_e){			//���
	for (int i = 0; i < L.length; i++){
		if (L.elem[i] == cur_e){
			if (i >= L.length){
				printf("%d�޺��\n", cur_e);
				return ERROR;
			}
			else{
				printf("%d���Ϊ%d\n", cur_e, L.elem[i + 1]);
				return OK;
			}
		}
	}
}
int ListInsert(SqList *L, int i, ElemType e){		//�������ݵ�ָ��λ��
	printf("--------�������ݵ�ָ��λ��--------\n");
	if ((i<1) || (i>L->length + 1)){
		printf("���ݲ���λ�÷Ƿ���\n");
		return ERROR;
	}
	if (L->length==MAXSIZE){
		printf("��ǰ�洢�ռ�������\n");
		return ERROR;
	}
	/*if (L->length == MAXSIZE){
		L=(int *)realloc(L, (MAXSIZE+1)* sizeof(int));
	}*/
	for (int j = L->length+1; j >= i; j--){
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i-1] = e;
	L->length++;
	return OK;
}
int ListDelete(SqList *L, int i){	//ɾ��ָ��λ������
	printf("--------ɾ��ָ��λ������--------\n");
	if ((i<1) || (i>L->length)){
		printf("ɾ������λ�÷Ƿ���\n");
		return ERROR;
	}
	i = i - 1;
	for (i; i < L->length-1; i++){
		L->elem[i] = L->elem[i + 1];
	}
	L->length--;
	return OK;
}
int TraverseList(SqList L){	//��������
	printf("--------��������--------\n");
	for (int i = 0; i < L.length; i++){
		printf("%d  ",L.elem[i]);
	}
	printf("\n");
	return OK;
}