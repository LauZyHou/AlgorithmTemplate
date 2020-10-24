#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/description/9/

ֻҪ����ÿ������ѡ��һ�����߲�ѡ������ 
*/

const int N = 110;

// ��i��ĵ�j����Ʒ 
int v[N][N], w[N][N];

// ��i����Ʒ�ж��ٸ�
int s[N]; 

// һά����dp����
int f[N]; 

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++) {
		scanf("%d", s + i);
		for (int j = 0; j < s[i]; j ++) {
			scanf("%d%d", &v[i][j], &w[i][j]);
		}
	}
	
	// һά���ı�������ÿһ�� 
	for (int i = 1; i <= n; i ++) {
		// ��ÿ�����j
		for (int j = m; j >= 0; j --) {
			// ������ĵ�k����Ʒ
			for (int k = 0; k < s[i]; k ++) {
				// ���������Ʒ�����������jʱ������
				if (v[i][k] <= j)
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]); 
			}
		} 
	}
	
	printf("%d\n", f[m]);
	
	return 0;
} 
