#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/845/
// 这是一种原始的逐位置的思路，在n-皇后里没考虑每行只能放一个这个信息
// 直接用逐行版就行了 

const int N = 10;

char g[N][N];
bool row[N], col[N], dg[2 * N], udg[2 * N];

int n;

// 从<x,y>位置继续搜索，已经放了s个皇后 
void dfs(int x, int y, int s) {
	// 如果列都遍历完了，就加上一行，并继续从第0列开始 
	if (y == n) {
		y = 0;
		x ++;
	}
	// 如果行数到了n，那么就要考虑回退了 
	if (x == n) {
		// 如果n个皇后都放完了，就找到了一个解 
		if (s == n) {
			for (int i = 0; i < n; i ++)
				puts(g[i]);
			puts("");
			return ;
		}
		return ;
	}
	// 在<x,y>位置不放皇后的情况
	dfs(x, y + 1, s);
	// 在<x,y>位置尝试放皇后的情况
	if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
		g[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
		dfs(x, y + 1, s + 1); // 继续本行的下一列
		g[x][y] = '.';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			g[i][j] = '.';
	
	// 从0行0列位置开始，已经放了0个皇后 
	dfs(0, 0, 0);
	
	return 0;
} 
