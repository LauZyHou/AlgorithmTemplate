#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/284/

const int N = 310;

int s[N]; // 前缀和 
int f[N][N]; // f[i][j]表示合并区间[i,j]的石子最小代价 

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i ++ )
		scanf("%d", s + i);
	
	for (int i = 1; i <= n; i ++ ) // 预处理前缀和
		s[i] += s[i - 1];
	
	// 从小到大枚举区间长度，因为区间长度是1的时候合并代价一定是0，所以从2开始 
	for (int len = 2; len <= n; len ++ )
		for (int i = 1; i + len - 1 <= n; i ++ ) {
			int j = i + len - 1; // 区间右端点
			f[i][j] = 1e8; // 计算之前变成一个比较大的数这样才能求min求下来
			// 枚举分界点k
			for (int k = i; k <= j - 1; k ++ )
				// 合并[i..k]合并[k+1..j]后再合并这两个区间的代价 
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]); 
		} 
	
	printf("%d\n", f[1][n]);
	 
	return 0;
} 
