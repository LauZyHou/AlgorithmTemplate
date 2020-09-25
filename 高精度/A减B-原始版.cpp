#include <iostream>
#include <vector>
using namespace std;

/*
(非负)大整数A-大整数B
十进制位数len(A)<=10^6，len(B)<=10^6
做减法之前要判断，如果A<B，那么要计算B-A，然后给结果加上一个负号 
*/

vector<int> sub(vector<int> &A, vector<int> &B) {
	int alen = A.size();
	int blen = B.size();
	
	vector<int> C;
	
	int t = 0; // 1:刚才有向这一位借位，所以这轮要减掉1 
	for (int i = 0; i < alen; i++) {
		t = A[i] - t;
		if (i < blen) t -= B[i];
		C.push_back((t + 10) % 10);
		// 判断有没有借了一位，借了一位就标记t为1，否则标记t为0 
		if (t < 0) t = 1;
		else t = 0;
	}
	
	// 因为A有多少位最有结果就有多少位，所以可能前面还有若干0
	// 删除前面的0，但是如果结果是0需要保留一个0 
	while (C.size()	> 1 && C.back() == 0)
		C.pop_back();
	return C;
}

// 判断是否有 A >= B
bool cmp(vector<int> &A, vector<int> &B) {
	int alen = A.size();
	int blen = B.size();
	if (alen != blen) return alen > blen;
	
	for (int i = alen - 1; i >= 0; i--)
		if (A[i] != B[i])
			return A[i] > B[i];
	return true;
}


int main() {
	string a, b;
	vector<int> A, B;
	
	cin >> a >> b;
	int alen = a.size();
	int blen = b.size();
	
	for (int i = alen - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for (int i = blen - 1; i >= 0; i--) B.push_back(b[i] - '0');
	
	// 确保调用减法的函数时A >= B 
	if (cmp(A, B)) {
		auto C = sub(A, B);
		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	}
	else {
		auto C = sub(B, A);
		printf("-");
		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	}
	return 0;
}
