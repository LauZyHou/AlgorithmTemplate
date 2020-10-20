#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/206/
// 这题是表达整数的奇怪方式，就是各个m不互质版的中国剩余定理 

typedef long long LL;

const int N = 30;

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	LL d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}



int main() {
	int n;
	scanf("%d", &n);
	
	bool has_answer = true; // 是否有解
	// 接下来要每次将两个方程x = a1 (mod m1)和x = a2 (mod m2)合并到第一个里 
	LL a1, m1;
	scanf("%lld%lld", &a1, &m1);
	for (int i = 0; i < n - 1; i ++) {
		LL a2, m2;
		scanf("%lld%lld", &a2, &m2);
		
		// 合并过程，a1k1 - a2k2 = m1 - m2，当m1 - m2是gcd(a1, a2)的倍数时有解
		// 注意下面变量里的k2实际上是公式里的-k2，不过我们只关心k1 
		LL k1, k2;
		LL d = exgcd(a1, a2, k1, k2);
		// 判断是否有解
		if ((m1 - m2) % d) {
			has_answer = false;
			break;
		}
		
		// 由于exgcd求的是a1k1+a2k2=gcd(a1, a2)=d的k1和k2，所以这里要把k1乘相应的倍数 
		k1 *= (m2 - m1) / d;
		// 由于k1 +- 任意个a2/d也都是解，所以这里要变成解里面的最小正值
		// 也就是变成在模a2/d时和k1同余的最小正值
		int t = a2 / d;
		k1 = (k1 % t + t) % t;
		
		// 计算合并后的一个方程里的m1和a1
		m1 = a1 * k1 + m1;
		a1 = abs(a1 / d * a2); // a1变成a1和a2的最小公倍数正数 
	}

	if (has_answer)
		printf("%lld\n", (m1 % a1 + a1) % a1);
	else
		puts("-1");
	
	return 0;
}
