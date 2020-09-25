#include <iostream>
#include <vector>
using namespace std;


/*
(�Ǹ�)������A * С����b
ʮ����λ��len(A)<=10^6
��Ϊb��һ��С������ÿ�ν�b����һ�������A�е�ÿһλ���˷� 
*/

vector<int> mul(vector<int> &A, int b) {
	vector<int> C;
	
	// ����bΪ0���������������A.size()��0
	// �ڳ˷������������������ǰ��0������ֻ�������b������ 
	if (!b) {
		C.push_back(0);
		return C;
	}
	
	int t = 0;
	// �˷�һֱ�˳����Ľ�λ���ܷǳ��󣬽�λû����ʱ��Ҳ���ܽ��� 
	for (int i = 0; i < A.size() || t; i++) {
		// A�ﻹ������û��ʱ��ȡ������ֺ�b��˼ӵ���λ�� 
		if (i < A.size())
			t += A[i] * b;
		// ��λģ��10���ǵ�ǰλ��Ӧ�����µ���������10���Ǽ������λ�Ľ�λ
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
