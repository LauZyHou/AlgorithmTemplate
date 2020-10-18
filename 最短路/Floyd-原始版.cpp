#include <iostream>

using namespace std;


/*
https://www.acwing.com/problem/content/856/

Floyd�㷨�������Դ�����·�����ڽӾ����ͼ 
��dp[k][i][j]��ʾ��i��j��ֻ������1~k��Щ������·
��dp[k][i][j] = min(dp[k][i][j], dp[k-1][i][k] + dp[k-1][k][j]) 
����kÿ�ζ���֮ǰ�ĸ��£�ֻҪ�ȱ���k�Ͳ���k���ά���� 
*/

const int N = 2e2 + 10;
const int M = 2e4 + 10;

// �տ�ʼ�Ǵ�ͼ��������֮��ľ���
// Floyd�ܹ�֮���Ǵ�������֮������· 
int d[N][N];


const int INF = 1e9;

int n, m, q;

int floyd() {
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
	
	while (m --) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		d[x][y] = min(d[x][y], z);
	}
	
	floyd();

	while (q --) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (d[x][y] > INF / 2) // INF���п��ܱ����߸��� 
			puts("impossible");
		else
			printf("%d\n", d[x][y]);
	}
	
	return 0;
}
