#include <iostream>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/941/1/

欧几里得算法，也叫辗转相除法
如果d能整除a，d能整除b，那么d能整除ax+by
a和b的最大公约数，就等于b和a模b的最大公约数
即gcd(a, b)==gcd(b, a%b)，因为a%b能写成a-kb的形式 
时间复杂度O(logn) 
*/

int gcd(int a, int b) {
	// 当b不为0时返回b和a%b的最大公约数，当b是0时，a和0的最大公约数就是a 
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n --) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
 
