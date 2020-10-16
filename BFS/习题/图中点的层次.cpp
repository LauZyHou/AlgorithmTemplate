#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], idx; // 邻接表，存树 
int d[N]; // 从1号点扩展的距离
int q[N]; // 队列，存树的结点 

// 添加边 
void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

// BFS搜索从1号点到n号点的最短距离
int bfs() {
	int hh = 0, tt = -1; // 队头队尾
	q[++ tt] = 1; // 入队1号点
	
	memset(d, -1, sizeof d); // 距离都初始化为-1 
	d[1] = 0; // 1号点到自己距离是0
	
	while (hh <= tt) {
		int v = q[hh ++]; // 出队一个点
		// 遍历所有出边
		for (int i = h[v]; i != -1; i = ne[i]) {
			// 对面的结点
			int j = e[i];
			if (d[j] == -1) { // 没访问过 
				d[j] = d[v] + 1; // 计算距离
				q[++ tt] = j; // 入队 
			} 
		} 
	}
	
	return d[n];
} 


int main() {
	scanf("%d%d", &n, &m);
	
	// 清空邻接表 
	memset(h, -1, sizeof h);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b);
	}
	
	printf("%d", bfs());
	
	return 0;
}
