#include<stdio.h>
#include<malloc.h>
typedef struct BiNode
{
	int data;
	struct BiNode* lc, * rc;
}BiNode, * BiTree;
// 重构二叉树
BiTree rebuild(int post[], int in[], int len, BiTree& T)
{
	// 长度为0时，递归退出
	if (len == 0)
		return NULL;
	// 根结点
	T = (BiTree)malloc(sizeof(BiNode));
	int root = post[len - 1];
	T->data = root;
	// 寻找root在in的位置
	int p = 0;
	for (; p < len; p++)
		if (in[p] == root)
			break;
	// 递归
	T->lc = rebuild(post, in, p, T->lc);
	T->rc = rebuild(&post[p], &in[p + 1], len - p - 1, T->rc);
	return T;
}

void output(BiTree T)
{

}

int main()
{
	int n;
	int postorder[50];	// 后序排列
	int inorder[50];	// 中序排列
	// 输入
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &postorder[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &inorder[i]);

	BiTree T = NULL;
	rebuild(postorder, inorder, 7, T);
	output(T);
	return 0;
}