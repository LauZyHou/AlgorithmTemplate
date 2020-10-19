#include <iostream>
#include <unordered_map>

using namespace std;

/*
https://www.acwing.com/problem/content/872/

如果一个数表示成X=p1^a1+p2^a2+...+pn^an
那么约数个数就是(a1+1)*(a2+1)*...*(an+1) 
因为每个约数pi可以选0到ai一共ai+1种可能 
*/

typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
	// 这题给了若干个数，要求他们乘积的约数个数
	// 求乘积的约数个数，就可以求每个数分解质因数，分解结果存下来p->a，然后再用上面的公式
	int n;
	scanf("%d", &n);
	
	// 哈希表存质数->出现次数
	unordered_map<int, int> primes;
	
	while (n --)
	{
		int x;
		scanf("%d", &x);
		// 对每次读入的数分解质因数
		for (int i = 2; i <= x / i; i ++)
		{
			while (x % i == 0)
			{
				x /= i;
				primes[i] ++;	
			}
		}
		// 最后可能剩个大质数
		if (x > 1)
			primes[x] ++;
	}
	
	// 计算结果
	LL ans = 1;
	for (auto prime : primes)
		ans = ans * (prime.second + 1) % mod;
	
	printf("%lld\n", ans);
	
	return 0;
}
