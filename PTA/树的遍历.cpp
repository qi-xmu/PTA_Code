#include<stdio.h>
#include<malloc.h>
typedef struct BiNode
{
	int data;
	struct BiNode* lc, * rc;
}Bitree;

int postorder[50];	// 后序排列
int inorder[50];	// 中序排列


int rebuild(int postBegin,int postEnd,int inBegin,int inEnd)
{
	if (postBegin > postEnd || inBegin > inEnd)
		return 0;
	// 根结点
	int root = postorder[postEnd];

	int lenL,lenR,position;
	for (int i = inBegin; i <= inEnd; i++)
	{
		if (inorder[inBegin + i] == root)
		{
			position = i;
			break;
		}
	}

	return root;
}

int main()
{
	int n;

	// 输入
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &postorder[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &inorder[i]);
	}
	Tree T;
	rebuild(1, 1, n, 1);

	printf("%d", T->data);
	Tree left = T->lc;
	Tree right = T->rc;
	while (1)
	{
		printf("%d %d", left->lc);

	}
	return 0;
}