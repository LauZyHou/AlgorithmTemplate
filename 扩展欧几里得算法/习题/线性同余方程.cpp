#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/880/

typedef long long LL;


int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int a, b, m;
		scanf("%d%d%d", &a, &b, &m);
		int x, y;
		int d = exgcd(a, m, x, y);
		if (b % d)
			puts("impossible");
		else
			printf("%d\n", (LL)x * (b / d) % m);
	}
	return 0;
}
