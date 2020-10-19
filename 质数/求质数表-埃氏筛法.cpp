#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/870/

先把要求的范围2~n都写进来
从小到大把每个数的倍数都删掉
最后剩下的就是这个范围内的质数表 
当每次枚举到一个数时，如果它没有在前面的过程中被筛掉，它就是质数 
优化：不需要把每个数的倍数都筛一遍，只需要把质数的倍数都筛一遍 
优化前的时间复杂度是O(nlogn)，优化后是O(nloglogn) 
*/

const int N = 1e6 + 10;

int cnt; // 质数个数
int primes[N]; // 求得的质数数组
bool st[N]; // st[i]表示i有没有被筛掉

void get_primes(int n)
{
	for (int i = 2; i <= n; i ++)
	{
		if (!st[i]) // 没被筛掉 
		{
			primes[cnt ++] = i;
			// 筛它的所有倍数
			for (int j = i + i; j <= n; j += i)
				st[j] = true; 
		}
	}
} 


int main()
{
	int n;
	scanf("%d", &n);
	
	get_primes(n);
	printf("%d\n", cnt);

	return 0;
}
