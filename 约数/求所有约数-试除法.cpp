#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://www.acwing.com/problem/content/871/

���d������n����ôn/dҲ������n 
����Լ���ǳɶԳ��ֵģ�ֻ��Ҫö�ٵ�����n 
ʱ�临�Ӷ�O(����n) 
*/

vector<int> get_divisors(int n)
{
	vector<int> res;
	for (int i = 1; i <= n / i; i ++)
	{
		if (n % i == 0)
		{
			res.push_back(i);
			// �����ֹi��n/iһ������ΪֻҪ��һ��
			if (n / i != i)
				res.push_back(n / i); 
		}
	}
	sort(res.begin(), res.end());
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	while (n --)
	{
		int x;
		scanf("%d", &x);
		auto res = get_divisors(x);
		for (int v : res) {
			printf("%d ", v);
		}
		puts("");
	}	
	
	return 0;
}
