#include<math.h>
#include<stdio.h>
int main(void)
{
	int i = 100;
	while (i<=999)
	{
		int a = 0, b = 0, c = 0;
		a = floor(i / 100);
		b = floor((i % 100) / 10);//floor((i-a*100)/10)
		c = i % 10;
		if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
			printf("%d\n", i);
		i++;
	}
	getchar();
	return 0;
}