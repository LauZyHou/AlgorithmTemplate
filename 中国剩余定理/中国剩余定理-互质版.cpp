#include <iostream>

using namespace std;

// ��չŷ������㷨��ax+by=gcd(a, b)
int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

// ��b��ģmʱ�ĳ˷���Ԫ����֤b��m���� 
int inv(int b, int m) {
	int x, y;
	exgcd(b, m, x, y); // bx + my = gcd(b, m)
	// ��Ϊb��m���ʣ�����gcd(b, m) = 1
	// ����bx % m = (bx + my) % m = 1 % m = 1
	// ����x����b�ĳ˷���Ԫ�����ｫx���0~m-1֮��
	x = (x % m + m) % m;
	return x; 
}

const int N = 1e5 + 10;

// �����Ѿ�������n��m[i]�������ǻ��ʵ� 
// ����Ҳ������ͬ�෽�������n��a[i]
int n, m[N], a[N];
// �й�ʣ�ඨ��Chinese Remainer Theorem 
int CRT() {
	int M = 1, ans = 0;
	// ��M = m[i]�˻�
	for (int i = 0; i < n; i ++)
		M *= m[i];
	// ����ͬ�෽���� x \equiv a[i] (mod m[i])�Ľ��x
	// �������е�a[i] * Mi * Mi��ļӺ� 
	for (int i = 0; i < n; i ++) {
		int Mi = M / m[i];
		ans = (ans + a[i] * Mi * inv(Mi, m[i])) % M;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i ++)
		scanf("%d", &m[i]);
	printf("%d\n", CRT());
	return 0;
}
