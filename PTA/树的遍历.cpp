#include<stdio.h>
#include<malloc.h>
typedef struct BiNode
{
	int data;
	struct BiNode* lc, * rc;
}BiNode, *BiTree;

int rebuild(int post[],int in[],int len, BiTree T)
{

	// �����
	int root = post[len];
	T->data = root;
	// Ѱ��root��in��λ��
	int p = 0;
	for (; p < len; p++)
	{
		if (in[p] == root)
			break;
	}
	T->lc = (BiTree)(sizeof(BiNode));
	rebuild(post, in, p, T->lc);
	T->rc = (BiTree)(sizeof(BiNode));
	rebuild(&post[len], &in[len + 1], len - p,T->rc);

	return root;
}

int main()
{
	int n;
	int postorder[50];	// ��������
	int inorder[50];	// ��������
	// ����
	scanf("%d", &n);

	//BiTree T;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &postorder[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &inorder[i]);
	}
	
	return 0;
}