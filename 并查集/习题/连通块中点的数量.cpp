#include <iostream>
using namespace std;

// https://www.acwing.com/activity/content/problem/content/886/1/
// 要有辅助数据来维护并查集中每个集合的元素数量 

const int N = 1e5 + 10;

int p[N]; // 每个结点的代表结点的index

int sz[N]; // 每个集合的大小，只对代表结点有意义 

// 查询所在集合 + 路径压缩
int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
} 

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	// 初始化，每个结点在自己在一个集合里
	for (int i = 1; i <= n; i ++)
		p[i] = i, sz[i] = 1;
	
	// m次查询
	while (m --) {
		char op[3]; // 操作
		int a, b; // 要操作的两个结点
		scanf("%s", op);
		
		if (op[0] == 'C') { // 并 
			scanf("%d%d", &a, &b);
			int fa = find(a);
			int fb = find(b);
			if (fa == fb)
				continue;
			sz[fa] += sz[fb];
			p[fb] = fa;
		}
		else if (op[1] == '1') { // 查 是否在同一个集合里 
			scanf("%d%d", &a, &b);
			if (find(a) == find(b))
				puts("Yes");
			else
				puts("No");
		}
		else { // 查 某个结点所在的子图的元素个数
			scanf("%d", &a); 
			printf("%d\n", sz[find(a)]);
		}
	}
	
	return 0;
}
