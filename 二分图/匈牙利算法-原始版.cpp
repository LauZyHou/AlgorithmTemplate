#include <cstring>
#include <iostream>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/927/1/

虽然是无向图，但是匈牙利算法过程中只会找左边每个点到右边的所有边
不会去找右边的点到左边的边，所以只要存从左到右的边就可以了	
要用一个数组记录一下右边的点和左边的哪个点匹配在一起 
*/

const int N = 510; // 用于邻接表h下标时表示男生id，用于match数组下标时表示女生id 
const int M = 1e5 + 10;

// 邻接表
int h[N], e[M], ne[M], idx;

// 邻接表加边 
void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
} 

// 存右边的女生和左边哪个男生在一起
int match[N];
// 存递归判断时哪些女生已经考虑过了（防止在不同的层递归同一个女生）
bool st[N];

// 匈牙利算法递归查找和给定的男生匹配的女生，找到时记录并返回true 
bool find(int x) {
	// 对于所有出边，也就是可以匹配的女生
	for (int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		// 如果考虑过了就跳过
		if (st[j])
			continue;
		// 没考虑过，现在考虑能不能和这个女生j匹配 
		st[j] = true;
		// 如果这个女生没匹配，或者和她匹配的男生可以找到下家 
		if (!match[j] || find(match[j])) {
			// 那么就把这个女生j匹配给男生x
			match[j] = x;
			// 找到了
			return true; 
		}
	} 
	// 找不到匹配
	return false; 
}

// 男生数、女生数、边数 
int n1, n2, m;

int main() {
	scanf("%d%d%d", &n1, &n2, &m);
	
	memset(h, -1, sizeof h);
	
	while (m --) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b); // 只存从男生到女生的就可以 
	}
	
	int ans = 0; // 最大匹配数
	// 遍历所有男生编号1~n1，看看能不能匹配
	for (int i = 1; i <= n1; i ++) {
		// 调递归的find查找前要把记录所有女生没考虑过的数组st置为false
		memset(st, false, sizeof st); 
		if (find(i))
			ans ++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
