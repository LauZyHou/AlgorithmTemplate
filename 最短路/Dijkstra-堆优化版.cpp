#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

/*
https://www.acwing.com/problem/content/852/

堆优化版Dijkstra求非负权单源点最短路
时间复杂度是O(mlogn)，适合稀疏图（边数m是不到n^2的级别） 
因为是稀疏图，所以用邻接表来存
注意最短路问题不区分有向图和无向图，如果是无向图就连双向边
所以写最短路算法只要考虑有向图就行了 

0. 集合S 
1. dist[1] = 0, dist[i] = +无穷
2. for i = 1..n
	找出不在S中的dist[t]最小的t
	把t放进S中，即确定到t的距离就是dist[i]
	看看先到t再到S中的点会不会更小，更新距离（这一步再邻接表中每次只要找从t出发的边） 

在(2.)循环里面的三步，整个循环走完它们的时间复杂度分别是
n-1次找最小：O(n^2)
n-1次确定距离：O(n)
n-1次更新距离：O(m)
把找最小改成用堆来实现
	每次只要O(1)，所以n-1次找最小：O(n^2)
在更新距离时，因为堆里也存了，所以要修改堆里任意元素
	每次要O(logn)，所以n-1次更新距离：O(mlogn)

STL的堆不支持修改任意元素，如果用STL的堆可以用冗余的方式
即每次向堆中插入新的元素，就当是修改元素了，这样堆里可能有m个元素
这样m次的更新距离，时间复杂度变成了O(mlogm)
不过因为m<n^2，所以mlogm<mlog(n^2)=2mlogn，所以O(mlogm)和O(mlogn)是一个级别的 
*/

const int N = 2e5;

int n, m;

int h[N], e[N], ne[N], idx; // 邻接表
int w[N]; // 邻接表带边权

// 邻接表加边a->b，边权为c
void add_edge(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c; // 注意设置边权 
	ne[idx] = h[a];
	h[a] = idx ++;
}

typedef pair<int, int> PII;

int dist[N]; // 存到每个点的距离 
bool st[N]; // 存这个点有没有用于更新其它点 

// 带堆优化的Dijkstra算法求点1到点n的最短路
int dijkstra() {
	// 初始化距离
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; // 源点
	
	// 用堆来求每次dist的最小
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1}); // <距离,结点号>
	
	while (heap.size()) {
		// 每次取堆顶元素 
		auto t = heap.top();
		heap.pop();
		
		// 取出距离和这个结点
		int distance = t.first;
		int vertex = t.second;
		
		// 如果这个结点更新过其它点了，就下一轮重新取
		if (st[vertex])
			continue;
		
		// 至此，要用vertex来更新其它点，到vertex的距离就是distance确定了
		st[vertex] = true; // 记录他更新了其它点
		// 遍历从vertex出发的所有边，做更新
		for (int i = h[vertex]; i != -1; i = ne[i]) {
			// dest点是j 
			int j = e[i];
			// 如果先到vertex再从vertex到j（这个权重就是w[i]）更小
			if (distance + w[i] < dist[j]) {
				dist[j] = distance + w[i]; // 就更新距离
				heap.push({dist[j], j}); // 因为更新了距离，这里直接插一个新的入堆 
			} 
		} 
	}
	
	// 如果点1和点n连通，则dist[n]被更新过，返回之
	if (dist[n] == 0x3f3f3f3f)
		return -1;
	return dist[n]; 
} 


int main() {
	scanf("%d%d", &n, &m);
	
	// 初始化邻接表
	memset(h, -1, sizeof h); 
	
	while (m --) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add_edge(x, y, z);
	}
	
	printf("%d", dijkstra());
	
	return 0;
}
