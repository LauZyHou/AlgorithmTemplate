#include <iostream>
using namespace std;

/*
��ά���
����һ������a���ҵ�һ������b��ʹ��a��b��ǰ׺�;���
��b[i][j]�������Ͻǵ��Ӿ�������Ԫ�ؼ�����=a[i][j]

��ά��ֿ������ڸ�a�е�һ���Ӿ������Ͻ�(x1,y1)�����½�(x2,y2)����ȫ��Ԫ�ؼ���c 
�����b������ĳ��λ��b[i][j]+=c�����൱����ǰ׺�;���a�У����λ�ÿ�ʼ���½ǵ�����λ�ö�������c
��������Ӿ������Ͻ�(x1,y1)�����½�(x2,y2)����ֻҪ��
b[x1][y1] += c
b[x2+1][y1] -= c
b[x1][y2+1] -= c
b[x2+1][y2+1] += c

��ʼ������a�����b����ȫ����0
Ȼ�����ֵa[i][j]=val�󣬾�ֻҪ�����Ͻ�(i,j)���½�(i,j)����Ӿ������val 
��������ͳһ����������˼��b��ô���� 
*/

const int N = 1e3 + 10;

int n, m, q;
int a[N][N], b[N][N];

void add(int x1, int y1, int x2, int y2, int c) {
	b[x1][y1] += c;
	b[x2+1][y1] -= c;
	b[x1][y2+1] -= c;
	b[x2+1][y2+1] += c;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			add(i, j, i, j, a[i][j]);
		
	int x1, y1, x2, y2, c;	
	while (q--) {
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
		add(x1, y1, x2, y2, c);
	}
	
	// ��b��������ǰ׺�����飬���ɻ�ԭ��a 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%d ", b[i][j]);
		puts("");
	}
	
	return 0;
}
