#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1001

typedef struct {
	int r, c, d;	// ��, ��, ����
}Triple;
typedef struct {
	Triple base[MAXSIZE + 1];	// ˳��ṹ
	int mu, nu, tu;				// ��, ��, ������
}TSMatrix;
// ��ȡ
int input(TSMatrix& T)
{
	scanf("%d", &T.tu);
	for (int i = 0; i < T.tu; i++)
		scanf("%d %d %d", &T.base[i].r, &T.base[i].c, &T.base[i].d);
	return 0;
}
// ���
void output(TSMatrix T)
{
	printf("%d\n", T.tu);
	for (int i = 0; i < T.tu; i++)
	{
		printf("%d %d %d", T.base[i].r, T.base[i].c, T.base[i].d);
		if (i != T.tu - 1)
			printf("\n");
	}
	return;
}
// ����
void EnterTriple(Triple& A, int r,int c,int d)
{
	A.r = r; A.c = c; A.d = d;
	return;
}
// ����ӷ�, ����A+B
TSMatrix MatrixAddition(TSMatrix A, TSMatrix B)
{
	TSMatrix RES;
	RES.mu = A.mu; RES.nu = A.nu;
	int pr = 0, pa = 0, pb = 0;
	while (pa != A.tu && pb != B.tu)
	{
		// �ȱȽ��е��������
		if (A.base[pa].r < B.base[pb].r)
		{
			EnterTriple(RES.base[pr], A.base[pa].r, A.base[pa].c, A.base[pa].d);
			pa++;
		}
		else if (A.base[pa].r > B.base[pb].r)
		{
			EnterTriple(RES.base[pr], B.base[pb].r, B.base[pb].c, B.base[pb].d);
			pb++;
		}
		else {	// �����, �Ƚ��е����
			if (A.base[pa].c < B.base[pb].c)
			{
				EnterTriple(RES.base[pr], A.base[pa].r, A.base[pa].c, A.base[pa].d);
				pa++;
			}
			else if(A.base[pa].c > B.base[pb].c)
			{
				EnterTriple(RES.base[pr], B.base[pb].r, B.base[pb].c, B.base[pb].d);
				pb++;
			}
			else{	// �����,�ж����ֵ�Ƿ�Ϊ��
				if (A.base[pa].d + B.base[pb].d != 0)
				{
					EnterTriple(RES.base[pr], A.base[pa].r, A.base[pa].c, A.base[pa].d + B.base[pb].d);
					pa++; pb++;
				}
				else {
					pa++; pb++; pr--;	// ����pr����Ҫ��һ, �����������һ
				}
			}
		}
		pr++;	// ÿ�θ���RES�����λ��
	}
	// ���ｫʣ���Ԫ�ط���RES��, ���ƹ鲢�㷨
	while (pa != A.tu) {
		EnterTriple(RES.base[pr], A.base[pa].r, A.base[pa].c, A.base[pa].d);
		pa++; pr++;
	}
	while (pb != B.tu) {
		EnterTriple(RES.base[pr], B.base[pb].r, B.base[pb].c, B.base[pb].d);
		pb++; pr++;
	}
	RES.tu = pr;	// ����RES�з���Ԫ��
	return RES;
}

int main() {
	// �����߼� ��ȡAB->���C=A+B->���C
	int r, c;
	TSMatrix A, B, C;
	scanf("%d %d",&r,&c);
	A.mu = B.mu = r; A.nu = B.nu = c;

	input(A); input(B);
	C = MatrixAddition(A, B);
	output(C);
	return 0;
}