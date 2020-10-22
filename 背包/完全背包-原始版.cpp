#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/3/

dp[i][j]和01背包时候一样，还是表示只考虑前i个物品，且总体积不大于j的所有选法数量 
但是01背包里只能选一个或者不选，所以这个集合可以拆成两个集合
完全背包里可以选任意多个，所以这个集合也可以拆成多个集合： 
第i个物品选0个、选1个、选2个、选3个、... 
第i个物品选了k个就是：f[i-1][j-k*v[i]] + k*w[i]，显然k*v[i]<=j才行 
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
		for (int j = 1; j <= m; j ++)
			for (int k = 0; k * v[i] <= j; k ++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
	
	printf("%d\n", dp[n][m]);	
	
	return 0;
}
