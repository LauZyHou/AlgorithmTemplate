#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/832/

单调栈一般用于在给定的序列上每一个数左边（或者右边）离它最近的比它小（或者大）的数
例如，【左边】最近【比它小】
序列： 3  4  2  7  5
得到：-1  3 -1  2  2
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
		// 当栈不为空，不断弹出栈顶>=当前值的元素，这些不可能再作为所求结果出现 
		while (tt && stk[tt] >= x)
			tt--;
		// 这里要判断一下，栈为空输出-1，否则栈顶元素就是左边最近比它小的 
		if (tt)
			cout << stk[tt] << ' ';
		else
			cout << -1 << ' ';
		// 注意把当前值加进来
		stk[++tt] = x; 
	}
	
	return 0;
}
