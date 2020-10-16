#include <iostream>
#include <cstring>
using namespace std;

// https://www.acwing.com/problem/content/846/
// ��Ϊ�ƶ�һ��λ�þ�������һ���ģ����Կ���ֱ��BFS�����· 

typedef pair<int, int> PII;

const int N = 1e2 + 5;

// �Թ� 
int g[N][N];

// �����ʵĵ�Ķ���
PII q[N * N];

// ÿ���������ʱ��Ĳ���
int d[N][N]; 

int n, m;

// ���ѷ��ؽ��
int bfs() {
	// �����ȶ����-1����ʾû������
	memset(d, -1, sizeof d); 
	// ��ͷ����β 
	int hh = 0, tt = -1;
	// ����ʼ��<0,0>���
	q[++ tt] = {0, 0};
	// ��ʼ��ı���������0 
	d[0][0] = 0;
	
	// �ĸ�����
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	// ���в�Ϊ��ʱ��һֱ����
	while (hh <= tt) {
		// ȡ��ͷ�� 
		auto t = q[hh ++];
		// ���������ܵ��ĸ�λ��
		for (int i = 0; i < 4; i ++) {
			// ��λ�õ�x��y
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			// ����ڷ�Χ�ڣ���û����������Ҫ��������¼һ�¾��룬Ȼ�����
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
				d[x][y] = d[t.first][t.second] + 1;
				q[++ tt] = {x, y};
			} 
		} 
	} 
	
	// ��󷵻صľ����ߵ����½ǵľ���
	return d[n - 1][m - 1]; 
} 

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			scanf("%d", &g[i][j]);
	
	printf("%d", bfs());
	
	return 0;
}
