#include <bits/stdc++.h>
using namespace std;

/*
https://www.acwing.com/problem/content/805/
(1)���������䰴��˵�Ӵ�С����
(2)ÿ��ά��һ����ǰ����[a1, b1]
   �鿴��һ����[a2, b2]������һ����a2>=a1
   ���a2<=b1 && b2<=b1����ϵ���ǰ������
   ���a2<=b1 && b2>b1����ϲ�Ϊ[a1, b2]
   ���a2>b1�����޷��ϲ�����¼����������ǰ�����Ϊ[a2. b2] 
*/

typedef pair<int, int> PII; 

int n;
vector<PII> segs;

void merge(vector<PII> &segs) {
	vector<PII> res;
	
	// ����Ĭ���ǰ���һ���С�����ٰ��ڶ����С���� 
	sort(segs.begin(), segs.end());
	
	// ����ֱ��ȡ����������һ������������������н��� 
	int a1 = INT_MIN, b1 = INT_MIN;
	for (auto &seg : segs) {
		int a2 = seg.first;
		int b2 = seg.second;
		if (a2 > b1) {
			if (a1 != INT_MIN) // �ж�һ�� 
				res.push_back({a1, b1});
			a1 = a2;
			b1 = b2;
		}
		else
			b1 = max(b1, b2);
	}
	
	// ��ǰ���䣨����еĻ���һ����Ҫ�Ͻ���
	if (a1 != INT_MIN) 
		res.push_back({a1, b1});
	
	segs = res;
}
 

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		segs.push_back({l, r});
	}
	
	merge(segs);
	
	cout << segs.size() << endl;
	
	return 0;
}
