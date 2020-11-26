#include<stdio.h>

int dependents[105][105] = { 0 };
int indegree[105] = { 0 };

bool isSatisfied()
{
	int stack[107] = { 0 };
	int top = 0;
	for (int i = 1; i <= dependents[0][0]; i++)
		if (!indegree[i])
			stack[++top] = i;
	int count = 0;
	while (top != 0)
	{
		int t=stack[top--]; count++;
		for (int p = 1; p <= dependents[t][0]; p++)
		{
			int adjvex = dependents[t][p];
			if (!(--indegree[adjvex]))
				stack[++top] = adjvex;
		}
	}
	if (count < dependents[0][0])
		return false;
	else 
		return true;
}
int main()
{
	int N = 0;
	// ÊäÈë²¿·Ö
	scanf("%d", &N);
	dependents[0][0] = N;
	for (int num = 1; num <= N; num++)
	{
		int K = 0;
		scanf("%d", &K);
		if (K == 0)
			continue;
		dependents[num][0] = K;
		for (int i = 1; i <= K; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			dependents[num][i] = tmp;
			indegree[tmp]++;
		}
	}
	if(isSatisfied())
		printf("1");
	else
		printf("0");
	return 0;
}