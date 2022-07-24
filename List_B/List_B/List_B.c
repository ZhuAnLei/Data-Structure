#include<stdio.h>
#include <stdlib.h> 
#include <string.h>
#define OK 1;
#define ERROR 0;
typedef struct {
	int num;
	char *name;
	float score;
}Student;
typedef struct LNode{
	Student *elem;
	struct LNode *next;
}LNode , *LinkList;
int main() {
	LinkList L;
	UI();
	while (1) {
		int choose;
		printf("���������ѡ��\n");
		scanf("%d",&choose);
		switch (choose)
		{
			case 1:InitList(&L); UI(); break;
			case 2:CreatList(&L); UI(); break;
			case 3:TraverseList(L); UI(); break;
			case 4:LocateElem(L); UI();; break;
			case 5:ListInsert(&L); UI(); break;
			case 6:ListDelete(&L);UI();break;
			case 7:DestroyList(&L); break;
			case 8:return 0; break;
			case 9:ListLength(L); UI(); break;
			case 10:DeleteRepeat(&L); UI(); break;
			default:printf("���������������������ѡ��\n"); break;
		}
	}
}

int InitList(LinkList *L) {
	*L = (LinkList *)malloc(sizeof(LNode));
	(*L)->next = NULL;
	printf("�����ʼ���ɹ���\n");
	return OK;
}

int DeleteRepeat(LinkList *L) {
	LinkList p = (*L)->next;
	while (p) {
		if (p->next == NULL) {
			break;
		}
		LinkList m = p;
		while (m->next) {
			if (p->elem->num == m->next->elem->num) {
				LinkList q = m->next;
				m->next = q->next;
				if (q == NULL) {
					break;
				}
				continue;
			}
			m = m->next;
		}
		p = p->next;
	}
	printf("Successful\n");
}

int CreatList(LinkList *L) {
	printf("---------�������������---------\n");
	InitList(L);
	/*printf("��������Ҫ����ѧ���ĸ���\n");
	int n = 0;
	scanf("%d",&n);

	for (int i = 0; i < n;i++) {
		ListInsert(L);
	}*/

	LinkList p = (LinkList)malloc(sizeof(LNode));   //����ʹ��
	LinkList r = *L;
	p->elem = (Student *)malloc(sizeof(Student));
	p->elem->num = 17217014;
	p->elem->name = "Jason";
	p->elem->score = 80;
	p->next = NULL;
	r->next = p;
	r = p;

	p = (LinkList)malloc(sizeof(LNode));
	p->elem = (Student *)malloc(sizeof(Student));
	p->elem->num = 17217015;
	p->elem->name = "Eason";
	p->elem->score = 90;
	p->next = NULL;
	r->next = p;
	r = p;

	p = (LinkList)malloc(sizeof(LNode));
	p->elem = (Student *)malloc(sizeof(Student));
	p->elem->num = 17217016;
	p->elem->name = "Aason";
	p->elem->score = 100;
	p->next = NULL;
	r->next = p;
	r = p;

}

int ListInsert(LinkList *L) {
	printf("---------������������---------\n");
	LinkList p = *L,q ,r;
	r = p;
	q= (LinkList)malloc(sizeof(LNode));
	q->elem= (Student *)malloc(sizeof(Student));
	Student s;
	char name[20];
	printf("����������ѧ��ѧ�ţ�\n");
	scanf("%d",&s.num);
	printf("����������ѧ��������\n");
	scanf("%s",name);
	printf("����������ѧ��������\n");
	scanf("%f",&s.score);
	s.name = strdup(name);
	q->elem->num = s.num;
	q->elem->name = s.name;
	q->elem->score = s.score;
	if (p->next==NULL) {
		q->next = NULL;
		p->next = q;
		printf("�������ݳɹ���\n");
		return OK;
	}
	p = p->next;
	while (p) {
		if (p->elem->score<s.score&&p->next == NULL) {
			q->next = NULL;
			p->next = q;
			printf("�������ݳɹ���\n");
			return OK;
		}
		if (p->elem->score<s.score&&p->next->elem->score>s.score) {
			q->next = p->next;
			p->next = q;
			printf("�������ݳɹ���\n");
			return OK;
		}
		if (p->elem->score>s.score) {
			r->next = q;
			q->next = p;
			printf("�������ݳɹ���\n");
			return OK;
		}
		p = p->next;
	}
	return ERROR; 
}

