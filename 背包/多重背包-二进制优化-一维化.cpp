#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/5/ 

// 打包后的物品数 = log(S) * 1000个物品 
const int N = 12010;
// 体积到2000 
const int M = 2010;

// 打包后物品的体积和价值权重 
int v[N], w[N];

// 一维化后的dp数组 
int f[M];


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	// n个物品打包 
	int cnt = 0; // 打包后物品数
	for (int i = 1; i <= n; i ++) {
		int a, b, s; // 第i个物品的体积、价值、数量 
		scanf("%d%d%d", &a, &b, &s);
		// 拆数量s，即做物品打包
		int k = 1; // 二进制倍增
		while (k <= s) {
			cnt ++;
			v[cnt] = a * k;
			w[cnt] = b * k;
			// 记录完这个打包物品然后就从s里去掉，然后倍增k 
			s -= k;
			k <<= 1;
		}
		// 如果最后s没拆完，剩下的这s个打包在一起
		if (s > 0) {
			cnt ++;
			v[cnt] = a * s;
			w[cnt] = b * s;
		} 
	}
	
	// 接下来就是对这cnt个物品做01背包
	n = cnt;
	for (int i = 1; i <= n; i ++)
		for (int j = m; j >= v[i]; j --)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
			
	printf("%d\n", f[m]);
	
	return 0;
}
