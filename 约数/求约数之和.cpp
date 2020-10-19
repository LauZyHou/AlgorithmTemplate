#include <iostream>
#include <unordered_map>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/940/1/

如果一个数表示成X=p1^a1+p2^a2+...+pn^an
那么约数之和就是(p1^0+p1^1+...+p1^a1)*(p2^0+p2^1+...+p2^a2)*...*(pn^0+pn^1+...+pn^an) 
因为每个约数pi可以选0到ai一共ai+1种可能，展开之后的每一项p1^k1 * p2^k2 * ... * pn^kn都是一个约数 
*/

typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
	// 这题给了若干个数，要求他们乘积的约数之和 
	// 求乘积的约数个数，就可以求每个数分解质因数，分解结果存下来p->a，然后再用上面的公式
	int n;
	scanf("%d", &n);
	
	unordered_map<int, int> primes;
	
	while (n --)
	{
		int x;
		scanf("%d", &x);
		// 分解质因数 
		for (int i = 2; i <= x / i; i ++)
		{
			while (x % i ==0)
			{
				x /= i;
				primes[i] ++;
			}
		}
		if (x > 1)
			primes[x] ++;
	}
	
	// 至此哈希表里存了每一对p->a 
	// 对每一个都要计算p^0+p^1+...+p^a 
	
	LL ans = 1;
	for (auto prime : primes)
	{
		int p = prime.first;
		int a = prime.second;
		// t = 1
		// t = p + 1
		// t = p^2 + p + 1
		// t = p^3 + p^2 + 1
		// 循环a次即可
		LL t = 1;
		while (a --) {
			t = (t * p + 1) % mod;
		}
		// 加到ans里
		ans = ans * t % mod; 
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
