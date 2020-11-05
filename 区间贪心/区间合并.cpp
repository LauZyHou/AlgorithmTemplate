#include <bits/stdc++.h>
using namespace std;

/*
https://www.acwing.com/problem/content/805/
(1)把所有区间按左端点从大到小排序
(2)每次维护一个当前区间[a1, b1]
   查看下一区间[a2, b2]，其中一定有a2>=a1
   如果a2<=b1 && b2<=b1，则合到当前区间里
   如果a2<=b1 && b2>b1，则合并为[a1, b2]
   如果a2>b1，则无法合并，记录区间数，当前区间变为[a2. b2] 
*/

typedef pair<int, int> PII; 

int n;
vector<PII> segs;

void merge(vector<PII> &segs) {
	vector<PII> res;
	
	// 这里默认是按第一项从小到大再按第二项从小到大 
	sort(segs.begin(), segs.end());
	
	// 这里直接取负无穷到负无穷，一定不会和其它的区间有交集 
	int a1 = INT_MIN, b1 = INT_MIN;
	for (auto &seg : segs) {
		int a2 = seg.first;
		int b2 = seg.second;
		if (a2 > b1) {
			if (a1 != INT_MIN) // 判断一下 
				res.push_back({a1, b1});
			a1 = a2;
			b1 = b2;
		}
		else
			b1 = max(b1, b2);
	}
	
	// 当前区间（如果有的话）一定还要合进来
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
