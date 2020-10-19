#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/875/

ŷ������phi(n)����1~n����n���ʵ�Ԫ�ظ���
��1~6��1��5��������6���ʣ�����phi(6)=2
�ⷨ�� 
��n��ʽ�ֽ�Ϊn=p1^a1+p2^a2+...+pk^ak
��phi(n)=n(1-1/p1)(1-1/p2)...(1-1/pk)
����n = 6 = 2 * 3
phi(6) = 6 * (1 - 1/2) * (1 - 1/3) = 2
*/

int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int x;
		scanf("%d", &x);
		
		int ans = x; // ��x��ŷ������
		// �ֽ�������
		for (int i = 2; i <= x / i; i ++)
			if (x % i == 0) { // ˵��i��x�������� 
				ans = ans / i * (i - 1); // ����(1 - 1/i)
				while (x % i == 0) // ��i���ɾ� 
					x /= i; 
			}
		// ������ʣһ��������
		if (x > 1)
			ans = ans / x * (x - 1);
		printf("%d\n", ans);
	}
	
	return 0;
}
