#include <iostream>

using namespace std;


/*
https://www.acwing.com/problem/content/877/
	
�����ݿ��Կ������a^k % p�Ľ����ʱ�临�Ӷ�O(alogk)
����a��p��k����1e9�ķ�Χ��
ԭʼ�ı��������ǰ�a����k�Σ�ÿ��ģp��ʱ�临�Ӷ���O(k)�� 
����˼·������ƽ�� 
*/

typedef long long LL;

int qmi(LL a, int k, int p) {
	LL res = 1;
	// �����ݣ�ÿ��ȡk�����λ�������1����ô��Ӧ��a^2^i���Ҫ����ȥ 
	// ��ʼʱa^2^0����a^1=a 
	while (k) { 
		if (k & 1)
			res = res * a % p;
		k >>= 1;
		a = a * a % p; // ÿ�ζ��������ƽ��	 
	}
	return res;
}


int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int a, k, p; // a^k mod p
		scanf("%d%d%d", &a, &k, &p);
		printf("%d\n", qmi(a, k, p));
	}
	
	return 0;
}
