#include <iostream>
using namespace std;

// https://www.acwing.com/activity/content/problem/content/886/1/
// Ҫ�и���������ά�����鼯��ÿ�����ϵ�Ԫ������ 

const int N = 1e5 + 10;

int p[N]; // ÿ�����Ĵ������index

int sz[N]; // ÿ�����ϵĴ�С��ֻ�Դ����������� 

// ��ѯ���ڼ��� + ·��ѹ��
int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
} 

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	// ��ʼ����ÿ��������Լ���һ��������
	for (int i = 1; i <= n; i ++)
		p[i] = i, sz[i] = 1;
	
	// m�β�ѯ
	while (m --) {
		char op[3]; // ����
		int a, b; // Ҫ�������������
		scanf("%s", op);
		
		if (op[0] == 'C') { // �� 
			scanf("%d%d", &a, &b);
			int fa = find(a);
			int fb = find(b);
			if (fa == fb)
				continue;
			sz[fa] += sz[fb];
			p[fb] = fa;
		}
		else if (op[1] == '1') { // �� �Ƿ���ͬһ�������� 
			scanf("%d%d", &a, &b);
			if (find(a) == find(b))
				puts("Yes");
			else
				puts("No");
		}
		else { // �� ĳ��������ڵ���ͼ��Ԫ�ظ���
			scanf("%d", &a); 
			printf("%d\n", sz[find(a)]);
		}
	}
	
	return 0;
}
