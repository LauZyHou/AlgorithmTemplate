#include <iostream>

using namespace std;

/*

基于定义求欧拉函数是求一个数的欧拉函数
有些时候要求1~n所有数的欧拉函数
如果还是用基于定义的求法，那么求n个数的欧拉函数的时间复杂度是O(n根号n) 
这个时候就可以用筛法去求了，时间复杂度是O(n)
注：线性筛法可以顺便求出来很多东西 
*/

typedef long long LL;

const int N = 1e6 + 10;

// 线性筛
int primes[N], cnt;
bool st[N];
// 欧拉函数表
int phi[N]; 

// 线性筛法求1~n每个数的欧拉函数的加和
LL get_eulers(int n) {
	phi[1] = 1;
	for (int i = 2; i <= n; i ++) {
		// 如果没被筛掉，是质数
		if (!st[i]) {
			primes[cnt ++] = i;
			phi[i] = i - 1; // 质数的欧拉函数就是它减去1 
		}
		// 筛掉质数表里的primes[j] * i，满足primes[j] <= 该数的最小质因数 
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = true; // 筛掉primes[j] * i
			// 如果primes[j]已经是最小质因数了
			if (i % primes[j] == 0) {
				phi[primes[j] * i] = phi[i] * primes[j];
				break; // 跳出 
			}
			// 如果是primes[j]是互质的更小的一个质数 
			else {
				phi[primes[j] * i] = phi[i] * (primes[j] - 1);
			}
		}
	}
	
	// 计算本题要的，从1到n的欧拉函数的和
	LL ans = 0;
	for (int i = 1; i <= n; i ++)
		ans += phi[i]; 
	return ans;
} 

int main() {
	int n;
	scanf("%d", &n);
	
	printf("%lld\n", get_eulers(n));
	
	return 0;
}
