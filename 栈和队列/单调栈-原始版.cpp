#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/832/

����ջһ�������ڸ�����������ÿһ������ߣ������ұߣ���������ı���С�����ߴ󣩵���
���磬����ߡ����������С��
���У� 3  4  2  7  5
�õ���-1  3 -1  2  2
*/

const int N = 1e5 + 10;

int n, x;
int stk[N], tt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		// ��ջ��Ϊ�գ����ϵ���ջ��>=��ǰֵ��Ԫ�أ���Щ����������Ϊ���������� 
		while (tt && stk[tt] >= x)
			tt--;
		// ����Ҫ�ж�һ�£�ջΪ�����-1������ջ��Ԫ�ؾ�������������С�� 
		if (tt)
			cout << stk[tt] << ' ';
		else
			cout << -1 << ' ';
		// ע��ѵ�ǰֵ�ӽ���
		stk[++tt] = x; 
	}
	
	return 0;
}
