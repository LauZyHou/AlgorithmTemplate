#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

// https://www.acwing.com/problem/content/895/
// 每堆石子能被取的情况构成了一个单独的局面图
// 如果把局面图构造出来，终止状态的SG值是0，就能把每个图根节点的SG值求出来
// 然后就用README里多个局面图的情况，把所有图的初始状态的SG值异或就能判断了 

const int N = 110; // 石子最大100堆
const int M = 1e4 + 10; // 取石子或者每堆石子的个数最大是10000 

int s[N]; // 集合中每个允许操作的数，所以和k是一个规模 
int f[M]; // f[x]是x个石子出发的结点SG函数的值，所以和石子规模有关 


// 集合中k个数，石子有n堆 
int k, n;

// 记忆化搜索求SG函数的值 
int sg(int x) {
	// 如果算过了就返回，保证每个状态SG函数只会被算一次 
	if (f[x] != -1)
		return f[x];
	// 哈希表集合存当前从这个局面可以到达的局面的SG函数值 
	unordered_set<int> dest_sgs;
	// 对于集合s里的每个数
	for (int i = 0; i < k; i ++) {
		int num = s[i]; // 集合里这个数（即可以取掉多少）
		// 如果当前局面x还可以取掉这么多数
		if (x >= num) {
			// 把新的状态的SG值加进来
			dest_sgs.insert(sg(x - num));
		}
	}
	// 对所有后继状态求好了SG函数值，接下来做一下Mex运算
	// 即算一下这里不存在的最小的自然数是多少，就是当前的SG值
	for (int v = 0; ; v ++)
		if (!dest_sgs.count(v))
			return f[x] = v;
}


int main() {
	// 读入集合s中k个数 
	scanf("%d", &k);
	for (int i = 0; i < k; i ++)
		scanf("%d", s + i);

	// 记忆化搜索，先清空SG函数的值的数组，没计算过就是-1
	memset(f, -1, sizeof f);
	
	// 读入n堆石子的数量
	scanf("%d", &n);
	int res = 0; // 答案：每一堆石子形成的局面图的SG函数值的异或 
	// 对于每一堆石子 
	for (int i = 0; i < n; i ++) {
		// 读入每一堆石子的个数 
		int x;
		scanf("%d", &x);
		res ^= sg(x);
	}
	
	// 根据局面图起点SG函数的异或值是不是0知道先手必胜/必败 
	if (res)
		puts("Yes");
	else
		puts("No");
	
	return 0;
}
