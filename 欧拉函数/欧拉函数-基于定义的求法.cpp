#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/875/

欧拉函数phi(n)是求1~n中与n互质的元素个数
如1~6中1、5两个数和6互质，所以phi(6)=2
解法： 
将n因式分解为n=p1^a1+p2^a2+...+pk^ak
则phi(n)=n(1-1/p1)(1-1/p2)...(1-1/pk)
例如n = 6 = 2 * 3
phi(6) = 6 * (1 - 1/2) * (1 - 1/3) = 2
*/

int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int x;
		scanf("%d", &x);
		
		int ans = x; // 求x的欧拉函数
		// 分解质因数
		for (int i = 2; i <= x / i; i ++)
			if (x % i == 0) { // 说明i是x的质因数 
				ans = ans / i * (i - 1); // 乘以(1 - 1/i)
				while (x % i == 0) // 把i除干净 
					x /= i; 
			}
		// 最后可能剩一个大质数
		if (x > 1)
			ans = ans / x * (x - 1);
		printf("%d\n", ans);
	}
	
	return 0;
}
