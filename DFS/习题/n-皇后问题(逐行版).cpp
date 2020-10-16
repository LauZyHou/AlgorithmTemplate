#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/845/

const int N = 20;

char g[N][N]; // 棋盘 

bool col[N]; // 列被放置的情况 
bool dg[N], udg[N]; // 正向和反向的对角线使用情况 

int n;

// 按行dfs 
void dfs(int u) {
	// 找到解 
	if (u == n) {
		for (int i = 0; i < n; i ++)
			puts(g[i]);
		puts("");
		return ;
	}
	// 在该行的每个列j位置检查并放置皇后
	for (int j = 0; j < n; j ++)
		if (!col[j] && !dg[u + j] && !udg[u - j + n]) {
			g[u][j] = 'Q';
			col[j] = dg[u + j] = udg[u - j + n] = true;
			dfs(u + 1);
			g[u][j] = '.';
			col[j] = dg[u + j] = udg[u - j + n] = false;
		}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			g[i][j] = '.';
	
	dfs(0); // 按行dfs
	
	return 0; 
}
