#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/831/
*/

const int N = 1e5 + 10;

// ttָ���β������ǰ��++��hhָ���ͷ 
int q[N], hh, tt = -1;

// ��ʼ�����У���ն��У�
void init() {
	hh = 0;
	tt = -1;
}

// �Ӷ�β����Ԫ��
void push(int x) {
	q[++tt] = x;
}

// �ж϶����Ƿ�Ϊ��
bool empty() {
	return hh > tt; // Ϊ��ʱhh==tt+1 
}


// �Ӷ�ͷɾ��һ��Ԫ��
void pop() {
	if (!empty())
		hh++;
}

// �Ӷ�βɾ��һ��Ԫ��
void pop_back() {
	if (!empty)
		tt--;
} 

// ���ض�ͷԪ�� 
int front() {
	if (!empty())
		return q[hh];
	return -1;
}

// ���ض�βԪ��
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
