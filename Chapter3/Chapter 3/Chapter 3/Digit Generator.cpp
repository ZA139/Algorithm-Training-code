#include<stdio.h>
#include<string.h>
#define maxn 100005
int ans[maxn];
int main(void)
{
	memset(ans, 0, sizeof(ans));
	int T, n;
	for (int i = 1; i < maxn; i++)
	{
		int x = i, y = i;
		while (x > 0)
		{
			y += x % 10;
			x /= 10;
		}
		if (ans[y] == 0 || ans[y] > i)
		{
			ans[y] = i;
		}
	}
		scanf("%d", &T);
		while (T--)
		{
			scanf("%d", &n);
			printf("%d\n", ans[n]);
		}
	
	return 0;
}