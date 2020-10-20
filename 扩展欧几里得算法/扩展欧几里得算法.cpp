#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/879/
*/

// ��չŷ������㷨
// �����÷���ʹ��ax+by=gcd(a,b)��x��y
// �ӷ���ֵ����gcd(a,b) 
int exgcd(int a, int b, int &x, int &y) {
	// b����0ʱ��gcd(a,b)=a��xȡ1��yȡ0 
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	// b������0ʱ������b��a%b��gcd��ͬʱ�����x��yʹ��
	// by + (a%b)x = gcd(b, a%b) = gcd(a, b)
	int d = exgcd(b, a % b, y, x);
	// ��Ϊ a % b ����a - (a/b)*b������(a/b)����ȡ�� 
	// ����by + [a - (a/b)*b]x = gcd(a, b)
	// ����ax + b[y - (a/b)x] = gcd(a, b)
	// ����a��ϵ������xû��b��ϵ����y - (a/b)x
	y = y - (a/b)*x;
	return d;
}

int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		int a, b, x, y;
		scanf("%d%d", &a, &b);
		
		exgcd(a, b, x, y);
		printf("%d %d\n", x, y);
	}
	
	return 0;
}
