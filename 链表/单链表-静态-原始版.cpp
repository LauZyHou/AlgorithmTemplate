#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/828/
*/

const int N = 1e5 + 10;

// head��¼��һ���ڵ��±꣬v[i]��¼���i��ֵ��ne[i]��¼���i��next����±꣬idx��¼��������±� 
int head, v[N], ne[N], idx;

// �����ʼ��
void init() {
	head = -1;
	idx = 0;
}

// ��ֵΪx�Ľ��ͷ�嵽��һ�����
void add_head(int x) {
	v[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++;
}

// ��ֵΪx�Ľ����뵽�±�Ϊj�Ľ�����
void add(int j, int x) {
	v[idx] = x;
	ne[idx] = ne[j];
	ne[j] = idx;
	idx++;
}

// ����һ�����ɾ����
void del_head() {
	if (head == -1)
		return ;
	head = ne[head];
} 

// ���±���j�Ľ�����Ľ��ɾ����
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
