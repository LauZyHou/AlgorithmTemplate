#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/4/

ֻ�������ȫ���������������ƣ����ذ������ 
*/

const int N = 110;

int v[N], w[N], s[N];
int dp[N][N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d%d%d", v + i, w + i, s + i);
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			// ��������Ҳ���Բ���k��ѭ�����k��0��ʼ������ 
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= s[i] && k * v[i] <= j; k ++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
		}
	}
	
	printf("%d\n", dp[n][m]);
	
	return 0;
}
