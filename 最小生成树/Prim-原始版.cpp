#include <iostream>
#include <cstring>

using namespace std;

/*

Prim算法和Dijkstra算法过程很相似
首先将dist数组（表示点到集合的距离）初始化为正无穷
dist[1] = 0 // 表示将点1加到集合（表示当前已经在联通块中的所有点）中去 
for i从1到n // 因为要加入n个点，所以这里是迭代n次 
	找到集合外距离集合最近的点t
	用t更新其它点到集合的距离
	把t加到集合中去，st[t] = true

某个点到集合的距离定义为这个点到集合中的所有点的距离的最小值
也就是到集合里的最近的点的距离
最终得到的生成树就是每次选的"距离最近"对应的边组成的树 
*/

const int N = 510;
const int INF = 0x3f3f3f3f;

int g[N][N]; // 邻接矩阵 
int dist[N]; // 点到集合的距离 
bool st[N]; // 记录点是否加到了集合（连通块）里 

int n, m;

int prim() {
	memset(dist, 0x3f, sizeof dist);
	
	int res = 0; // 存答案：最小生成树里所有边的家和 
	dist[1] = 0; // 让它是到集合距离最近的点，距离就是0，这样一开始就能加入进来 
	// 循环n次，每次找一个点加入集合 
	for (int i = 0; i < n; i ++) {
		// 找集合外的一个到集合距离最近的点
		int t = -1;
		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		// 至此，t是集合外的到集合距离最近的点
		
		// 如果距离最近的点到集合的距离都是无穷
		// 那么说明集合外的点到集合都是不连通的了
		if (dist[t] == INF)
			return INF; // 表示不存在最小生成树
		// 否则，要更新答案（最小生成树边加和）
		res += dist[t];
		
		// 把这个点加到集合里
		st[t] = true;
		
		// 用这个点更新到其它点的距离
		// 这一步要在更新答案之后做，因为可能会有负自环导致更新自己的dist[t]
		for (int j = 1; j <= n; j ++)
			// 注意这里不是dist[t] + g[t][j]
			// 在prim算法里dist[t]表示t到集合的距离
			// 因为t加入集合里，所以要用dist[t][j]来更新j到集合的距离 
			dist[j] = min(dist[j], g[t][j]);
	}
	return res;
}


int main() {
	scanf("%d%d", &n, &m);
	
	memset(g, 0x3f, sizeof g);
	
	while (m --) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		// 无向图存两个方向的有向图
		// 有重边时候取较小的 
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	
	int t = prim();
	
	if (t == INF) // 所有点不连通，不存在最小生成树 
		puts("impossible");
	else
		printf("%d", t);

	return 0;
}
