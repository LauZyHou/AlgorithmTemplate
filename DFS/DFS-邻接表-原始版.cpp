#include <iostream>

using namespace std;

/*
		数据结构	使用空间 	性质 
DFS 	stack		O(h)		不具最近性质  
*/

// 结点数量最大值 
const int N = 1e5 + 10;

// 邻接表N个结点每个最多拉出N-1长度的链，所以静态链表最大要开N*N规模的
// 但是这里可以根据题目数据来看，最多有多少边其实就开多少就行了 
const int M = N * 2;

// 邻接表
int h[N];

// 链表结点数组，链表next指针数组，链表分配位置 
int e[M], ne[M], idx;

// 向邻接表中添加a->b的边
void add_edge(int a, int b) {
	// 创建链表结点b
	e[idx] = b;
	// 将其头插到h[a]位置上 
	ne[idx] = h[a];
	h[a] = idx ++;
}

// 在邻接表上DFS时，要记录哪些结点访问过了 
bool st[N];

// 邻接表上DFS，从点u位置 
void dfs(int u) {
	// 标记被搜过了 
	st[u] = true;
	
	// 遍历从u出发的所有边，另一侧的结点
	for (int i = h[u]; i != -1; i = ne[i]) {
		// i是在链表数组中的下标，这里要变成图中的结点号
		int j = e[i];
		// 如果这个结点没被访问过，就往下DFS
		if (!st[j])
			dfs(j); 
	}
	
	// 这里不需要像解空间上的DFS（实际是回溯）一样取消标记
	// 图上的遍历用的搜索就是搜到一次就不会再来搜这个点了 
} 

int main() {
	// 邻接表初始每个位置链表都是空的，所以全部设为-1 
	memset(h, -1, sizeof h);
	
	// 创建邻接表表示的有向图...（无向图就存两个方向）
	
	// 从点1开始dfs 
	dfs(1);
	
	return 0;
}

 
