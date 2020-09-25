#include <iostream>
using namespace std;

/*
一维前缀和
s[i] = a[1]+...+a[i]
即
s[i] = s[i-1]+a[i]，让下标从1开始，这样只要定义s[0]=0，方便处理边界 

可以快速查询一个区间的和，比如[l, r]区间的和
只需要s[r]-s[l-1]即可 
*/

const int N = 1e5 + 10;

int n, m;
int a[N], s[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i]; 
	}
	
	int l, r;
	while (m--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	
	return 0;
} 
