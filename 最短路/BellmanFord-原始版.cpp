#include <iostream>
#include <cstring>

using namespace std;

/*
https://www.acwing.com/problem/content/855/

BF算法适合有负权边的单源点最短路

算法过程：
for n 次 // 这里如果循环k次，则求得的是经过"不超过k条边"的最短路
	备份dist数组，保证每次只用上次更新的dist结果来计算 
	for 所有边 // 每条边(a,b,w) 表示 从a到b，边权是w
		dist[b] = min(dist[b], _dist[a] + w) // 松弛操作 
因为每次只要所有边都遍历到就行了
所以BF算法里不用邻接矩阵、不用邻接表也可以 
直接把所有边(a,b,w)存下来就行了
结构体数组，或者三个等长数组都可以的 

经过n次对所有边的松弛操作，一定满足如下的三角不等式：
对所有边(a,b,w)有dist[b] <= dist[a] + w 

注意如果有负权回路，那么最短路可能不存在
因为可以一直在负权回路里越转越小
BF算法可以求出来有没有负权回路 
因为循环k次，求得的是经过"不超过k条边"的最短路
如果第n次循环时候dist还有更新，说明这时候找到了长度为n的最短路
这条路径上有n+1个点，由抽屉原理知一定有重复点，所以一定是有负环

BF虽然可以求负环，但是时间复杂度比较高，所以不用它来求
BF比其它算法好用的就是【循环k次，求得的是经过"不超过k条边"的最短路】这个性质 
*/

const int N = 5e2 + 10;
const int M = 1e5 + 10;

int n, m, k;

struct Edge {
	int a, b, w;
}e[M];

int dist[N], backup[N]; // dist和它的备份数组 

int bellman_ford() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	// 因为最多长度是k，所以这里循环k次 
	for (int i = 0; i < k; i ++) {
		// 备份dist数组
		memcpy(backup, dist, sizeof dist);
		// 对每条边做松弛操作
		for (int j = 0; j < m; j ++) {
			int a = e[j].a, b = e[j].b, w = e[j].w;
			dist[b] = min(dist[b], backup[a] + w); // 注意这里用备份的backup[a]取到a的距离 
		} 
	}
	
	// 因为无穷也可能被无穷+负权边更新变小，所以这里用大于一个较大的数来判断
	if (dist[n] > 0x3f3f3f3f / 2) 
		return -1;
	return dist[n];
}


int main() {
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 0; i < m; i ++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[i] = {x, y, z};
	}
	
	int ans = bellman_ford();
	
	if (ans == -1)
		puts("impossible");
	else
		printf("%d\n", ans);
	
	return 0;
}
