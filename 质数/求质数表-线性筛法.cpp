#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/870/

����ɸ���ĺ�����ÿ����iֻ�ᱻ������С������ɸ�� 
ÿ�δ���������һ��һ�����Ե�ǰ����ɸ��
�����ǰ����%�����������Ϊ0����i % primes[j] == 0��˵��primes[j]����i����С������
����<=��С��������primes[j]����һ��i֮���������С������������primes[j]
������Щ����prime[j]��������ʱɸ�����������primes[j]*i����С�����Ͳ���primes[j]�� 
����ɸ����ʱ�临�Ӷ���O(n) 
*/

const int N = 1e6 + 10;

int cnt; // �ҵ�����������
int primes[N]; // ������
bool st[N]; // �Ƿ�ɸ��

void get_primes(int n)
{
	// ������2��n 
	for (int i = 2; i <= n; i ++)
	{
		// ���û��ɸ������¼
		if (!st[i])
			primes[cnt ++] = i;
		// ����ɸ������Ϊ�˷�ֹprimes[j]*i���������primes[j]���Ͻ���n/i
		for (int j = 0; primes[j] <= n / i; j ++)
		{
			// ��primes[j] * iɸ������Ϊ������С����������primes[j]
			st[primes[j] * i] = true;
			// ���primes[j]�Ѿ���i��(��)�����ˣ��ͽ�����ȥ������һ��i 
			// ��i�Ǻ���ʱ��primes[j]ö�ٵ�i����С�����Ӿ�ͣ��
			// ��iʱ����ʱ��primes[j]ö�ٵ�i��ͣ�� 
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
