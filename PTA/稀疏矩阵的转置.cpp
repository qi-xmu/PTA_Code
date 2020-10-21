#include<stdio.h>

#define MAXSIZE 1001

typedef struct {
	int r, c, d;	// 行, 列, 数据
}Triple;
typedef struct {
	Triple base[MAXSIZE + 1];	// 顺序结构
	int mu, nu, tu;				// 行, 列, 非零项
}TSMatrix;

// 输入T矩阵
int input(TSMatrix& T)
{
	for (int i = 0; i < T.tu; i++)
		scanf("%d %d %d", &T.base[i].r, &T.base[i].c, &T.base[i].d);
	return 0;
}
// 输出T矩阵
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
// 把r,c,d放到结点A中
void EnterTriple(Triple& A, int r, int c, int d)
{
	A.r = r; A.c = c; A.d = d;
	return;
}
// 转置M矩阵,并放在T中
int TransposeMatrix(TSMatrix M,TSMatrix& T)
{
	T.mu = M.mu; T.nu = M.nu; T.tu = M.tu;
	int num[1001] = { 0 };		// 统计各个列的数量
	int position[1001] = { 0 };	// 根据num计算各个元素的起始位置
	if (T.tu)
	{
		// 统计
		for (int c = 0; c < M.tu; c++)
			num[M.base[c].c]++;
		// 计算位置
		position[0] = 0;
		for (int i = 1; i < M.nu; i++)
			position[i] = position[i - 1] + num[i - 1];
		// 把对应元素放进对应位置
		for (int i = 0; i < M.tu; i++)
		{
			int Col = M.base[i].c;
			EnterTriple(T.base[position[Col]], M.base[i].c, M.base[i].r, M.base[i].d);
			position[Col]++;	// 放入后相应位置指针加一
		}
	}
	return 0;
}

int main()
{
	// 程序逻辑 读取->转置->输出
	TSMatrix M, T;
	scanf("%d %d %d", &M.mu, &M.nu, &M.tu);
	input(M);
	TransposeMatrix(M,T);
	output(T);
	return 0;
}