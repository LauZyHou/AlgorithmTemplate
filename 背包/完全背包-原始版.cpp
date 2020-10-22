#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/3/

dp[i][j]��01����ʱ��һ�������Ǳ�ʾֻ����ǰi����Ʒ���������������j������ѡ������ 
����01������ֻ��ѡһ�����߲�ѡ������������Ͽ��Բ����������
��ȫ���������ѡ�������������������Ҳ���Բ�ɶ�����ϣ� 
��i����Ʒѡ0����ѡ1����ѡ2����ѡ3����... 
��i����Ʒѡ��k�����ǣ�f[i-1][j-k*v[i]] + k*w[i]����Ȼk*v[i]<=j���� 
*/

const int N = 1010;

int v[N], w[N];
int dp[N][N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", v + i, w + i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			for (int k = 0; k * v[i] <= j; k ++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
	
	printf("%d\n", dp[n][m]);	
	
	return 0;
}
