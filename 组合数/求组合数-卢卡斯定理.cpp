#include <iostream>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/957/1/

当a和b规模很大，但查询次数不多时可以用卢卡斯定理来求组合数 
C_a^b = C_{a % p}^{b % p} * C_{a / p}^{b / p}
因为查询次数不多，不用给组合数打表，只要每次用定义计算就行了 
*/

typedef long long LL; 

// 快速幂，这题里用来求逆元
int qmi(int a, int k, int p) {
	int res = 1;
	while (k) {
		if (k & 1)
			res = (LL)res * a % p;
		k >>= 1;
		a = (LL)a * a % p; 
	}
	return res;
} 

// 根据定义求C_a^b模p的结果 
int C(int a, int b, int p) {
	if (b > a)
		return 0;
	int res = 1;
	// C_a^b = a*(a-1)*...*(a-b+1) / b!
	// 上下都是b项，循环b次就行了
	for (int i = 1, j = a; i <= b; i ++, j --) {
		res = (LL)res * j % p;
		// 因为是带模p的，这里除法用对p的逆元来做 
		res = (LL)res * qmi(i, p - 2, p) % p;
	}
	return res;
}

// 卢卡斯定理求C_a^b模p的结果 
int lucas(LL a, LL b, int p) {
	// 如果a和b都比p还小，卢卡斯定理第二项是1，第一项就是C_a^b，直接求
	if (a < p && b < p)
		return C(a, b, p);
	// 卢卡斯定理第一项的ab取模之后一定比p小，直接求组合数
	// 卢卡斯定理第二项的ab除法之后可能还是很大，要继续用卢卡斯定理求 
	return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		LL a, b;
		int p; // 模数 
		scanf("%lld%lld%d", &a, &b, &p);
		printf("%d\n", lucas(a, b, p));
	}
	
	return 0;
} 
