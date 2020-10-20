#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/206/
// �����Ǳ����������ַ�ʽ�����Ǹ���m�����ʰ���й�ʣ�ඨ�� 

typedef long long LL;

const int N = 30;

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	LL d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}



int main() {
	int n;
	scanf("%d", &n);
	
	bool has_answer = true; // �Ƿ��н�
	// ������Ҫÿ�ν���������x = a1 (mod m1)��x = a2 (mod m2)�ϲ�����һ���� 
	LL a1, m1;
	scanf("%lld%lld", &a1, &m1);
	for (int i = 0; i < n - 1; i ++) {
		LL a2, m2;
		scanf("%lld%lld", &a2, &m2);
		
		// �ϲ����̣�a1k1 - a2k2 = m1 - m2����m1 - m2��gcd(a1, a2)�ı���ʱ�н�
		// ע������������k2ʵ�����ǹ�ʽ���-k2����������ֻ����k1 
		LL k1, k2;
		LL d = exgcd(a1, a2, k1, k2);
		// �ж��Ƿ��н�
		if ((m1 - m2) % d) {
			has_answer = false;
			break;
		}
		
		// ����exgcd�����a1k1+a2k2=gcd(a1, a2)=d��k1��k2����������Ҫ��k1����Ӧ�ı��� 
		k1 *= (m2 - m1) / d;
		// ����k1 +- �����a2/dҲ���ǽ⣬��������Ҫ��ɽ��������С��ֵ
		// Ҳ���Ǳ����ģa2/dʱ��k1ͬ�����С��ֵ
		int t = a2 / d;
		k1 = (k1 % t + t) % t;
		
		// ����ϲ����һ���������m1��a1
		m1 = a1 * k1 + m1;
		a1 = abs(a1 / d * a2); // a1���a1��a2����С���������� 
	}

	if (has_answer)
		printf("%lld\n", (m1 % a1 + a1) % a1);
	else
		puts("-1");
	
	return 0;
}
