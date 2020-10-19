#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://www.acwing.com/problem/content/871/

如果d能整除n，那么n/d也能整除n 
所以约数是成对出现的，只需要枚举到根号n 
时间复杂度O(根号n) 
*/

vector<int> get_divisors(int n)
{
	vector<int> res;
	for (int i = 1; i <= n / i; i ++)
	{
		if (n % i == 0)
		{
			res.push_back(i);
			// 这里防止i和n/i一样，因为只要放一次
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
