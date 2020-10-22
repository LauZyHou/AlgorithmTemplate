#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/2/

01背包原始版
n个物品，每个的体积是v[i]，价值权重是w[i] 
dp[i][j]：只考虑前i个物品，且总体积不大于j的所有选法数量 
*/


const int N = 1010;

int v[N], w[N];

int dp[N][N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", v + i, w + i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= v[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
		}
	
	printf("%d\n", dp[n][m]);
	
	return 0;
} 
