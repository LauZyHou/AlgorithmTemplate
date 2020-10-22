#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/5/ 

// ��������Ʒ�� = log(S) * 1000����Ʒ 
const int N = 12010;
// �����2000 
const int M = 2010;

// �������Ʒ������ͼ�ֵȨ�� 
int v[N], w[N];

// һά�����dp���� 
int f[M];


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	// n����Ʒ��� 
	int cnt = 0; // �������Ʒ��
	for (int i = 1; i <= n; i ++) {
		int a, b, s; // ��i����Ʒ���������ֵ������ 
		scanf("%d%d%d", &a, &b, &s);
		// ������s��������Ʒ���
		int k = 1; // �����Ʊ���
		while (k <= s) {
			cnt ++;
			v[cnt] = a * k;
			w[cnt] = b * k;
			// ��¼����������ƷȻ��ʹ�s��ȥ����Ȼ����k 
			s -= k;
			k <<= 1;
		}
		// ������sû���꣬ʣ�µ���s�������һ��
		if (s > 0) {
			cnt ++;
			v[cnt] = a * s;
			w[cnt] = b * s;
		} 
	}
	
	// ���������Ƕ���cnt����Ʒ��01����
	n = cnt;
	for (int i = 1; i <= n; i ++)
		for (int j = m; j >= v[i]; j --)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
			
	printf("%d\n", f[m]);
	
	return 0;
}
