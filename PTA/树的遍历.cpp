#include<stdio.h>
#include<malloc.h>
typedef struct BiNode
{
	int data;
	struct BiNode* lc, * rc;
}BiNode, *BiTree;
// �ع�������
BiTree rebuild(int post[],int in[],int len, BiTree &T)
{
	// ����Ϊ0ʱ���ݹ��˳�
	if (len == 0)
		return NULL;

	// �����
	T = (BiTree)malloc(sizeof(BiNode));
	int root = post[len-1];
	T->data = root;
	// Ѱ��root��in��λ��
	int p = 0;
	for (; p < len; p++)
	{
		if (in[p] == root)
			break;
	}

	// 
	T->lc=rebuild(post, in, p, T->lc);
	T->rc = rebuild(&post[p], &in[p + 1], len - p - 1, T->rc);
	return T;
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
	BiTree T = NULL;
	rebuild(postorder, inorder, 7, T);
	
	return 0;
}