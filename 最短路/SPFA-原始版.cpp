#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

/*
https://www.acwing.com/problem/content/853/

SPFA是用宽搜的思想对Bellman-Ford算法做了优化
因为Bellman-Ford算法中的 dist[b] = min(dist[b], _dist[a] + w)
不一定每次都会执行
仅当dist[a]变小时候，dist[a]+w才会变小，那么dist[b]才可能被更新
否则上一轮没更新，这一轮也不会更新，可以用一个队列来记录上一轮更新的点

用一个队列queue来维护所有变小了的结点，只有它的出边需要更新
核心流程：
先将源点1入队queue
while queue不空
	取出队头结点t
	更新t的所有出边（从t到b，距离是w）
	如果这个出边确实更新了，将b入队（因为dist[b]变小了，所以下一轮从b出发的要被更新） 

时间复杂度 一般O(m)，最坏O(nm) ，数据结构用邻接表或者邻接矩阵 
*/

const int N = 1e5 + 10;

int n, m;

// 邻接表
int h[N], e[N], ne[N], idx, w[N];

// 添加边
void add_edge(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
} 

bool st[N]; // 存某个点有没有在队列里，防止重复入队 

int dist[N];

// spfa求从1号点到n号点的最短路 
int spfa() {
	// 初始化dist
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	// 队列存要用来更新其它点的点
	queue<int> q;
	q.push(1); // 源点
	st[1] = true;

	while (q.size()) {
		int t = q.front();
		q.pop();
		st[t] = false;
		
		// 遍历从t出发的所有边
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[t] + w[i] < dist[j]) {
				dist[j] = dist[t] + w[i];
				if (!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}		
	}
	
	if (dist[n] == 0x3f3f3f3f)
		return -1;
	return dist[n];
}

int main() {
	scanf("%d%d", &n, &m);
	
	// 清空邻接表
	memset(h, -1, sizeof h);
	
	while (m --) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add_edge(x, y, z);
	}
	
	int t = spfa();
	if (t == -1)
		puts("impossible");
	else
		printf("%d", t);
	
	return 0;
}
