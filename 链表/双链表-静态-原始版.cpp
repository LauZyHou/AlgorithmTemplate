#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/829/
*/

const int N = 1e5 + 10;

// v[i]��¼���i��ֵ��l[i]��¼���i�������±꣬r[i]��¼���i���ҽ���±꣬idx��¼��������±� 
int v[N], l[N], r[N], idx;


// ��ʼ��˫����
void init() {
	// ������0��1��ʾ�����ڱ����
	r[0] = 1, l[1] = 0;
	idx = 2; // ��Ϊ0��1�Ѿ�ռ��������λ�ã����Դ�2��ʼ 
}

// ���±���j�Ľ���ұ߲���x
// ���Ҫ���±�k�Ľ����߲���x��ֻҪ����add(l[k])
void add(int j, int x) {
	v[idx] = x;
	l[idx] = j;
	r[idx] = r[j];
	l[r[j]] = idx;
	r[j] = idx;
	idx++;
}

// ɾ���±�Ϊj�Ľ��
void del(int j) {
	l[r[j]] = l[j];
	r[l[j]] = r[j];
} 


int main() {
	int m;
	cin >> m;
	
	init(); 
	
	while (m--) {
		int k, x;
		string s;
		cin >> s;
		
		if (s == "L") {
			cin >> x;
			add(0, x);
		}
		else if (s == "R") {
			cin >> x;
			add(l[1], x);
		}
		else if (s == "D") {
			cin >> k;
			del(k-1 + 2);
		}
		else if (s == "IL") {
			cin >> k >> x;
			add(l[k-1 + 2], x);
		}
		else {
			cin >> k >> x;
			add(k-1 + 2, x);
		}
	}
	
	for (int p = r[0]; p != 1; p = r[p])
		cout << v[p] << ' ';
	
	return 0;
}
