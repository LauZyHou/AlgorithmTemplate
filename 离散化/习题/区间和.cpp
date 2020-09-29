#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

/*
https://www.acwing.com/problem/content/804/
*/

typedef pair<int, int> PII;

// 因为x/l/r各1e5个，都要存下来，所以这里开3e5规模的数组 
const int N = 3e5 + 10;

int n, m;
int a[N], s[N]; // 离散化后的是a，计算前缀和之后是s

vector<int> alls; // x/l/r的原始值都要存到这里
vector<PII> add, query; // 分别存<x,c>和<l,r>

// 二分计算离散化之后的值 
int find(int x) {
	// 这里alls已经是排序+去重过的了 
	int l = 0, r = alls.size() - 1;
	while (l < r) {
		int mid = l+r >> 1;
		if (alls[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	}
	return r + 1; // 这里+1让离散化之后的下标从1开始 
} 

int main() {
	cin >> n >> m;
	
	// 读取<x,c> 
	for (int i = 0; i < n; i++) {
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	}
	
	// 读取<l,r>
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r);
	}
	
	// 对alls排序+去重
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	// 处理插入，即对add数组中<x, c>的x离散化得到y然后a[y]+=c
	for (auto &item : add) {
		int x = item.first;
		int c = item.second;
		int y = find(x);
		a[y] += c;
	}
	
	// 计算前缀和得到s数组
	for (int i = 1; i <= alls.size(); i++) {
		s[i] = s[i - 1] + a[i];
	}
	
	// 处理查询，即对query数组中<l, r>的l和r离散化，然后用前缀和计算区间和
	for (auto &item : query) {
		int l = item.first;
		int r = item.second;
		int _l = find(l);
		int _r = find(r);
		cout << s[_r] - s[_l - 1] << endl; 
	} 
	
	return 0; 
}
