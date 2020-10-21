#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/891/

// 画张坐标系，从原点开始，0表示向右走，1表示向上走 
// 从而可以转换成到(n,n)的路径问题
// 要求的就是y=x这根线及其下面的到(n,n)路径总数 
// 也就是严格不能接触y=x+1这根线的路径总数
// 从(0,0)走到(n,n)，路径总数是C_{2n}^n
// 只要再减去接触y=x+1这根线的路径数
// 只要接触了y=x+1，就从这个点开始把后面的路径对于y=x+1做轴对称
// 这样路径就一定到达(n-1,n+1)这个点
// 所以要减去的就是从(0,0)到(n-1,n+1)的路径数量
// 所以答案就是C_{2n}^n - C_{2n}^{n-1} 
// 化简得C_{2n}^n / (n + 1)，也称为卡特兰数，很多问题的方案数都是卡特兰数 

typedef long long LL;

const int mod = 1e9 + 7;

// 快速幂
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
	
	// 求C_{2n}^n / (n + 1) 模 mod
	// 因为mod是一个质数，所以可以用费马小定理+快速幂求逆元来算
	int a = 2 * n, b = n;
	int res = 1;
	
	for (int i = a; i > a - b; i --)
		res = (LL)res * i % mod;
	for (int i = 1; i <= b; i ++)
		res = (LL)res * qmi(i, mod - 2, mod) % mod; // 除法就是乘以逆元
	
	res = (LL)res * qmi(n + 1, mod - 2, mod) % mod; // 除以n+1
	
	printf("%d\n", res);
	
	return 0; 
}
