#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], idx; // �ڽӱ����� 
int d[N]; // ��1�ŵ���չ�ľ���
int q[N]; // ���У������Ľ�� 

// ��ӱ� 
void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

// BFS������1�ŵ㵽n�ŵ����̾���
int bfs() {
	int hh = 0, tt = -1; // ��ͷ��β
	q[++ tt] = 1; // ���1�ŵ�
	
	memset(d, -1, sizeof d); // ���붼��ʼ��Ϊ-1 
	d[1] = 0; // 1�ŵ㵽�Լ�������0
	
	while (hh <= tt) {
		int v = q[hh ++]; // ����һ����
		// �������г���
		for (int i = h[v]; i != -1; i = ne[i]) {
			// ����Ľ��
			int j = e[i];
			if (d[j] == -1) { // û���ʹ� 
				d[j] = d[v] + 1; // �������
				q[++ tt] = j; // ��� 
			} 
		} 
	}
	
	return d[n];
} 


int main() {
	scanf("%d%d", &n, &m);
	
	// ����ڽӱ� 
	memset(h, -1, sizeof h);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b);
	}
	
	printf("%d", bfs());
	
	return 0;
}
