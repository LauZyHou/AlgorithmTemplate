#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/837/

Trie树可以快速存取字符串集合，字符类型不会很多 
*/

// 输入的字符串的总长度上界（所有字符串加起来不超过这个值） 
const int N = 1e5 + 10;

// 字符串每个位置可以是26个小写字母，所以有26个子结点
// 这里son[i][j]存的是解空间的i结点的'a'~'z'子结点的下标
// 值0既表示是空结点，也表示Trie树的根节点 
int son[N][26];

// 用于指示son数组用到了哪里，分配要使用的结点时从这里加 
int idx; // 数组模拟指针 

// cnt[i]记录解空间的i结点结尾的字符串出现了多少次
int cnt[N]; 

// Trie树插入一个字符串
void insert(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i ++) {
		int u = str[i] - 'a';
		// 如果孩子结点不存在，就分配一个 
		if (!son[p][u])
			son[p][u] = ++ idx; // 这里先++，因为0表示空结点
		// 向下走 
		p = son[p][u]; 
	}
	// 走完要记录该处结尾的字符串数量+1
	cnt[p] ++; 
}

// 查询字符串在Trie树中出现多少次
int query(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i ++) {
		int u = str[i] - 'a';
		// 如果某个位置发现孩子结点不存在 
		if (!son[p][u])
			return 0; // 那没法往下走了，字符串肯定没出现过
		// 往下走
		p = son[p][u]; 
	}
	// 走完返回记录的出现次数
	return cnt[p]; 
}

char str[N];
char op[2];

int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		scanf("%s%s", op, str);
		if (op[0] == 'I')
			insert(str);
		else
			printf("%d\n", query(str));
	}
	
	return 0;
}
