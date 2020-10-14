#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// https://www.acwing.com/problem/content/description/841/
// 因为调整之后顺序就和输入的不一样了
// 所以要记录堆里的每个元素是第几个插入的，用数组hp
// 也要记录第几个插入的是堆里的哪个元素，用数组ph

const int N = 1e5 + 10;

int n;

int m; // 第几个插入的数 
int hp[N]; // 堆下标 -> 第几个插入的数
int ph[N]; // 第几个插入的数 -> 堆下标 

int h[N]; // 堆数组 
int sz = 0; // 堆数组用到了哪里 

// 交换h[a]和h[b]，同时维护hp和ph 
void heap_swap(int a, int b) {
	swap(h[a], h[b]); // 交换值 
	swap(ph[hp[a]], ph[hp[b]]); // 交换记录：第几个插入的数的堆下标 
	swap(hp[a], hp[b]); // 交换记录：这两个位置的数是第几个插入的数 
}

// 当前位置比较大时，向下调整成堆 
void down(int u) {
	int t = u;
	if (u * 2 <= sz && h[u * 2] < h[t])
		t = u * 2;
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])
		t = u * 2 + 1;
	if (t != u) {
		heap_swap(t, u);
		down(t);
	}
}

// 当前位置比较小时，向上调整成堆
void up(int u) {
	while (u / 2 && h[u / 2] > h[u]) {
		heap_swap(u / 2, u);
		u /= 2;
	}
} 

int main() {
	scanf("%d", &n);
	while (n --) {
		char op[3];
		scanf("%s", op);
		if (!strcmp(op, "I")) { // 插入 
			m ++;
			int x;
			scanf("%d", &x);
			h[++ sz] = x;
			hp[sz] = m;
			ph[m] = sz;
			up(sz);
		}
		else if (!strcmp(op, "PM")) { // 输出最小值 
			printf("%d\n", h[1]);
		}
		else if (!strcmp(op, "DM")) { // 删除最小值 
			heap_swap(sz, 1);
			sz --;
			down(1);
		}
		else if (!strcmp(op, "D")) { // 删除第k个插入的数 
			int k;
			scanf("%d", &k);
			int x = ph[k]; // 在堆中的位置
			heap_swap(sz, x);
			sz --;
			down(x), up(x); 
		}
		else if (!strcmp(op, "C")) { // 修改第k个插入的数 
			int k, v;
			scanf("%d%d", &k, &v);
			int _x = ph[k]; // 第k个插入的元素现在在堆中的位置
			h[_x] = v;
			down(_x), up(_x); 
		}
	}
	return 0;
}
