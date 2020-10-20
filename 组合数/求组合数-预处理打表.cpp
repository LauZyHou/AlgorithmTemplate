#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/888/

typedef long long LL;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

// 阶乘表和阶乘的逆元表 
int fact[N], infact[N];

// 快速幂
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

int main() {
	// 预处理打表
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i ++) {
		fact[i] = (LL)fact[i - 1] * i % mod;
		infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod; // 费马小定理 + 快速幂 
	}
	
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int a, b;
		scanf("%d%d", &a, &b);
		// 组合数C_a^b = a! / (a-b)! / b!
		printf("%d\n", (LL)fact[a] * infact[a-b] % mod * infact[b] % mod);
	}
	
	return 0;
}
