#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/description/838/

并查集
1. 将两个集合合并
2. 询问两个元素是否在一个集合当中

基本原理：每个集合用一棵树来表示
树根的编号就是整合集合的编号
每个结点存储它的父节点
p[x]表示x的父节点

Q1: 如何判断树根
	if (p[x] == x) 那么是树根
Q2: 如何求x的结点编号
	while (p[x] != x) x = p[x];
Q3: 如何合并两个集合
	x和y分别是两集合的根，p[x]=y或者p[y]=x就行了 
*/

const int N = 1e5 + 10;

// 存每个元素的父节点的下标 
int p[N];

// 查询x的祖宗结点，这里用递归好写路径压缩 
int find(int x) {
	// 路径上每个x的父亲都指向祖先 
	// 并且这里find(p[x])不能写成find(x)，否则一直还是在这个x结点层面 
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x]; // 压缩完x的父亲就是祖先了 
} 

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	// 初始化，每个结点自己一个集合
	for (int i = 1; i <= n; i ++)
		p[i] = i;
	
	while (m --) {
		char op[2]; // 操作 
		int a, b; // 两个元素 
		scanf("%s%d%d", op, &a, &b);
		
		if (op[0] == 'M') // 合并
			p[find(a)] = find(b); // a所在的树挂到b上
		else // 查询
			if (find(a) == find(b))
				puts("Yes");
			else
				puts("No"); 
	}
	
	return 0;
}
