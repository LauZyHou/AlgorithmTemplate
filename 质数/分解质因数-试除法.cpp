#include <iostream>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/936/1/

枚举到根号n，如果能整除就是一个因子，把它除出来
最后可能还剩下一个大于根号n的质数，把它输出 
*/

// 每次枚举，当枚举到i时，就意味着已经把从2到i-1的所有数都除干净了
// 如果这个时候i还能作为n的因子，那么i一定是一个质数
void divide(int n)
{
	// n中最多只包含一个大于根号n的因子
	// 所以这里i只要遍历到根号n就行了 
	for (int i = 2; i <= n / i; i ++)
	{
		if (n % i == 0)
		{
			int s = 0; // i作为因子出现次数
			while (n % i == 0)
			{
				n /= i;
				s ++;
			}
			printf("%d %d\n", i, s);
		}
	}
	// 最后再判断n剩下的值是不是1，不是1就是那个剩下的唯一质数了
	if (n > 1)
		printf("%d 1\n", n); 
} 

int n;

int main()
{
	scanf("%d", &n);
	while (n --)
	{
		int a;
		scanf("%d", &a);
		divide(a);
		puts("");
	}
	
	return 0;
}
