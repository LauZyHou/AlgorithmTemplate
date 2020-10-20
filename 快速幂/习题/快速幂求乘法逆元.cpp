#include <iostream>

using namespace std;

typedef long long LL;

int qmi(LL a, int k, int p) {
	LL res = 1;
	while (k) {
		if (k & 1)
			res = res * a % p;
		k >>= 1;
		a = a * a % p;
	}
	return res;
}


int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int b, m;
		scanf("%d%d", &b, &m);
		if (b % m == 0)
			puts("impossible");
		else
			printf("%d\n", qmi(b, m - 2, m));
	}
	
	return 0;
} 
