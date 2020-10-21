#include<stdio.h>
#include<malloc.h>
typedef struct BiNode
{
	int data;
	struct BiNode* lc, * rc;
}Bitree;

int rebuild(int post[],int in[],int len)
{
	// 根结点
	int root = post[len];


	return root;
}

int main()
{
	int n;
	int postorder[50];	// 后序排列
	int inorder[50];	// 中序排列
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
	
	return 0;
}