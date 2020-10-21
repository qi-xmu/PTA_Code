#include<stdio.h>

#define MAX_TREE 1000

void theCommonAncestor(int n, int tree[],int i,int j)
{
	int pi = i, pj = j;
	int ca = 0, cav = 0;
	while (1) {
		if (tree[pi] == 0)
		{
			printf("ERROR: T[%d] is NULL", pi);
			break;
		}
		if (tree[pj] == 0)
		{
			printf("ERROR: T[%d] is NULL", pj);
			break;
		}
		if (pi > pj)
		{
			pi = pi / 2;
		}
		else if (pi < pj) {
			pj = pj / 2;
		}
		else {
			ca = pi;
			cav = tree[ca];
			printf("%d %d", ca, cav);
			break;
		}
	}
}

int main()
{
	int n;
	int tree[MAX_TREE] = { 0 };
	int i, j;
	scanf("%d", &n);
	for (int a = 1; a <= n; a++)
	{
		scanf("%d", &tree[a]);
	}
	scanf("%d %d", &i, &j);
	theCommonAncestor(n, tree, i, j);
}