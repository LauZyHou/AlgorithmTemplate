#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

/*
https://www.acwing.com/problem/content/854/

dist[j]记录源点到j点的当前最短路长度
cnt[j]记录这个最短路的边数

从t点到j点，边权是c，则更新时：
dist[j] = dist[t] + c
cnt[j] = cnt[t] + 1

只要某个cnt[j] >= n，则由抽屉原理知有回路了，就一定有负回路了 

注意初始时要把所有点都放到队列里，因为这些点不一定是联通的
要检查的是从任何一个点出发有没有负环 
*/

const int N = 2e3 + 10;
const int M = 1e4 + 10;

int n, m;
int h[N], e[M], ne[M], idx, w[M];

void add_edge(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
}

int dist[N], cnt[N];
bool st[N];

// 返回有没有负环 
bool spfa() {
	// 判断负环时不用初始化dist了，都是0就行
	// 要把所有的点都加入要更新出边的队列
	queue<int> q;
	for (int i = 1; i <= n; i ++) {
		q.push(i), st[i] = true;
	}
	
	while (q.size()) {
		int t = q.front();
		q.pop(), st[t] = false;
		
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[t] + w[i] < dist[j]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n)
					return true;
				if (!st[j])
					q.push(j), st[j] = true;
			}
		}
	}
	return false;
}
 

int main() {
	memset(h, -1, sizeof h);
	
	scanf("%d%d", &n, &m);
	while (m --) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a, b, c);
	}
	
	if (spfa())
		puts("Yes");
	else
		puts("No");

	return 0;
}
