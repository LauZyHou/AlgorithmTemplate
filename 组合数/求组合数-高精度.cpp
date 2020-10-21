#include <iostream>
#include <vector>

using namespace std;

/*
https://www.acwing.com/problem/content/890/

高精度组合数，先把2-a之间质数筛出来
然后对组合数分解质因数，记录出现次数，最后高精度乘起来 
*/

const int N = 5010;

// 线性筛 
int primes[N], cnt;
bool st[N];

void get_primes(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i])
			primes[cnt ++] = i;
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0)
				break;
		}
	}
}

// 计算n!里p出现次数
int get(int n, int p) {
	int res = 0;
	while (n) {
		res += n / p;
		n /= p; 
	}
	return res;
}

// 高精度乘法
vector<int> mul(vector<int> &a, int b) {
	vector<int> c; // 结果
	int t = 0; // 进位
	// 从低位到高位依次乘过去 
	for (int i = 0; i < a.size(); i ++) {
		t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	// 最后还有剩的进位都加到末尾（高位上） 
	while (t) {
		c.push_back(t % 10);
		t /= 10;
	}
	return c;
} 

// 每个质数出现多少次 
int sum[N];

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	
	get_primes(a);
	
	// 统计C_a^b里每个质数出现次数
	for (int i = 0; i < cnt; i ++) {
		int p = primes[i]; // 当前质数
		sum[i] = get(a, p) - get(b, p) - get(a - b, p);
	}
	
	// 高精度乘法把结果乘出来
	vector<int> res;
	res.push_back(1); // 从1开始乘
	
	// 每个质数primes[i]都要乘sum[i]次
	for (int i = 0; i < cnt; i ++)
		for (int j = 0; j < sum[i]; j ++)
			res = mul(res, primes[i]);
	
	// 从高位到低位输出结果
	for (int i = res.size() - 1; i >= 0; i --)
		printf("%d", res[i]);
	puts("");
	 
	return 0;
}
