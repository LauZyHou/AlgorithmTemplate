#include <iostream>
#include <vector>

using namespace std;

// https://www.acwing.com/problem/content/340/

// 求一个从低位到高位存储的数，从第l位到第r位村存储的数字是多少
// 这里让l<=r，但是比如num = {1,2,3}其实存的是321，所以从r到l枚举 
int get(vector<int> num, int l, int r) {
	if (l > r) swap(l, r);
	int res = 0;
	for (int i = r; i >= l; i -- )
		res = res * 10 + num[i];
	return res;
}

// 求10的k次方
int pow10(int k) {
	int res = 1;
	while (k --)
		res *= 10;
	return res;
}

// 计算从1~n中所有数的十进制表示里x出现的次数 
int count(int n, int x) {
	if (!n) return 0; // 因为统计的是1~n，如果n就是0就直接返回0
	
	// 把n的每一位抠出来，这里是从小到大
	vector<int> num;
	while (n) {
		num.emplace_back(n % 10);
		n /= 10;
	}
	
	// 后续让n表示num有多少位
	n = num.size();
	// res记录所求的答案：1~num表示的数里x出现的次数 
	int res = 0;
	// 从最高位开始枚举每一位
	// 当x=0时，最高位不能是0，所以要从第此高位开始枚举，所以这里 - !x 
	for (int i = n - 1 - !x; i >= 0; i -- ) {
		// 当枚举的是最高位时候，情况1是不存在的（不能从0枚举到-1）
		// 所以情况1只考虑枚举的不是最高位的情况
		if (i < n - 1) {
			// 枚举的这一位前面的所有位构成的数字，乘以后面的位数i对应的10的i次方 
			res += get(num, n - 1, i + 1) * pow10(i);
			// 当目标值是0时候，因为不能从0..0开始，要从0..1开始，所以要少乘一个pow10(i);
			if (x == 0)
				res -= pow10(i); 
		}
		// 第2种情况的2.1，当d<x时是无解的，所以不用考虑
		// 第2种情况的2.2，当d=x时
		if (num[i] == x) {
			// i后面的所有位构成的数字+1
			res += get(num, i - 1, 0) + 1; 
		}
		// 第2种情况的2.2，当d>x时
		else if(num[i] > x) {
			// 直接加后面的位数i对应的10的i次方
			res += pow10(i); 
		}
	}
	
	return res;
}

int main() {
	int a, b;
	// 读入a,b并且不都是0 
	while (cin >> a >> b, a || b) {
		// 保持a <= b 
		if (a > b) swap(a, b);
		
		// 计算a~b之间所有数的十进制表示里0~9出现的次数
		for (int x = 0; x <= 9; x ++ )
			cout << count(b, x) - count(a - 1, x) << ' ';
		cout << endl; 
	}
	
	return 0;
}
