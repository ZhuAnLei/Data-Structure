#include <stdio.h>
#include <stdlib.h>
#define HASHSIZE 15
#define NULLKEY -32768
typedef struct
{
	int *elem; //����Ԫ�ش洢��ַ
	int count;//��ǰԪ�ظ���
}HashTable;
int L = 0; //��ĳ���
int main() {
	HashTable hashTable;
	int arr[HASHSIZE];
	printf("������15������ʼ����ϣ���Ԫ�أ�\n");
	for (int i = 0; i < HASHSIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	Init(&hashTable);
	for (int i = 0; i < HASHSIZE; i++) {
		insert(&hashTable, arr[i]);
	}
	display(&hashTable);
	int x = 0;
	printf("��������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d", &x);
	int result = findNum(hashTable, x);
	if (result)
		printf("����Ԫ��%d�ڹ�ϣ���е�λ��Ϊ%d\n", x, result);
	else
		printf("û�ҵ���\n");
}
int Init(HashTable *hashTable)//��ϣ��ĳ�ʼ��
{
	int i;
	L = HASHSIZE;
	hashTable->elem = (int*)malloc(L * sizeof(int));//�����ڴ�
	hashTable->count = L;
	for (i = 0; i < L; i++)
	{
		hashTable->elem[i] = NULLKEY;
	}
	return 1;
}
//��ϣ����������������
int Hash(int data)
{
	return data%L;
}
int insert(HashTable *hashTable, int data)
{
	int Addr = Hash(data);//���ϣ��ַ
	while (hashTable->elem[Addr] != NULLKEY)//��õ�ַ���ǳ�ʼ��ʱ�Ŀգ����ʾ��Ԫ���Ѿ����룬���г�ͻ
	{
		Addr = (Addr + 1) % L;//���ŵ�ַ����̽�⣬�����Զ���̽��
	}
	hashTable->elem[Addr] = data;
}

int display(HashTable *hashTable)
{
	printf(".........���չʾ.........\n");
	for (int i = 0; i < hashTable->count; i++)
	{
		printf("%d  ", hashTable->elem[i]);
	}
	printf("\n");
}
int findNum(HashTable hashTable, int data) {
	int Addr = Hash(data);
	while (hashTable.elem[Addr] != data)
	{
		Addr = (Addr + 1) % L;
		if (hashTable.elem[Addr] == NULLKEY || Addr == Hash(data)) {
			return 0;
		}
	}
	return Addr + 1;
}
//�������ݣ� 19 14 23 1 68 20 84 27 55 11 10 79 95 12 50