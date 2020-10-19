#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/868/

���d������n����ôn/dҲ������n
��n��Լ�����ǳɶԳ��ֵ�
����ֻ��Ҫö��d <= n/d�����͹���
��ֻҪö��d <= ����n��ʱ�临�Ӷ���O(����n) 
*/

bool is_prime(int n) {
	if (n < 2)
		return false;
	// ��Ҫдi*i <= n����Ϊ��n�ȽϽӽ�INT_MAXʱ
	// iö�ٹ����кܿ����������ѭ��û������ 
	// Ҳ��Ҫ��sqrt(n)����Ϊÿ����sqrt(n)Ҳ���� 
	for (int i = 2; i <= n / i; i ++) {
		if (n % i == 0)
			return false;	
	}
	return true;
}

int n;

int main() {
	scanf("%d", &n);
	while (n --) {
		int a;
		scanf("%d", &a);
		if (is_prime(a))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
