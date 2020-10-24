#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/900/

// ״̬��ʾ-���ϣ�f[i][j]��ʾ���д�����ߵ�i,j�����ļ���
// ״̬��ʾ-���ԣ�f[i][j]��ֵ��ʾ����������·�������ֺ͵����ֵ 
// ״̬���㣺f[i][j]���Բ���������Ϸ��ĺ��������Ϸ���
// f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j]


const int N = 510;
const int INF = 1e9;

int f[N][N];
int a[N][N];

int main() {
	int n;
	scanf("%d", &n);
	
	// ����������������� 
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++)
			scanf("%d", &a[i][j]);

	// Ϊ�˴���߽����ﶼ��ʼ��Ϊ-INF�����ܳ�ʼ��Ϊ0����Ϊ�и���ֵ
	// i���Դ�1��ʼ������jһ��Ҫ��0��ʼ��ʼ������Ϊ����j-1����ȡ0 
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= i + 1; j ++) // ����jҪ��i+1����Ϊת��ʱ�����Ͻǵĵ���ܲ����ڣ�����Ҫ�� 
			 f[i][j] = -INF;
	
	f[1][1] = a[1][1];
	for (int i = 2; i <= n; i ++)
		for (int j = 1; j <= i; j ++)
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
			
	int res = -INF;
	for (int j = 1; j <= n; j ++)
		res = max(res, f[n][j]);
	
	printf("%d\n", res);
	
	return 0;
}
