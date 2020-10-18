#include <iostream>

using namespace std;


/*
https://www.acwing.com/problem/content/856/

Floyd算法用于求多源汇最短路，用邻接矩阵存图 
设dp[k][i][j]表示从i到j，只允许经过1~k这些点的最短路
则dp[k][i][j] = min(dp[k][i][j], dp[k-1][i][k] + dp[k-1][k][j]) 
发现k每次都用之前的更新，只要先遍历k就不用k这个维度了 
*/

const int N = 2e2 + 10;
const int M = 2e4 + 10;

// 刚开始是存图的两两边之间的距离
// Floyd跑过之后是存两两点之间的最短路 
int d[N][N];


const int INF = 1e9;

int n, m, q;

int floyd() {
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
	
	while (m --) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		d[x][y] = min(d[x][y], z);
	}
	
	floyd();

	while (q --) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (d[x][y] > INF / 2) // INF边有可能被负边更新 
			puts("impossible");
		else
			printf("%d\n", d[x][y]);
	}
	
	return 0;
}
