#include <iostream>

using namespace std;

/*
		数据结构	使用空间 	性质 
BFS		queue		O(2^h)		边权都是1时，第一次搜到的解是最近的 
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

// 在邻接表上BFS时，要记录哪些结点访问过了 
bool st[N];

void bfs(int u) {
	// 加入队列中 
	queue<int> q;
	q.push(u);
	
	while (q.size()) {
		int v = q.front();
		q.pop();
		// 记录被访问了
		st[v] = true;
		// 遍历从v出发的所有边，另一侧的结点
		for (int i = h[v]; i != -1; i = ne[i]) {
			// i是在链表数组中的下标，这里要变成图中的结点号
			int j = e[i];
			// 如果这个结点没被访问过，就加入队列中 
			if (!st[j])
				q.push(j);
		}
	}
}

int main() {
	// 邻接表初始每个位置链表都是空的，所以全部设为-1 
	memset(h, -1, sizeof h);
	
	// 创建邻接表表示的有向图...（无向图就存两个方向）
	
	// 从点1开始bfs 
	bfs(1);
	
	return 0;
}

