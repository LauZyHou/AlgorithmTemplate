#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/828/
*/

const int N = 1e5 + 10;

// head记录第一个节点下标，v[i]记录结点i的值，ne[i]记录结点i的next结点下标，idx记录待分配的下标 
int head, v[N], ne[N], idx;

// 链表初始化
void init() {
	head = -1;
	idx = 0;
}

// 将值为x的结点头插到第一个结点
void add_head(int x) {
	v[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++;
}

// 将值为x的结点插入到下标为j的结点后面
void add(int j, int x) {
	v[idx] = x;
	ne[idx] = ne[j];
	ne[j] = idx;
	idx++;
}

// 将第一个结点删除掉
void del_head() {
	if (head == -1)
		return ;
	head = ne[head];
} 

// 将下表是j的结点后面的结点删除掉
void del(int j) {
	if (ne[j] == -1)
		return ;
	ne[j] = ne[ne[j]];
} 


int main() {
	int m;
	cin >> m;
	
	init();
	
	while (m--) {
		char c;
		int k, x;
		
		cin >> c;
		if (c == 'H') {
			cin >> x;
			add_head(x);
		}
		else if (c == 'D') {
			cin >> k;
			if (k == 0)
				del_head();
			else
				del(k - 1);
		}
		else {
			cin >> k >> x;
			add(k - 1, x);
		}
	}
	
	for (int p = head; p != -1; p = ne[p])
		cout << v[p] << ' ';
	
	return 0;
}
