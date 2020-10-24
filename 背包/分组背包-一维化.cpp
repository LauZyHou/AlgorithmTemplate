#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/description/9/

只要考虑每组里面选哪一个或者不选就行了 
*/

const int N = 110;

// 第i组的第j个物品 
int v[N][N], w[N][N];

// 第i组物品有多少个
int s[N]; 

// 一维化的dp数组
int f[N]; 

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++) {
		scanf("%d", s + i);
		for (int j = 0; j < s[i]; j ++) {
			scanf("%d%d", &v[i][j], &w[i][j]);
		}
	}
	
	// 一维化的背包，对每一组 
	for (int i = 1; i <= n; i ++) {
		// 对每个体积j
		for (int j = m; j >= 0; j --) {
			// 对组里的第k个物品
			for (int k = 0; k < s[i]; k ++) {
				// 仅当这个物品的体积不超过j时才能算
				if (v[i][k] <= j)
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]); 
			}
		} 
	}
	
	printf("%d\n", f[m]);
	
	return 0;
} 
