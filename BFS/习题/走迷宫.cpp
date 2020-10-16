#include <iostream>
#include <cstring>
using namespace std;

// https://www.acwing.com/problem/content/846/
// 因为移动一个位置距离总是一样的，所以可以直接BFS找最短路 

typedef pair<int, int> PII;

const int N = 1e2 + 5;

// 迷宫 
int g[N][N];

// 待访问的点的队列
PII q[N * N];

// 每个点遍历到时候的步数
int d[N][N]; 

int n, m;

// 广搜返回结果
int bfs() {
	// 步数先都变成-1，表示没遍历过
	memset(d, -1, sizeof d); 
	// 队头，队尾 
	int hh = 0, tt = -1;
	// 将起始点<0,0>入队
	q[++ tt] = {0, 0};
	// 起始点的遍历步数是0 
	d[0][0] = 0;
	
	// 四个方向
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	// 队列不为空时就一直遍历
	while (hh <= tt) {
		// 取队头点 
		auto t = q[hh ++];
		// 遍历其四周的四个位置
		for (int i = 0; i < 4; i ++) {
			// 新位置的x和y
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			// 如果在范围内，且没遍历过，就要遍历并记录一下距离，然后入队
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
				d[x][y] = d[t.first][t.second] + 1;
				q[++ tt] = {x, y};
			} 
		} 
	} 
	
	// 最后返回的就是走到右下角的距离
	return d[n - 1][m - 1]; 
} 

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			scanf("%d", &g[i][j]);
	
	printf("%d", bfs());
	
	return 0;
}
