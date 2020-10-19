#include <iostream>
#include <cstring>

using namespace std;

/*
https://www.acwing.com/problem/content/862/

一个图是二分图，当且仅当图中不含奇数环
如果在染色过程中没有矛盾就一定是二分图 

算法流程：
for (int i = 1; i <= n; i ++)
	if i未染色
		dfs(i, 1); // 把i染成1号颜色，继续深搜把i所在的连通块染色一遍 
*/

const int N = 1e5 + 10;
// 无向图每条边存两个方向所以开两倍
const int M = 2e5 + 10;

int n, m;

// 邻接表 
int h[N], e[M], ne[M], idx;

// 邻接表加边 
void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

// 记录染色情况：0没染色，1染了颜色1，2染了颜色2 
int color[N];

// 给连通块染色，返回染色过程中有没有矛盾
// 颜色只有两种：1和2
bool dfs(int u, int val) {
	// 给这个点染色
	color[u] = val; 
	// 对所有边
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i]; // 另一端的点
		// 如果j已经有和自己相同的颜色那么有错误
		if (color[j] == val)
			return false;
		// 如果给这个点染成另一个颜色过程中发生错误也要往上传
		if (!color[j] && !dfs(j, 3 - val))
			return false; 
	}
	return true;
} 

int main() {
	scanf("%d%d", &n, &m);
	
	// 清空链表
	memset(h, -1, sizeof h); 
	
	while (m --) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b), add_edge(b, a);
	}
	
	// 染色法
	bool ok = true; // 记录染色时是否发生矛盾 
	for (int i = 1; i <= n; i ++) {
		// 如果没染色过
		if (!color[i]) {
			// 染色，如果发生矛盾就结束
			if (!dfs(i, 1)) {
				ok = false;
				break;
			}
		} 
	} 
	
	// 查看有没有矛盾
	if (ok)
		puts("Yes");
	else
		puts("No");
	
	return 0;
}
