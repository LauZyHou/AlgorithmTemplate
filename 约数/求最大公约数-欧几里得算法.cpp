#include <iostream>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/941/1/

ŷ������㷨��Ҳ��շת�����
���d������a��d������b����ôd������ax+by
a��b�����Լ�����͵���b��aģb�����Լ��
��gcd(a, b)==gcd(b, a%b)����Ϊa%b��д��a-kb����ʽ 
ʱ�临�Ӷ�O(logn) 
*/

int gcd(int a, int b) {
	// ��b��Ϊ0ʱ����b��a%b�����Լ������b��0ʱ��a��0�����Լ������a 
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n --) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
 
