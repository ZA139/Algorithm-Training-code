#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	double i;
	for ( i = 0; i!=10; i+=0.1)
		printf("%.1f\n", i);
	system("pause");
	return 0;
}