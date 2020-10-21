#include<stdio.h>

#define MAXSIZE 1001

typedef struct {
	int r, c, d;	// ��, ��, ����
}Triple;
typedef struct {
	Triple base[MAXSIZE + 1];	// ˳��ṹ
	int mu, nu, tu;				// ��, ��, ������
}TSMatrix;

// ����T����
int input(TSMatrix& T)
{
	for (int i = 0; i < T.tu; i++)
		scanf("%d %d %d", &T.base[i].r, &T.base[i].c, &T.base[i].d);
	return 0;
}
// ���T����
int output(TSMatrix T)
{
	for (int i = 0; i < T.tu; i++)
	{
		printf("%d %d %d", T.base[i].r, T.base[i].c, T.base[i].d);
		if (i != T.tu - 1)
			printf("\n");
	}
	return 0;
}
// ��r,c,d�ŵ����A��
void EnterTriple(Triple& A, int r, int c, int d)
{
	A.r = r; A.c = c; A.d = d;
	return;
}
// ת��M����,������T��
int TransposeMatrix(TSMatrix M,TSMatrix& T)
{
	T.mu = M.mu; T.nu = M.nu; T.tu = M.tu;
	int num[1001] = { 0 };		// ͳ�Ƹ����е�����
	int position[1001] = { 0 };	// ����num�������Ԫ�ص���ʼλ��
	if (T.tu)
	{
		// ͳ��
		for (int c = 0; c < M.tu; c++)
			num[M.base[c].c]++;
		// ����λ��
		position[0] = 0;
		for (int i = 1; i < M.nu; i++)
			position[i] = position[i - 1] + num[i - 1];
		// �Ѷ�ӦԪ�طŽ���Ӧλ��
		for (int i = 0; i < M.tu; i++)
		{
			int Col = M.base[i].c;
			EnterTriple(T.base[position[Col]], M.base[i].c, M.base[i].r, M.base[i].d);
			position[Col]++;	// �������Ӧλ��ָ���һ
		}
	}
	return 0;
}

int main()
{
	// �����߼� ��ȡ->ת��->���
	TSMatrix M, T;
	scanf("%d %d %d", &M.mu, &M.nu, &M.tu);
	input(M);
	TransposeMatrix(M,T);
	output(T);
	return 0;
}