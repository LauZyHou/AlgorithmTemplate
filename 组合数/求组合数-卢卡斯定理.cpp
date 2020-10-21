#include <iostream>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/957/1/

��a��b��ģ�ܴ󣬵���ѯ��������ʱ������¬��˹������������� 
C_a^b = C_{a % p}^{b % p} * C_{a / p}^{b / p}
��Ϊ��ѯ�������࣬���ø���������ֻҪÿ���ö����������� 
*/

typedef long long LL; 

// �����ݣ���������������Ԫ
int qmi(int a, int k, int p) {
	int res = 1;
	while (k) {
		if (k & 1)
			res = (LL)res * a % p;
		k >>= 1;
		a = (LL)a * a % p; 
	}
	return res;
} 

// ���ݶ�����C_a^bģp�Ľ�� 
int C(int a, int b, int p) {
	if (b > a)
		return 0;
	int res = 1;
	// C_a^b = a*(a-1)*...*(a-b+1) / b!
	// ���¶���b�ѭ��b�ξ�����
	for (int i = 1, j = a; i <= b; i ++, j --) {
		res = (LL)res * j % p;
		// ��Ϊ�Ǵ�ģp�ģ���������ö�p����Ԫ���� 
		res = (LL)res * qmi(i, p - 2, p) % p;
	}
	return res;
}

// ¬��˹������C_a^bģp�Ľ�� 
int lucas(LL a, LL b, int p) {
	// ���a��b����p��С��¬��˹����ڶ�����1����һ�����C_a^b��ֱ����
	if (a < p && b < p)
		return C(a, b, p);
	// ¬��˹�����һ���abȡģ֮��һ����pС��ֱ���������
	// ¬��˹����ڶ����ab����֮����ܻ��Ǻܴ�Ҫ������¬��˹������ 
	return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		LL a, b;
		int p; // ģ�� 
		scanf("%lld%lld%d", &a, &b, &p);
		printf("%d\n", lucas(a, b, p));
	}
	
	return 0;
} 
