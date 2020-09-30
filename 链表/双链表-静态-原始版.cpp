#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/829/
*/

const int N = 1e5 + 10;

// v[i]记录结点i的值，l[i]记录结点i的左结点下标，r[i]记录结点i的右结点下标，idx记录待分配的下标 
int v[N], l[N], r[N], idx;


// 初始化双链表
void init() {
	// 这里用0和1表示左右哨兵结点
	r[0] = 1, l[1] = 0;
	idx = 2; // 因为0和1已经占用了两个位置，所以从2开始 
}

// 在下标是j的结点右边插入x
// 如果要在下标k的结点左边插入x，只要调用add(l[k])
void add(int j, int x) {
	v[idx] = x;
	l[idx] = j;
	r[idx] = r[j];
	l[r[j]] = idx;
	r[j] = idx;
	idx++;
}

// 删除下标为j的结点
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