int ListLength(LinkList L) {
	LinkList p = L->next;
	int count = 0;
	while (p) {
		count++;
		p=p->next;
	}
	printf("������%d\n",count);
}

int TraverseList(LinkList L) {
	printf("---------����������---------\n");
	if (L==NULL) {
		printf("������δ������\n");
		return ERROR;
	}
	LinkList p = L->next;
	if (p==NULL) {
		printf("�������ݣ�\n");
		return OK;
	}
	while (p) {
		printf("ѧ�ţ�%10d    ",p->elem->num);
		printf("������%10s    ", p->elem->name);
		printf("������%10.1f\n", p->elem->score);
		p = p->next;
	}
}
int LocateElem(LinkList L) {
	printf("----------��ѯ���ݲ���----------\n");
	char name[20];
	int num;
	LinkList p = L->next;
	printf("��������Ҫ��ѯ�����ݣ�\n");
	int choose = 0;
	printf("\n�����������밴��1��\n��ѧ�Ų����밴��2��\n\n");
	scanf("%d",&choose);
	switch (choose)
	{
		case 1:	printf("��������Ҫ��ѯ������\n");
				scanf("%s", name); 
				while (p&& strcmp(p->elem->name, name)) {
					p = p->next;
				}; 
				break;
		case 2:	printf("��������Ҫ��ѯ��ѧ��\n");
				scanf("%d", &num); 
				while (p&&p->elem->num != num) {
					p = p->next;
				}; 
				break;
		default:printf("��������\n"); return ERROR;
		break;
	}
	
	if (p == NULL) {
		printf("��ѯ�޹����������ڸ����ݣ�\n");
		return ERROR;
	}
	printf("������Ϣ��\n");
	printf("ѧ�ţ�%10d    ", p->elem->num);
	printf("������%10s    ", p->elem->name);
	printf("������%10.1f\n", p->elem->score);
	return OK;
}
int ListDelete(LinkList *L) {
	printf("----------ɾ�����ݲ���----------\n");
	char name[20];
	int num;
	LinkList p = (*L);
	printf("��������Ҫɾ�������ݣ�\n");
	int choose = 0;
	printf("\n������ɾ���밴��1��\n��ѧ��ɾ���밴��2��\n\n");
	scanf("%d", &choose);
	switch (choose)
	{
		case 1:	printf("��������Ҫɾ�����ݵ�����\n");
				scanf("%s", name);
				while (p->next&& strcmp(p->next->elem->name, name)) {
					p = p->next;
				};
				break;
		case 2:	printf("��������Ҫɾ�����ݵ�ѧ��\n");
				scanf("%d", &num);
				while (p->next&&p->next->elem->num != num) {
					p = p->next;
				};
				break;
		default:printf("��������\n"); return ERROR;
				break;
	}
	if (p->next == NULL) {
		printf("ɾ��ʧ�ܣ��������ڸ����ݣ�\n");
		return ERROR;
	}
	LinkList q = p->next;
	p->next = q->next;
	free(q->elem);
	free(q);
	printf("ɾ�����ݳɹ���\n");
	return OK;
}
int DestroyList(LinkList *L) {
	printf("----------��������----------\n");
	LinkList p;
	while (*L!=NULL) {
		p = *L;
		*L = (*L)->next;
		free(p->elem);
		free(p);
	}
	return OK;
}
int UI() {
	printf("\t\t***************************************\n");
	printf("\t\t*-------ѧ���ɼ�����ϵͳ(����)--------*\n");
	printf("\t\t*		                      *\n");
	printf("\t\t*----------����1����ʼ�����Ա�--------*\n");
	printf("\t\t*----------����2���������Ա�----------*\n");
	printf("\t\t*----------����3���������Ա�----------*\n");
	printf("\t\t*----------����4����ѯ����------------*\n");
	printf("\t\t*----------����5����������------------*\n");
	printf("\t\t*----------����6��ɾ������------------*\n");
	printf("\t\t*----------����7���������Ա�----------*\n");
	printf("\t\t*----------����8���˳�����ϵͳ--------*\n");
	printf("\t\t*----------����9���������ݸ���--------*\n");
	printf("\t\t*----------����10��ɾ���ظ�ֵ---------*\n");
	printf("\t\t*		                      *\n");
	printf("\t\t***************************************\n");
}