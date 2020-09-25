#include <iostream>
using namespace std;

/*
��άǰ׺��
s[i][j] = a[1][1]+...+a[1][j]
         +a[2][1]+...+a[2][j]
         +...
         +a[i][1]+...+a[i][j]
��
s[i][j] = s[i-1][j]+s[i][j-1]+s[i-1][j-1]+a[i][j] 
���Կ��ٲ�ѯһ���Ӿ������Ͻ�(x1,y1)�����½�(x2,y2)���ڲ��ĺ�
ֻҪs[x2][y2]-x[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]���� 
*/

const int N = 1e3 + 10;

int n, m, q;
int a[N][N], s[N][N];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
			
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
	
	int x1, y1, x2, y2;
	while (q--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]);
	}
	
	return 0;
}
