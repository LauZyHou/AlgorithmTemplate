#include <iostream>

using namespace std;

const int N = 1010;

// https://www.acwing.com/problem/content/2/
// 因为dp[i][j]总是从dp[i-1][x]转移来的，所以可以不要这一维
// 但是要注意必须反向遍历体积，这样才能保证f[j-v[i]]是i-1时候的，而不会先变成dp[i][j-v[i]] 

int v[N], w[N];
int f[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", v + i, w + i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = m; j >= v[i]; j --)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	
	printf("%d\n", f[m]);
	
	return 0;
}
