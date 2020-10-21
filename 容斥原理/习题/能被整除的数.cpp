#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/description/892/

typedef long long LL;

const int M = 20;

int p[M]; // m个质数 

int main() {
	int n, m; // 整数是1~n，质数是m个 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++)
		scanf("%d", p + i);
	
	int res = 0; // 答案，容斥原理求m个集合的并集中元素数目
	// 从1到2^m-1枚举，每个二进制数1的位置表示选这个集合，0表示不选这个集合
	// 这样每个数i的二进制都表示若干个集合的交集
	for (int i = 1; i < (1 << m); i ++) {
		int t = 1; // 当前所有质数的乘积
		int cnt = 0; // 当前数i的二进制里包含几个1，也就是当前是求几个集合的交集
		// 枚举数字i二进制的0~m-1位每一位
		for (int j = 0; j < m; j ++)
			// 如果当前这一位是1
			if ((i >> j) & 1) {
				cnt ++; // 统计是1的位数
				// 乘之前判断一下，因为只考虑1~n之间的，如果质数乘积超过n了就不用管了
				if ((LL)t * p[j] > n) {
					t = -1; // 标记一下这些质数相乘是>n的
					break; // 跳出，其它位都不用再算了 
				}
				// 将这个质数乘到t里 
				t = t * p[j]; 
			}
		// 仅当t!=-1，也就是质数相乘不超过n时才算
		if (t != -1) {
			// 判断一下有几个集合，根据容斥原理
			// 如果是奇数个集合就加上，偶数个集合就减去
			if (cnt & 1)
				res += n / t; // 因为是互质的，所以同时被这些数整除的数就是同时被它们乘积整除的数
			else
				res -= n / t; 
		}
	}
	
	printf("%d\n", res);
	              
	return 0;
}
