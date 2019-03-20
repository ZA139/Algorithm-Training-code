#include<stdio.h>
#include<string.h>
int a[25], n, k, m;
int go(int p, int dir, int step)
{
	while (step--)
	{
		do {
			p = (p + dir+n-1) % n+1;
			/*
			+n目的为防止出现负数（+n%n后不影响p的数值）
			-1后+1：因为当p+dir==n时，取余后值为0，但实际值应为n，故加入此步
			*/
		} while (a[p] == 0);
    }
	return p;
}
int main(void)
{
	memset(a, 1, sizeof(a));
	while (scanf("%d%d%d",&n,&k,&m)==3&&n)
	{
		for (int i = 1; i<=n; i++)
		{
			a[i] = i;
		}//编号
		int left = n, p1 = n, p2 = 1;//题目中说是数k个，则第一个为1，不是2，故p1=n,p2=1开始数
		while (left)
		{
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			printf("%3d", p1);
			left--;
			if (p1 != p2)
			{
				printf("%3d", p2);//题目中：Note: The symbol ⊔ in the Sample Output below represents a space.
				left--;
			}
			a[p1] = a[p2] = 0;
			if (left)
				printf(",");
		}
		printf("\n");
	}
	return 0;
}