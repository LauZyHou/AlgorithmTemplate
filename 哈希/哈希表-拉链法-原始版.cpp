#include <iostream>
#include <cstring>

using namespace std;

/*
https://www.acwing.com/problem/content/842/

哈希表将较大的空间的数据映射到一个小范围里
拉链法是在发生冲突时直接加到这个位置拉出来的链表里 
*/

// 哈希表长度，选用质数，并尽可能离2的幂远，能减少冲突 
const int N = 100003;

// 哈希表 
int h[N];

// 链表的结点分配数组 
int e[N];

// 链表的next结点指向
int ne[N];

// 链表的结点分配下标
int idx; 

// 哈希表插入操作
void insert(int x) { 
	// 哈希操作后的值 
	int k = (x % N + N) % N;
	// 创建链表结点
	e[idx] = x;
	// 头插到哈希表的k位置链表上 
	ne[idx] = h[k]; 
	h[k] = idx;
	// 分配下标向后走
	idx ++; 
}

// 哈希表的查找操作
bool find(int x) {
	// 在拉链法里就是直接去对应的链表里找
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == x)
			return true;
	return false; 
} 

int n;

int main() {
	scanf("%d", &n);
	
	// 初始化整个哈希表中是-1，即各个链表都是空的
	memset(h, -1, sizeof h); 
	
	while (n --) {
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		
		if (op[0] == 'I') // 插入
			insert(x);
		else { // 查找 
			if (find(x))
				puts("Yes");
			else
				puts("No");
		} 
	}
	
	return 0;
}
