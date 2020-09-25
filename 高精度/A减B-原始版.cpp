#include <iostream>
#include <vector>
using namespace std;

/*
(�Ǹ�)������A-������B
ʮ����λ��len(A)<=10^6��len(B)<=10^6
������֮ǰҪ�жϣ����A<B����ôҪ����B-A��Ȼ����������һ������ 
*/

vector<int> sub(vector<int> &A, vector<int> &B) {
	int alen = A.size();
	int blen = B.size();
	
	vector<int> C;
	
	int t = 0; // 1:�ղ�������һλ��λ����������Ҫ����1 
	for (int i = 0; i < alen; i++) {
		t = A[i] - t;
		if (i < blen) t -= B[i];
		C.push_back((t + 10) % 10);
		// �ж���û�н���һλ������һλ�ͱ��tΪ1��������tΪ0 
		if (t < 0) t = 1;
		else t = 0;
	}
	
	// ��ΪA�ж���λ���н�����ж���λ�����Կ���ǰ�滹������0
	// ɾ��ǰ���0��������������0��Ҫ����һ��0 
	while (C.size()	> 1 && C.back() == 0)
		C.pop_back();
	return C;
}

// �ж��Ƿ��� A >= B
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
	
	// ȷ�����ü����ĺ���ʱA >= B 
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
