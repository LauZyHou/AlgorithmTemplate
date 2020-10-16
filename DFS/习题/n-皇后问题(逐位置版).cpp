#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/845/
// ����һ��ԭʼ����λ�õ�˼·����n-�ʺ���û����ÿ��ֻ�ܷ�һ�������Ϣ
// ֱ�������а������ 

const int N = 10;

char g[N][N];
bool row[N], col[N], dg[2 * N], udg[2 * N];

int n;

// ��<x,y>λ�ü����������Ѿ�����s���ʺ� 
void dfs(int x, int y, int s) {
	// ����ж��������ˣ��ͼ���һ�У��������ӵ�0�п�ʼ 
	if (y == n) {
		y = 0;
		x ++;
	}
	// �����������n����ô��Ҫ���ǻ����� 
	if (x == n) {
		// ���n���ʺ󶼷����ˣ����ҵ���һ���� 
		if (s == n) {
			for (int i = 0; i < n; i ++)
				puts(g[i]);
			puts("");
			return ;
		}
		return ;
	}
	// ��<x,y>λ�ò��Żʺ�����
	dfs(x, y + 1, s);
	// ��<x,y>λ�ó��ԷŻʺ�����
	if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
		g[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
		dfs(x, y + 1, s + 1); // �������е���һ��
		g[x][y] = '.';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			g[i][j] = '.';
	
	// ��0��0��λ�ÿ�ʼ���Ѿ�����0���ʺ� 
	dfs(0, 0, 0);
	
	return 0;
} 
