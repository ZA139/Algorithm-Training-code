#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
void count(const char *b,int (&a)[26],int n)
{
	for (int i = 0; i < n; i++)
	{
		a[*(b+i) - 'A']++;
	}
}
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main(void)
{
	char s1[110], s2[110];
	int counts1[26], counts2[26];
	while (scanf("%s%s", s1, s2) == 2)
	{
		bool ok = true;
		memset(counts1, 0, sizeof(counts1));
		memset(counts2, 0, sizeof(counts2));
		count(s1, counts1, strlen(s1));
		count(s2, counts2, strlen(s2));
		qsort(counts1, 26, sizeof(int), cmp);
		qsort(counts2, 26, sizeof(int), cmp);
		for (int i = 0; i < 26; i++)
		{
			if (counts1[i] != counts2[i])
				ok = false;
		}
		if (ok)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}
	return 0;
}