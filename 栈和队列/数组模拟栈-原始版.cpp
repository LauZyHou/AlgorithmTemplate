#include <iostream>
using namespace std;

const int N = 1e5 + 10;

// tt指向栈顶，插入前先++ 
int stk[N], tt;

// 初始化栈（清空栈） 
void init() {
	tt = 0;
}

// 向栈顶插入一个元素
void push(int x) {
	stk[++tt] = x;
}

// 判断栈是否为空
bool empty() {
	return tt == 0;
} 

// 从栈顶弹出一个元素
void pop() {
	if (!empty())
		tt--;
}

// 返回栈顶元素
int top() {
	return stk[tt];
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
			cout << top() << endl;
		}
	}
	
	return 0;
}


