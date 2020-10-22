#include <iostream>

using namespace std;

const int N = 1010;

// https://www.acwing.com/problem/content/2/
// ��Ϊdp[i][j]���Ǵ�dp[i-1][x]ת�����ģ����Կ��Բ�Ҫ��һά
// ����Ҫע����뷴�����������������ܱ�֤f[j-v[i]]��i-1ʱ��ģ��������ȱ��dp[i][j-v[i]] 

int v[N], w[N];
int f[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", v + i, w + i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = m; j >= v[i]; j --)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	
	printf("%d\n", f[m]);
	
	return 0;
}
