#include <iostream>
#include <vector>
using namespace std;


/*
(非负)大整数A * 小整数b
十进制位数len(A)<=10^6
因为b是一个小整数，每次将b当作一个整体和A中的每一位作乘法 
*/

vector<int> mul(vector<int> &A, int b) {
	vector<int> C;
	
	// 特判b为0的情况，否则会出现A.size()个0
	// 在乘法里，其它情况都不会出现前导0，所以只特判这个b就行了 
	if (!b) {
		C.push_back(0);
		return C;
	}
	
	int t = 0;
	// 乘法一直乘出来的进位可能非常大，进位没用完时候也不能结束 
	for (int i = 0; i < A.size() || t; i++) {
		// A里还有数字没乘时候，取这个数字和b相乘加到进位里 
		if (i < A.size())
			t += A[i] * b;
		// 进位模上10就是当前位置应该留下的数，除以10就是继续向高位的进位
		C.push_back(t % 10); 
		t /= 10;
	}
	
	return C;
}

int main() {
	string a;
	int b;
	
	cin >> a >> b;
	
	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	
	auto C = mul(A, b);
	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	
	return 0;
}
