#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/844/
// 用DFS做，要考虑好用什么样的顺序遍历所有的方案 

const int N = 10;

int path[N]; // DFS时路径上的解
bool st[N]; // 记录每个数字是否被用过

int n;

// 搜索下标为u的path[u]可以的值 
void dfs(int u) {
	// 找到了解 
	if (u == n) {
		for (int i = 0; i < n ; i ++)
			printf("%d ", path[i]);
		puts("");
		return ;
	}
	// 这个位置填充每个可能的取值
	for (int i = 1; i <= n; i ++)
		if (!st[i]) { // 没用过 
			path[u] = i; // 填充到这个位置
			st[i] = true; // 设置被使用过
			dfs(u + 1); // 向下一层搜索
			st[i] = false; // 恢复现场：这个数字不再被使用 
		}
}

int main() {
	scanf("%d", &n);
	
	dfs(0);
	
	return 0;
} 

