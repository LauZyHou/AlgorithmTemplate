#include <iostream>
#include <unordered_map>

using namespace std;

/*
https://www.acwing.com/problem/content/872/

���һ������ʾ��X=p1^a1+p2^a2+...+pn^an
��ôԼ����������(a1+1)*(a2+1)*...*(an+1) 
��Ϊÿ��Լ��pi����ѡ0��aiһ��ai+1�ֿ��� 
*/

typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
	// ����������ɸ�����Ҫ�����ǳ˻���Լ������
	// ��˻���Լ���������Ϳ�����ÿ�����ֽ����������ֽ���������p->a��Ȼ����������Ĺ�ʽ
	int n;
	scanf("%d", &n);
	
	// ��ϣ�������->���ִ���
	unordered_map<int, int> primes;
	
	while (n --)
	{
		int x;
		scanf("%d", &x);
		// ��ÿ�ζ�������ֽ�������
		for (int i = 2; i <= x / i; i ++)
		{
			while (x % i == 0)
			{
				x /= i;
				primes[i] ++;	
			}
		}
		// ������ʣ��������
		if (x > 1)
			primes[x] ++;
	}
	
	// ������
	LL ans = 1;
	for (auto prime : primes)
		ans = ans * (prime.second + 1) % mod;
	
	printf("%lld\n", ans);
	
	return 0;
}
