#include <iostream>
using namespace std;

/*
浮点数二分因为没有整除问题
每次一定能严格分成两半
所以不用处理边界 
当区间长度已经很小时候，比如r-l<=1e-6
就可以认为找到了答案
这时候可以用l或者用r或者用(l+r)/2当作答案都行 
*/

// 基于精度的浮点数二分 
double bsearch_1(double l, double r) {
	// 题目要求保留6位小数就1e-8，即至少要比要求的有效位数多2 
	while (r - l > 1e-8) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	return l;
}

// 基于迭代次数的浮点数二分
double bsearch_2(double l, double r) {
	// 这个就是不考虑精度，直接跑够多少次 
	// 循环n次就是将区间长度缩小2^n倍 
	for (int i = 0; i < 100; i++) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	return l;
}
