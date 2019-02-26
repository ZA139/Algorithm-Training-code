#include<stdio.h>
#include<string.h>
int main(void)
{
	int a[10] = { 1,1,1,1,1,1,1,1,1,1 };
	for ( int i = 0; i <10; i++)
	{
		printf("%d\n", a[i]);
	}
	memset(a, 5, sizeof(a));
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
	getchar();
	return 0;
}