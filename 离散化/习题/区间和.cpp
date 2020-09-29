#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

/*
https://www.acwing.com/problem/content/804/
*/

typedef pair<int, int> PII;

// ��Ϊx/l/r��1e5������Ҫ���������������￪3e5��ģ������ 
const int N = 3e5 + 10;

int n, m;
int a[N], s[N]; // ��ɢ�������a������ǰ׺��֮����s

vector<int> alls; // x/l/r��ԭʼֵ��Ҫ�浽����
vector<PII> add, query; // �ֱ��<x,c>��<l,r>

// ���ּ�����ɢ��֮���ֵ 
int find(int x) {
	// ����alls�Ѿ�������+ȥ�ع����� 
	int l = 0, r = alls.size() - 1;
	while (l < r) {
		int mid = l+r >> 1;
		if (alls[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	}
	return r + 1; // ����+1����ɢ��֮����±��1��ʼ 
} 

int main() {
	cin >> n >> m;
	
	// ��ȡ<x,c> 
	for (int i = 0; i < n; i++) {
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	}
	
	// ��ȡ<l,r>
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r);
	}
	
	// ��alls����+ȥ��
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	// ������룬����add������<x, c>��x��ɢ���õ�yȻ��a[y]+=c
	for (auto &item : add) {
		int x = item.first;
		int c = item.second;
		int y = find(x);
		a[y] += c;
	}
	
	// ����ǰ׺�͵õ�s����
	for (int i = 1; i <= alls.size(); i++) {
		s[i] = s[i - 1] + a[i];
	}
	
	// �����ѯ������query������<l, r>��l��r��ɢ����Ȼ����ǰ׺�ͼ��������
	for (auto &item : query) {
		int l = item.first;
		int r = item.second;
		int _l = find(l);
		int _r = find(r);
		cout << s[_r] - s[_l - 1] << endl; 
	} 
	
	return 0; 
}
