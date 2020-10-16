#include <iostream>
#include <cstring>

using namespace std;

/*
https://www.acwing.com/problem/content/850/

DAG（有向无环图）存在拓扑序，也叫拓扑图 
BFS可以用来在DAG上求拓扑序 
从入度为0的点开始，入队
枚举队头元素的所有出边t->j，删掉这个出边
这会影响j的入度，即d[j]--
如果j的入度是0了，就可以入队了 
*/

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx; // 邻接表
int d[N]; // 入度
int q[N]; // 队列 

int n, m;

void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
	// 维护入度
	d[b] ++; 
}

// 拓扑排序，返回拓扑序是否存在 
bool toposort() {
	int hh = 0, tt = -1;
	
	// 将所有入度为0的点入队
	for (int i = 1; i <= n; i ++) {
		if (!d[i])
			q[++ tt] = i;
	}
	
	// 拓扑排序过程
	while (hh <= tt) {
		int t = q[hh ++];
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i]; // t -> j 
			// 入度减少，而不用真的删除这条边
			d[j] --;
			if (!d[j]) // 减少到0时入队
				q[++ tt] = j; 
		}
	}
	
	// 所有结点都入队了，那么就是存在拓扑序的
	return tt == n - 1; 
}

int main() {
	scanf("%d%d", &n, &m);
	
	memset(h, -1, sizeof h);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b);
	}
	
	if (toposort()) {
		// 存在时，队列的入队顺序就是拓扑序
		for (int i = 0; i < n; i ++)
			printf("%d ", q[i]); 
	}
	else {
		puts("-1");
	}
	
	return 0;
}

