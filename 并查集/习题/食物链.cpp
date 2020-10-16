#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/description/242/
// 使用需要使用维护额外信息的并查集 
// 维护并查集树上每个结点到父节点的距离
// 这样在路径压缩时候就知道每个结点到根节点的距离
// 根据这个距离%3的值来判断属于哪一类 

const int N = 5e4 + 10;

// 每个元素父结点下标 
int p[N];

// 每个元素到并查集的集合树上父节点的距离
// 自己到自己的距离就是0 
int d[N];

// 查找x的父节点 + 路径压缩 + 维护到父节点的距离 
int find(int x) {
	// 不是这棵树的根 
	if (p[x] != x) {
		// 维护d[x] = 旧d[x] + d[旧p[x]]
		// 对p[x]的find过程既不改变d[x]也不改变p[x]的值
		// 但是赋值就会改变p[x]的值了，所以先记录一下
		int px = p[x]; 
		p[x] = find(px);
		d[x] += d[px];
	}
	return p[x];
} 


int n, k;
int ans = 0; // 假话数量

int main() {
	scanf("%d%d", &n, &k);
	
	// 初始化，每个节点在一个集合上
	for (int i = 1; i <= n; i ++)
		p[i] = i; 
	
	while (k --) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (x > n || y > n) { // 超过范围 
			ans ++;
			continue;
		}
		int fx = find(x);
		int fy = find(y);
		if (op == 1) { // x和y是同一类 
			// 如果两个在同一个集合（同一棵树）上，就可以根据距离判断是不是同一类
			// 前面调用完find之后它们就都挂在根节点上了
			// 所以这里d[x]和d[y]就是到根节点的距离
			// 如果模3不一样就不是同一类，是假话 
			if (fx == fy && (d[x] - d[y]) % 3)
				ans ++;
			// 如果不在同一个集合上，要合并到一起 
			// 把fx挂到fy上，保证(d[fx]+d[x])%3 = d[y]%3
			else if (fx != fy) {
				p[fx] = fy;
				d[fx] = d[y] - d[x];
			}
		}
		else { // x吃y 
			// 如果在同一个集合（同一棵树）上，则根据距离判断
			// 如果x吃y则应该有x到根节点距离%3比y到根节点距离%3多1 
			if (fx == fy && (d[x] - d[y] - 1) % 3)
				ans ++;
			// 如果不在同一个集合上，要合并到一起
			// 把fx挂到fy上，保证(d[x]+d[fx])%3 = d[y]%3 + 1
			else if (fx != fy) {
				p[fx] = fy;
				d[fx] = d[y] + 1 - d[x];
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
} 
