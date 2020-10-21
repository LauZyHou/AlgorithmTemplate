#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/891/

// ��������ϵ����ԭ�㿪ʼ��0��ʾ�����ߣ�1��ʾ������ 
// �Ӷ�����ת���ɵ�(n,n)��·������
// Ҫ��ľ���y=x����߼�������ĵ�(n,n)·������ 
// Ҳ�����ϸ��ܽӴ�y=x+1����ߵ�·������
// ��(0,0)�ߵ�(n,n)��·��������C_{2n}^n
// ֻҪ�ټ�ȥ�Ӵ�y=x+1����ߵ�·����
// ֻҪ�Ӵ���y=x+1���ʹ�����㿪ʼ�Ѻ����·������y=x+1����Գ�
// ����·����һ������(n-1,n+1)�����
// ����Ҫ��ȥ�ľ��Ǵ�(0,0)��(n-1,n+1)��·������
// ���Դ𰸾���C_{2n}^n - C_{2n}^{n-1} 
// �����C_{2n}^n / (n + 1)��Ҳ��Ϊ�����������ܶ�����ķ��������ǿ������� 

typedef long long LL;

const int mod = 1e9 + 7;

// ������
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


int main() {
	int n;
	scanf("%d", &n);
	
	// ��C_{2n}^n / (n + 1) ģ mod
	// ��Ϊmod��һ�����������Կ����÷���С����+����������Ԫ����
	int a = 2 * n, b = n;
	int res = 1;
	
	for (int i = a; i > a - b; i --)
		res = (LL)res * i % mod;
	for (int i = 1; i <= b; i ++)
		res = (LL)res * qmi(i, mod - 2, mod) % mod; // �������ǳ�����Ԫ
	
	res = (LL)res * qmi(n + 1, mod - 2, mod) % mod; // ����n+1
	
	printf("%d\n", res);
	
	return 0; 
}
