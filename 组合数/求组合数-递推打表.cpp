#include <iostream>

using namespace std;

const int N = 2010, mod = 1e9 + 7; 

int c[N][N];

// 打表
void init() {
	for (int i = 0; i < N; i ++)
		for (int j = 0; j <= i; j ++) // C_i^j，j不能超过i
			if (!j)
				c[i][j] = 1; // 边界，取0个元素有一种情况
			else
				c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
}


int main() {
	init(); 
	
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", c[a][b]);
	}
	
	return 0;
} 
