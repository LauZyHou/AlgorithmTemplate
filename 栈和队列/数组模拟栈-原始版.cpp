#include <iostream>
using namespace std;

const int N = 1e5 + 10;

// ttָ��ջ��������ǰ��++ 
int stk[N], tt;

// ��ʼ��ջ�����ջ�� 
void init() {
	tt = 0;
}

// ��ջ������һ��Ԫ��
void push(int x) {
	stk[++tt] = x;
}

// �ж�ջ�Ƿ�Ϊ��
bool empty() {
	return tt == 0;
} 

// ��ջ������һ��Ԫ��
void pop() {
	if (!empty())
		tt--;
}

// ����ջ��Ԫ��
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


