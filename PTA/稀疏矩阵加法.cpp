#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1001

typedef struct {
	int r, c, d;	// 行, 列, 数据
}Triple;
typedef struct {
	Triple base[MAXSIZE + 1];	// 顺序结构
	int mu, nu, tu;				// 行, 列, 非零项
}TSMatrix;
// 读取
int input(TSMatrix& T)
{
	scanf("%d", &T.tu);
	for (int i = 0; i < T.tu; i++)
		scanf("%d %d %d", &T.base[i].r, &T.base[i].c, &T.base[i].d);
	return 0;
}
// 输出
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
// 存入
void EnterTriple(Triple& A, int r,int c,int d)
{
	A.r = r; A.c = c; A.d = d;
	return;
}
// 矩阵加法, 返回A+B
TSMatrix MatrixAddition(TSMatrix A, TSMatrix B)
{
	TSMatrix RES;
	RES.mu = A.mu; RES.nu = A.nu;
	int pr = 0, pa = 0, pb = 0;
	while (pa != A.tu && pb != B.tu)
	{
		// 先比较行的三种情况
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
		else {	// 行相等, 比较列的情况
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
			else{	// 列相等,判断相加值是否为零
				if (A.base[pa].d + B.base[pb].d != 0)
				{
					EnterTriple(RES.base[pr], A.base[pa].r, A.base[pa].c, A.base[pa].d + B.base[pb].d);
					pa++; pb++;
				}
				else {
					pa++; pb++; pr--;	// 下面pr不需要加一, 所以在这里减一
				}
			}
		}
		pr++;	// 每次更新RES存入的位置
	}
	// 这里将剩余的元素放入RES中, 类似归并算法
	while (pa != A.tu) {
		EnterTriple(RES.base[pr], A.base[pa].r, A.base[pa].c, A.base[pa].d);
		pa++; pr++;
	}
	while (pb != B.tu) {
		EnterTriple(RES.base[pr], B.base[pb].r, B.base[pb].c, B.base[pb].d);
		pb++; pr++;
	}
	RES.tu = pr;	// 更新RES中非零元素
	return RES;
}

int main() {
	// 程序逻辑 读取AB->相加C=A+B->输出C
	int r, c;
	TSMatrix A, B, C;
	scanf("%d %d",&r,&c);
	A.mu = B.mu = r; A.nu = B.nu = c;

	input(A); input(B);
	C = MatrixAddition(A, B);
	output(C);
	return 0;
}