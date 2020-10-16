#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/845/

const int N = 20;

char g[N][N]; // ���� 

bool col[N]; // �б����õ���� 
bool dg[N], udg[N]; // ����ͷ���ĶԽ���ʹ����� 

int n;

// ����dfs 
void dfs(int u) {
	// �ҵ��� 
	if (u == n) {
		for (int i = 0; i < n; i ++)
			puts(g[i]);
		puts("");
		return ;
	}
	// �ڸ��е�ÿ����jλ�ü�鲢���ûʺ�
	for (int j = 0; j < n; j ++)
		if (!col[j] && !dg[u + j] && !udg[u - j + n]) {
			g[u][j] = 'Q';
			col[j] = dg[u + j] = udg[u - j + n] = true;
			dfs(u + 1);
			g[u][j] = '.';
			col[j] = dg[u + j] = udg[u - j + n] = false;
		}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			g[i][j] = '.';
	
	dfs(0); // ����dfs
	
	return 0; 
}
