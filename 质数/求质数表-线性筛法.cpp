#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/870/

线性筛法的核心是每个数i只会被它的最小质因子筛掉 
每次从质数表里一个一个乘以当前的数筛掉
如果当前的数%质数表里的数为0，即i % primes[j] == 0，说明primes[j]就是i的最小质因数
所有<=最小质因数的primes[j]乘以一个i之后的数的最小质因数都还是primes[j]
所以这些都在prime[j]被遍历到时筛掉，再往后的primes[j]*i的最小质数就不是primes[j]了 
线性筛法的时间复杂度是O(n) 
*/

const int N = 1e6 + 10;

int cnt; // 找到的质数个数
int primes[N]; // 质数表
bool st[N]; // 是否被筛掉

void get_primes(int n)
{
	// 遍历从2到n 
	for (int i = 2; i <= n; i ++)
	{
		// 如果没被筛掉，记录
		if (!st[i])
			primes[cnt ++] = i;
		// 线性筛，这里为了防止primes[j]*i溢出，所以primes[j]的上界是n/i
		for (int j = 0; primes[j] <= n / i; j ++)
		{
			// 把primes[j] * i筛掉，因为它的最小质因数就是primes[j]
			st[primes[j] * i] = true;
			// 如果primes[j]已经是i的(质)因数了，就结束，去考察下一个i 
			// 当i是合数时，primes[j]枚举到i的最小质因子就停了
			// 当i时质数时，primes[j]枚举到i就停了 
			if (i % primes[j] == 0)
				break; 
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
