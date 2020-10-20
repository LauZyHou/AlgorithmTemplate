#include <iostream>

using namespace std;

// 扩展欧几里得算法求ax+by=gcd(a, b)
int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

// 求b在模m时的乘法逆元，保证b和m互质 
int inv(int b, int m) {
	int x, y;
	exgcd(b, m, x, y); // bx + my = gcd(b, m)
	// 因为b和m互质，所以gcd(b, m) = 1
	// 所以bx % m = (bx + my) % m = 1 % m = 1
	// 所以x就是b的乘法逆元，这里将x变成0~m-1之间
	x = (x % m + m) % m;
	return x; 
}

const int N = 1e5 + 10;

// 假设已经定义了n个m[i]，它们是互质的 
// 并且也读入了同余方程组里的n个a[i]
int n, m[N], a[N];
// 中国剩余定理Chinese Remainer Theorem 
int CRT() {
	int M = 1, ans = 0;
	// 求M = m[i]乘积
	for (int i = 0; i < n; i ++)
		M *= m[i];
	// 计算同余方程组 x \equiv a[i] (mod m[i])的结果x
	// 它是所有的a[i] * Mi * Mi逆的加和 
	for (int i = 0; i < n; i ++) {
		int Mi = M / m[i];
		ans = (ans + a[i] * Mi * inv(Mi, m[i])) % M;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i ++)
		scanf("%d", &m[i]);
	printf("%d\n", CRT());
	return 0;
}
