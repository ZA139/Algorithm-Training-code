#include<stdio.h>
#include<string.h>
int main(void)
{
	int T = 0;
	scanf("%d", &T);
	while (T--&&T <= 20)
	{
		char buff[10];//题目中对于N的限制为10000，所以至少要开到7，习惯性稍微开大一点
		int first = 1;//初始化first来输出格式
		int counts[11] = { 0 };//储存每个数字出现次数的答案数组
		memset(buff, 0, sizeof(buff));//每组CASE重置buffer（安全起见）
		int n = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			sprintf(buff, "%d", i);
			//因为sprintf函数每次调用是会初始化数组并且输入数据的，所以要用循环写入
			for (int i = 0; i < 6; i++)//因为N<10000,所以小于六够用了
			{
				counts[buff[i] - '0']++;//buff[i]的ASCII码减去'0'则为buff[i]的十进制值
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (first)//首个答案直接输出，不需要输出空格
			{
				printf("%d", counts[i]);
				first = 0;
			}
			else
				printf(" %d", counts[i]);//注意该处有空格
		}
		printf("\n");
	}
	return 0;
}
