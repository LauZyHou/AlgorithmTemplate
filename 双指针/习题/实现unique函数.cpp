#include <iostream>
#include <vector>
using namespace std;


vector<int>::iterator unique(vector<int> &a) {
	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		if (!i || a[i] != a[i-1])
			a[j++] = a[i];
	}
	// ���ˣ�a[0]~a[j-1]��a�����в�ͬ����
	// ������һ��λ�õ����� 
	return a.begin() + j;
}

int main() {
	int a[] = {1,1,2,2,3,3,3,5,6,7,7,8,9,9,10,11,11,11};
	vector<int> v(a, a+18);

	int val = *unique(v); // ȥ�أ���������һ��λ�� 
	cout << val << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}
