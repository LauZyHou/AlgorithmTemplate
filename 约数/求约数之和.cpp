#include <iostream>
#include <unordered_map>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/940/1/

���һ������ʾ��X=p1^a1+p2^a2+...+pn^an
��ôԼ��֮�;���(p1^0+p1^1+...+p1^a1)*(p2^0+p2^1+...+p2^a2)*...*(pn^0+pn^1+...+pn^an) 
��Ϊÿ��Լ��pi����ѡ0��aiһ��ai+1�ֿ��ܣ�չ��֮���ÿһ��p1^k1 * p2^k2 * ... * pn^kn����һ��Լ�� 
*/

typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
	// ����������ɸ�����Ҫ�����ǳ˻���Լ��֮�� 
	// ��˻���Լ���������Ϳ�����ÿ�����ֽ����������ֽ���������p->a��Ȼ����������Ĺ�ʽ
	int n;
	scanf("%d", &n);
	
	unordered_map<int, int> primes;
	
	while (n --)
	{
		int x;
		scanf("%d", &x);
		// �ֽ������� 
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
	
	// ���˹�ϣ�������ÿһ��p->a 
	// ��ÿһ����Ҫ����p^0+p^1+...+p^a 
	
	LL ans = 1;
	for (auto prime : primes)
	{
		int p = prime.first;
		int a = prime.second;
		// t = 1
		// t = p + 1
		// t = p^2 + p + 1
		// t = p^3 + p^2 + 1
		// ѭ��a�μ���
		LL t = 1;
		while (a --) {
			t = (t * p + 1) % mod;
		}
		// �ӵ�ans��
		ans = ans * t % mod; 
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
