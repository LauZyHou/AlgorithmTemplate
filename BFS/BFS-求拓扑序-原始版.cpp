#include <iostream>
#include <cstring>

using namespace std;

/*
https://www.acwing.com/problem/content/850/

DAG�������޻�ͼ������������Ҳ������ͼ 
BFS����������DAG���������� 
�����Ϊ0�ĵ㿪ʼ�����
ö�ٶ�ͷԪ�ص����г���t->j��ɾ���������
���Ӱ��j����ȣ���d[j]--
���j�������0�ˣ��Ϳ�������� 
*/

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx; // �ڽӱ�
int d[N]; // ���
int q[N]; // ���� 

int n, m;

void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
	// ά�����
	d[b] ++; 
}

// �������򣬷����������Ƿ���� 
bool toposort() {
	int hh = 0, tt = -1;
	
	// ���������Ϊ0�ĵ����
	for (int i = 1; i <= n; i ++) {
		if (!d[i])
			q[++ tt] = i;
	}
	
	// �����������
	while (hh <= tt) {
		int t = q[hh ++];
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i]; // t -> j 
			// ��ȼ��٣����������ɾ��������
			d[j] --;
			if (!d[j]) // ���ٵ�0ʱ���
				q[++ tt] = j; 
		}
	}
	
	// ���н�㶼����ˣ���ô���Ǵ����������
	return tt == n - 1; 
}

int main() {
	scanf("%d%d", &n, &m);
	
	memset(h, -1, sizeof h);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b);
	}
	
	if (toposort()) {
		// ����ʱ�����е����˳�����������
		for (int i = 0; i < n; i ++)
			printf("%d ", q[i]); 
	}
	else {
		puts("-1");
	}
	
	return 0;
}

