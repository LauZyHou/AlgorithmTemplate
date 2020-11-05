#include <iostream>
#include <vector>

using namespace std;

// https://www.acwing.com/problem/content/340/

// ��һ���ӵ�λ����λ�洢�������ӵ�lλ����rλ��洢�������Ƕ���
// ������l<=r�����Ǳ���num = {1,2,3}��ʵ�����321�����Դ�r��lö�� 
int get(vector<int> num, int l, int r) {
	if (l > r) swap(l, r);
	int res = 0;
	for (int i = r; i >= l; i -- )
		res = res * 10 + num[i];
	return res;
}

// ��10��k�η�
int pow10(int k) {
	int res = 1;
	while (k --)
		res *= 10;
	return res;
}

// �����1~n����������ʮ���Ʊ�ʾ��x���ֵĴ��� 
int count(int n, int x) {
	if (!n) return 0; // ��Ϊͳ�Ƶ���1~n�����n����0��ֱ�ӷ���0
	
	// ��n��ÿһλ�ٳ����������Ǵ�С����
	vector<int> num;
	while (n) {
		num.emplace_back(n % 10);
		n /= 10;
	}
	
	// ������n��ʾnum�ж���λ
	n = num.size();
	// res��¼����Ĵ𰸣�1~num��ʾ������x���ֵĴ��� 
	int res = 0;
	// �����λ��ʼö��ÿһλ
	// ��x=0ʱ�����λ������0������Ҫ�ӵڴ˸�λ��ʼö�٣��������� - !x 
	for (int i = n - 1 - !x; i >= 0; i -- ) {
		// ��ö�ٵ������λʱ�����1�ǲ����ڵģ����ܴ�0ö�ٵ�-1��
		// �������1ֻ����ö�ٵĲ������λ�����
		if (i < n - 1) {
			// ö�ٵ���һλǰ�������λ���ɵ����֣����Ժ����λ��i��Ӧ��10��i�η� 
			res += get(num, n - 1, i + 1) * pow10(i);
			// ��Ŀ��ֵ��0ʱ����Ϊ���ܴ�0..0��ʼ��Ҫ��0..1��ʼ������Ҫ�ٳ�һ��pow10(i);
			if (x == 0)
				res -= pow10(i); 
		}
		// ��2�������2.1����d<xʱ���޽�ģ����Բ��ÿ���
		// ��2�������2.2����d=xʱ
		if (num[i] == x) {
			// i���������λ���ɵ�����+1
			res += get(num, i - 1, 0) + 1; 
		}
		// ��2�������2.2����d>xʱ
		else if(num[i] > x) {
			// ֱ�ӼӺ����λ��i��Ӧ��10��i�η�
			res += pow10(i); 
		}
	}
	
	return res;
}

int main() {
	int a, b;
	// ����a,b���Ҳ�����0 
	while (cin >> a >> b, a || b) {
		// ����a <= b 
		if (a > b) swap(a, b);
		
		// ����a~b֮����������ʮ���Ʊ�ʾ��0~9���ֵĴ���
		for (int x = 0; x <= 9; x ++ )
			cout << count(b, x) - count(a - 1, x) << ' ';
		cout << endl; 
	}
	
	return 0;
}
