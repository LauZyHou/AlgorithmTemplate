#include <iostream>
#include <vector>
using namespace std;

/*
(非负)大整数A+大整数B
十进制位数len(A)<=10^6，len(B)<=10^6 
*/

vector<int> add(vector<int> &A, vector<int> &B) {
	int alen = A.size();
	int blen = B.size();
	
	vector<int> C;
	
	int t = 0;
	for (int i = 0; i < alen || i < blen; i++) {
		if (i < alen) t += A[i];
		if (i < blen) t += B[i];
		C.push_back(t % 10);
		t /= 10; // 进位 
	}
	if (t) C.push_back(t);
	return C;
}


int main() {
	string a, b;
	vector<int> A, B;
	
	cin >> a >> b;
	int alen = a.size();
	int blen = b.size();
	
	for (int i = alen - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for (int i = blen - 1; i >= 0; i--) B.push_back(b[i] - '0');
	
	auto C = add(A, B);
	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	return 0;
}
