#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
(�Ǹ�)������A / С����b������C��������r 
ʮ����λ��len(A)<=10^6
��Ϊb��һ��С������ÿ�ν�b����һ�������A�е�ÿһλ������ 

ע�⣺�����Ǵ����λ��ʼ��ģ����ӷ����������˷����Ǵ����λ��ʼ���
���������Ŀ��ֻ�г�������ô�������棨�����λ->��λ ����λ->��λ�������д 
һ������¸߾��ȵ���Ŀ�ж��ǼӼ��˳����еģ�����Ϊ������һ����
����ʵ�ֵĳ����Ĵ洢��ʽҲ��ǰ��һ���Ĵӵ�λ����λ���������棩 
*/

vector<int> div(vector<int> &A, int b, int &r) {
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		r = r*10 + A[i];
		C.push_back(r / b);
		r %= b; 
	}
	
	// ������õ���C��Ӧ������������ģ�����Ϊ�˱���һ��
	// �������ǵ������棬���ﷴ��һ�£����ֶ����ʽһ�� 
	reverse(C.begin(), C.end());
	// ���о��ǿ���һ��ǰ��0����Ϊ�Ѿ������ˣ�����ǰ��0��ĩβ
	while (C.size() > 1 && C.back()==0)
		C.pop_back();
	
	return C;
}


int main() {
	string a;
	int b;
	
	cin >> a >> b;
	
	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	
	int r; // ������ͨ�����ô�����
	auto C = div(A, b, r);
	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	printf("\n%d\n", r);
	
	return 0;
}
