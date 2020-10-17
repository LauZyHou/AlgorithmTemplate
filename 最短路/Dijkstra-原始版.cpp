#include <iostream>
#include <cstring>
using namespace std;

/*
https://www.acwing.com/problem/content/description/851/

朴素版Dijkstra求非负权单源点最短路
时间复杂度是O(n^2)，适合稠密图（边数m是n^2级别） 
因为是稠密图，所以用邻接矩阵来存 
注意最短路问题不区分有向图和无向图，如果是无向图就连双向边
所以写最短路算法只要考虑有向图就行了 

0. 集合S 
1. dist[1] = 0, dist[i] = +无穷
2. for i = 1..n
	找出不在S中的dist[t]最小的t
	把t放进S中，即确定到t的距离就是dist[i]
	看看先到t再到S中的点会不会更小，更新距离 
*/

const int N = 510;

int g[N][N]; // 邻接矩阵
int dist[N]; // 存从源点到这个点的距离
bool st[N]; // 某个点有没有更新过其它点（而不是某个点距离有没有被确定） 

int n, m;


// 朴素Dijkstra计算最短路 
int dijkstra() {
	// 初始化dist数组
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; // 源点到源点距离
	// 注意，这里不能写st[1]=true，因为1还没有用来更新过其它点 
	
	// 再循环n-1次，每次都能确定到一个点的距离，最后一个点一定已经确定了 
	for (int i = 0; i < n - 1; i ++) {
		// 找使得dist[t]最小未确定距离的t点
		int t = -1; // -1表示t还没被赋值过 
		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		// 尝试用源点先到t再从t到汇点来更新所有点距离
		// 实际上只更新未确定的那些点，不过这里不判断未确定也行
		// 因为已经确定的自己没法再变小了
		for (int j = 1; j <= n; j ++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		// 标记这个点的距离被确定了
		st[t] = true; 
	} 
	
	// 这里要求的是到n号点的，如果到n号点的距离没更新过，说明n号点和1号点是不连通的	
	// memset会把每个字节都写成0x3f，dist[n]是int型变量，包含4个字节，所以一定要写成0x3f3f3f3f
	if (dist[n] == 0x3f3f3f3f)
		return -1;
	return dist[n];
}



int main() {
	scanf("%d%d", &n, &m);
	
	// 邻接矩阵建立 
	memset(g, 0x3f, sizeof g);
	while (m --) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c); // a->b直接距离是c
		g[a][b] = min(g[a][b], c); // 因为有重边，所以要取重边里最小的 
	}
	// 每个点到自己的距离是0
	for (int i = 1; i <= n; i ++) 
		g[i][i] = 0;

	printf("%d", dijkstra()); 
	
	return 0;
} 
