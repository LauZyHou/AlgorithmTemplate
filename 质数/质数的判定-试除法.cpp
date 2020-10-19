#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/868/

如果d能整除n，那么n/d也能整除n
即n的约数总是成对出现的
所以只需要枚举d <= n/d的数就够了
即只要枚举d <= 根号n，时间复杂度是O(根号n) 
*/

bool is_prime(int n) {
	if (n < 2)
		return false;
	// 不要写i*i <= n，因为当n比较接近INT_MAX时
	// i枚举过程中很可能溢出导致循环没法结束 
	// 也不要用sqrt(n)，因为每次求sqrt(n)也很慢 
	for (int i = 2; i <= n / i; i ++) {
		if (n % i == 0)
			return false;	
	}
	return true;
}

int n;

int main() {
	scanf("%d", &n);
	while (n --) {
		int a;
		scanf("%d", &a);
		if (is_prime(a))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
