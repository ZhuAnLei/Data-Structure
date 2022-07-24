#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
#define OK 1;
#define ERROR 0;
typedef struct {
	int num;
	char *name;
	float score;
}Student;
typedef struct {
	Student *elem;
	int length;
}SqList;
void main() {

	SqList L;
	UI();
	while (1) {
		int choose;
		printf("���������ѡ��\n");
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:IniSqList(&L); UI(); break;
			case 2:CreatList(&L); UI(); break;
			case 3:TraverseList(L); UI(); break;
			case 4:GetElem(L); UI(); break;
			case 5:ListInsert(&L); UI(); break;
			case 6:ListDelete(&L); UI(); break;
			case 7:DestroyList(&L); UI(); break;
			case 8:return 0; break;
			default:printf("���������������������ѡ��\n"); break;
		}
	}
}
int IniSqList(SqList *L) {	//����յ����Ա�
	L->elem = (Student *)malloc(MAXSIZE * sizeof(Student));
	if (L->elem == NULL) {
		printf("�洢����ʧ�ܣ�\n");
		return ERROR;
	}
	else {
		printf("�洢����ɹ���\n");
		L->length = 0;
		return OK;
	}
}
int DestroyList(SqList *L) {	//�������Ա�
	L->elem = NULL;
	L->length = 0;
	printf("�������Ա�ɹ���\n");
	return OK;
}
int CreatList(SqList *L) {		//����˳���
	IniSqList(L);
	/*printf("��������Ҫ����ѧ���ĸ���\n");
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ListInsert(L);
	}*/
	L->elem[0].num = 17217014;    //����ʹ��
	L->elem[0].name = "Jason";
	L->elem[0].score = 80;
	L->length++;
	L->elem[1].num = 17217015;
	L->elem[1].name = "Eason";
	L->elem[1].score = 90;
	L->length++;
	L->elem[2].num = 17217016;
	L->elem[2].name = "Aason";
	L->elem[2].score = 100;
	L->length++;
}
int TraverseList(SqList L) {	//��������
	printf("--------------��������--------------\n");
	if (L.length == 0) {
		printf("��������\n");
		return ERROR;
	}
	for (int i = 0; i < L.length; i++) {
		printf("ѧ�ţ� %10d   ", L.elem[i].num);
		printf("������ %10s   ", L.elem[i].name);
		printf("������ %10.1f\n", L.elem[i].score);
	}
	printf("\n");
	return OK;
}
int GetElem(SqList L) {	//��ȡָ��Ԫ�ص�ֵ
	printf("----------��ѯ���ݲ���----------\n");
	char name[20];
	int num;
	printf("��������Ҫ��ѯ�����ݣ�\n");
	int choose = 0;
	printf("\n�����������밴��1��\n��ѧ�Ų����밴��2��\n\n");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:	printf("��������Ҫ��ѯ������\n");
		scanf("%s", name);
		for (int i = 0; i < L.length; i++) {
			if (strcmp(L.elem[i].name,name)==0) {
				printf("������Ϣ��\n");
				printf("ѧ�ţ�%10d    ", L.elem[i].num);
				printf("������%10s    ", L.elem[i].name);
				printf("������%10.1f\n", L.elem[i].score);
				return OK;
			}
		}
		break;
	case 2:	printf("��������Ҫ��ѯ��ѧ��\n");
		scanf("%d", &num);
		for (int i = 0; i < L.length; i++) {
			if (L.elem[i].num == num) {
				printf("������Ϣ��\n");
				printf("%10d    ", L.elem[i].num);
				printf("%10s    ", L.elem[i].name);
				printf("%10.1f\n", L.elem[i].score);
				return OK;
				break;
			}
		}
		break;
	default:printf("��������\n"); return ERROR;
		break;
	}
	printf("��ѯ�޹���\n");
	return ERROR;
}
int ListDelete(SqList *L) {	//ɾ��ָ��λ������
	printf("--------ɾ��ָ��λ������--------\n");
	char name[20];
	int num;
	printf("��������Ҫɾ�������ݣ�\n");
	int choose = 0;
	printf("\n������ɾ���밴��1��\n��ѧ��ɾ���밴��2��\n\n");
	scanf("%d", &choose);
	switch (choose)
	{
		case 1:	printf("��������Ҫɾ�����ݵ�����\n");
				scanf("%s", name);
				if (strcmp(L->elem[L->length - 1].name, name)==0) {
					L->length--;
					printf("ɾ�����ݳɹ���\n");
					return OK;
				};
				for (int j = 0; j < L->length - 1; j++) {
					if (strcmp(L->elem[j].name, name) == 0) {
						for (int i = j; i < L->length - 1; i++) {
							L->elem[i] = L->elem[i + 1];
						}
						L->length--;
						printf("ɾ�����ݳɹ���\n");
						return OK;
					}
				}
				break;
		case 2:	printf("��������Ҫɾ�����ݵ�ѧ��\n");
				scanf("%d", &num);
				if (L->elem[L->length - 1].num==num) {
					L->length--;
					printf("ɾ�����ݳɹ���\n");
					return OK;
				}
				for (int j = 0; j < L->length - 1; j++) {
					if (L->elem[j].num==num) {
						for (int i = j; i < L->length - 1; i++) {
							L->elem[i] = L->elem[i + 1];
						}
						L->length--;
						printf("ɾ�����ݳɹ���\n");
						return OK;
					}
				}
				break;
		default:printf("��������\n"); return ERROR;break;
	}
	printf("ɾ��ʧ�ܣ��������ڸ����ݣ�\n");
	return OK;
}
int ListInsert(SqList *L) {		//�������ݵ�ָ��λ��
	printf("		-------��������-------\n");
	Student s;
	char str[20];
	printf("��������Ҫ�����ѧ��ѧ��:\n");
	scanf("%d", &s.num);
	printf("��������Ҫ�����ѧ������:\n");
	scanf("%s", str);
	printf("��������Ҫ�����ѧ������:\n");
	scanf("%f", &s.score);
	s.name = strdup(str);
	if (L->length >= MAXSIZE) {
		printf("����������\n");
		return ERROR;
	}
	for (int i = 0; i < L->length; i++) {
		if (s.score <= L->elem[i].score) {
			for (int j = L->length; j >= i; j--) {
				L->elem[j] = L->elem[j - 1];
			}
			L->elem[i].num = s.num;
			L->elem[i].name = s.name;
			L->elem[i].score = s.score;
			L->length++;
		}
	}
	printf("�������ݳɹ���\n");
	return OK;
}
int UI() {
	printf("\t\t***************************************\n");
	printf("\t\t*------ѧ���ɼ�����ϵͳ(˳���)-------*\n");
	printf("\t\t*		                      *\n");
	printf("\t\t*----------����1����ʼ�����Ա�--------*\n");
	printf("\t\t*----------����2���������Ա�----------*\n");
	printf("\t\t*----------����3���������Ա�----------*\n");
	printf("\t\t*----------����4����ѯ����------------*\n");
	printf("\t\t*----------����5����������------------*\n");
	printf("\t\t*----------����6��ɾ������------------*\n");
	printf("\t\t*----------����7���������Ա�----------*\n");
	printf("\t\t*----------����8���˳�����ϵͳ--------*\n");
	printf("\t\t*		                      *\n");
	printf("\t\t***************************************\n");
	return OK;
}