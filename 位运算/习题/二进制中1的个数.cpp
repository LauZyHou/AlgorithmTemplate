#include <iostream>
using namespace std;

int n, x, ans;

int lowbit(int x) {
	return x & -x;
}

int main() {
	cin >> n;
	
	while (n--) {
		ans = 0;
		cin >> x;
		while (x) {
			x -= lowbit(x); // ÿ�μ�ȥ���һλ1
			ans++; 
		}
		cout << ans << ' ';
	}
	
	return 0;
}
