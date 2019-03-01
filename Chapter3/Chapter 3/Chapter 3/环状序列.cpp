#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 105

int compare(const char* s, int p, int q)
{
	int n = strlen(s);
	for (int  i = 0;  i <n;  i++)
	{
		if (s[(p + i )% n] != s[(q + i) % n])//从第i/p个位置开始比较字典序
			return s[(p + i )% n] < s[(q + i) % n];
	}
	return 0;
}
int main(void)
{
	int T = 0;
	scanf("%d", &T);
	while (T--)
	{
		char s[maxn] = { 0 };
		scanf("%s", s);
		int ans = 0;
		int n = strlen(s);
		for (int i = 0; i < n; i++)
		{
			if (compare(s, i, ans))
				ans = i;
		}
		for (int i = 0; i < n; i++)
		{
			putchar( s[(ans + i )% n]);
		}
		putchar('\n');
	}
	system("pasue");
	return 0;
}