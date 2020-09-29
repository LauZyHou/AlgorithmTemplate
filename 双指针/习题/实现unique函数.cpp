#include <iostream>
#include <vector>
using namespace std;


vector<int>::iterator unique(vector<int> &a) {
	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		if (!i || a[i] != a[i-1])
			a[j++] = a[i];
	}
	// 至此，a[0]~a[j-1]是a中所有不同的数
	// 返回下一个位置迭代器 
	return a.begin() + j;
}

int main() {
	int a[] = {1,1,2,2,3,3,3,5,6,7,7,8,9,9,10,11,11,11};
	vector<int> v(a, a+18);

	int val = *unique(v); // 去重，并返回下一个位置 
	cout << val << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}
