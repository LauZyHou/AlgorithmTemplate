#include <iostream>
using namespace std;

/*
������������Ϊû����������
ÿ��һ�����ϸ�ֳ�����
���Բ��ô���߽� 
�����䳤���Ѿ���Сʱ�򣬱���r-l<=1e-6
�Ϳ�����Ϊ�ҵ��˴�
��ʱ�������l������r������(l+r)/2�����𰸶��� 
*/

// ���ھ��ȵĸ��������� 
double bsearch_1(double l, double r) {
	// ��ĿҪ����6λС����1e-8��������Ҫ��Ҫ�����Чλ����2 
	while (r - l > 1e-8) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	return l;
}

// ���ڵ��������ĸ���������
double bsearch_2(double l, double r) {
	// ������ǲ����Ǿ��ȣ�ֱ���ܹ����ٴ� 
	// ѭ��n�ξ��ǽ����䳤����С2^n�� 
	for (int i = 0; i < 100; i++) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	return l;
}
