#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/3/

const int N = 1010;

int v[N], w[N];
int f[N]; // �ڹ�ʽ�Ż��Ļ�����ֱ��ȥ����һά�Ϳ����� 

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", v + i, w + i);
	
	for (int i = 1; i <= n; i ++)
		for (int j = v[i]; j <= m; j ++) // 01���������ǴӴ�С����ȫ�����Ǵ�С���󣬱��û���� 
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	
	printf("%d\n", f[m]);
	
	return 0;
}
