#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/4/

只是相比完全背包多了数量限制，朴素版很容易 
*/

const int N = 110;

int v[N], w[N], s[N];
int dp[N][N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d%d%d", v + i, w + i, s + i);
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			// 下面这行也可以并到k的循环里，让k从0开始就行了 
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= s[i] && k * v[i] <= j; k ++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
		}
	}
	
	printf("%d\n", dp[n][m]);
	
	return 0;
}
