#include <iostream>
#include <cstring>

using namespace std;

// https://www.acwing.com/problem/content/848/
// 树的重心 

const int N = 1e5 + 10; // 点数最大值

const int M = 2 * N; // 边树最大值，由于在树上，所以和N是一个规模，不过要存两个方向 


int h[N]; // 邻接表

int e[M]; // 链表数组
int ne[M]; // 链表next
int idx; // 链表分配用  
 

// 在邻接表中添加边a->b 
void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++; 
}

// 记录树结点访问情况
bool st[N]; 

int n; // 树结点数 

int ans = N; // 所求的最小最大值 


// 从结点u深搜：去掉这个结点后，各个连通图中结点数最大值
// 返回值是以u开始的子树中有多少结点，以用于上层的调用方算自己的 
int dfs(int u) {
	st[u] = true; // 访问过了 
	
	int sum = 1; // u自己至少一个
	int nowans = 0; // 记录各个连通图中结点数最大值 
	
	// 遍历所有的边，i是链表索引 
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i]; // 取出存的树结点索引
		if (!st[j]) {
			int s = dfs(j);
			sum += s;
			nowans = max(nowans, s);
		}
	}
	
	// 还要和去掉自己后上面的连通图比大小
	nowans = max(nowans, n - sum);
	
	// 更新全局的这个最小最大值 
	ans = min(ans, nowans);
	
	return sum; 
} 



int main() {
	memset(h, -1, sizeof h);
	
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i ++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b);
		add_edge(b, a);
	}
	
	dfs(1);
	
	printf("%d", ans);
	
	return 0;
}
