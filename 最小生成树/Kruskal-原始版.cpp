#include <iostream>
#include <algorithm>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/925/1/

步骤： 
1. 将所有边按照权重从小到大排序，O(mlogm)
   // 这一步是Kruskal算法的瓶颈，不过排序算法的常数很小，所以Kruskal很快
2. 枚举每条边，a-b，权重是c，O(m) 
   if 当前a和b不连通 then 将这条边加入到集合中来，a和b也联通了 
   // 这一步可以用最普通的并查集来做，也不用维护额外信息 

只要把每条边直接存下来就行了，不用邻接表和邻接矩阵 
一般在稀疏图里就用Kruskal算法 
*/

const int M = 2e5 + 10;

int p[M]; // 并查集

// 边 
struct Edge {
	int a, b, w;
	bool operator< (const Edge &e)const {
		return w < e.w;
	}
}edges[M];

// 并查集查找 + 路径压缩
int find(int x) {
	if (p[x] != x) { // 自己还有更上面的祖先 
		p[x] = find(p[x]); // 路径压缩 
	}
	return p[x];
} 

int n, m; 

int main() {
	scanf("%d%d", &n, &m);
	
	// 读入所有边 
	for (int i = 0; i < m; i ++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = {a, b, w};
	}
	
	// 按权重从小到大排序 
	sort(edges, edges + m);
	
	// 初始化并查集
	for (int i = 1; i <= n; i ++)
		p[i] = i; 
	
	int ans = 0, cnt = 0;
	
	// 遍历所有的边 
	for (int i = 0; i < m; i ++) {
		// 两顶点
		int a = edges[i].a;
		int b = edges[i].b;
		int w = edges[i].w;
		// 并查集查找祖先
		a = find(a);
		b = find(b);
		// 不在同一个连通块集合里
		if (a != b) {
			p[a] = b; // 放一起
			ans += w; // 记录答案：边长和
			cnt ++; // 已经加入了多少边 
		} 
	} 
	
	// 如果最后得到的不足n-1条边，说明不联通
	if (cnt < n - 1)
		puts("impossible");
	else
		printf("%d\n", ans); 
	
	return 0;
} 
