#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/831/
*/

const int N = 1e5 + 10;

// tt指向队尾，插入前先++，hh指向队头 
int q[N], hh, tt = -1;

// 初始化队列（清空队列）
void init() {
	hh = 0;
	tt = -1;
}

// 从队尾插入元素
void push(int x) {
	q[++tt] = x;
}

// 判断队列是否为空
bool empty() {
	return hh > tt; // 为空时hh==tt+1 
}


// 从队头删除一个元素
void pop() {
	if (!empty())
		hh++;
}

// 从队尾删除一个元素
void pop_back() {
	if (!empty)
		tt--;
} 

// 返回队头元素 
int front() {
	if (!empty())
		return q[hh];
	return -1;
}

// 返回队尾元素
int back() {
	if (!empty())
		return q[tt];
	return -1;
} 

int main() {
	int m;
	cin >> m;
	
	init();
	
	while (m--) {
		int x;
		string op;
		cin >> op;
		
		if (op == "push") {
			cin >> x;
			push(x);
		}
		else if (op == "pop") {
			pop();
		}
		else if (op == "empty") {
			cout << (empty() ? "YES" : "NO") << endl;
		}
		else if (op == "query") {
			cout << front() << endl;
		}
	}
	
	return 0;
}
