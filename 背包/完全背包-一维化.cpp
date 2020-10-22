#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/3/

const int N = 1010;

int v[N], w[N];
int f[N]; // 在公式优化的基础上直接去掉第一维就可以了 

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", v + i, w + i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = v[i]; j <= m; j ++) // 01背包这里是从大到小，完全背包是从小到大，别的没区别 
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	
	printf("%d\n", f[m]);
	
	return 0;
}
