#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/879/
*/

// 扩展欧几里得算法
// 从引用返回使得ax+by=gcd(a,b)的x和y
// 从返回值返回gcd(a,b) 
int exgcd(int a, int b, int &x, int &y) {
	// b等于0时，gcd(a,b)=a，x取1，y取0 
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	// b不等于0时，先求b和a%b的gcd，同时计算的x和y使得
	// by + (a%b)x = gcd(b, a%b) = gcd(a, b)
	int d = exgcd(b, a % b, y, x);
	// 因为 a % b 等于a - (a/b)*b，这里(a/b)是下取整 
	// 所以by + [a - (a/b)*b]x = gcd(a, b)
	// 所以ax + b[y - (a/b)x] = gcd(a, b)
	// 所以a的系数就是x没错，b的系数是y - (a/b)x
	y = y - (a/b)*x;
	return d;
}

int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int a, b, x, y;
		scanf("%d%d", &a, &b);
		
		exgcd(a, b, x, y);
		printf("%d %d\n", x, y);
	}
	
	return 0;
}
