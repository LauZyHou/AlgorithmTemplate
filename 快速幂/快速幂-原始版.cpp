#include <iostream>

using namespace std;


/*
https://www.acwing.com/problem/content/877/
	
快速幂可以快速求出a^k % p的结果，时间复杂度O(alogk)
其中a、p、k都在1e9的范围内
原始的暴力做法是把a乘上k次，每次模p，时间复杂度是O(k)的 
核心思路：反复平方 
*/

typedef long long LL;

int qmi(LL a, int k, int p) {
	LL res = 1;
	// 快速幂，每次取k的最低位，如果是1，那么相应的a^2^i项就要乘上去 
	// 初始时a^2^0就是a^1=a 
	while (k) { 
		if (k & 1)
			res = res * a % p;
		k >>= 1;
		a = a * a % p; // 每次都把这个项平方	 
	}
	return res;
}


int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int a, k, p; // a^k mod p
		scanf("%d%d%d", &a, &k, &p);
		printf("%d\n", qmi(a, k, p));
	}
	
	return 0;
}
