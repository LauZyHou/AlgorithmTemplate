#include <iostream>
#include <cstring>

using namespace std;

// https://www.acwing.com/problem/content/848/
// �������� 

const int N = 1e5 + 10; // �������ֵ

const int M = 2 * N; // �������ֵ�����������ϣ����Ժ�N��һ����ģ������Ҫ���������� 


int h[N]; // �ڽӱ�

int e[M]; // ��������
int ne[M]; // ����next
int idx; // ���������  
 

// ���ڽӱ�����ӱ�a->b 
void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++; 
}

// ��¼�����������
bool st[N]; 

int n; // ������� 

int ans = N; // �������С���ֵ 


// �ӽ��u���ѣ�ȥ��������󣬸�����ͨͼ�н�������ֵ
// ����ֵ����u��ʼ���������ж��ٽ�㣬�������ϲ�ĵ��÷����Լ��� 
int dfs(int u) {
	st[u] = true; // ���ʹ��� 
	
	int sum = 1; // u�Լ�����һ��
	int nowans = 0; // ��¼������ͨͼ�н�������ֵ 
	
	// �������еıߣ�i���������� 
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i]; // ȡ��������������
		if (!st[j]) {
			int s = dfs(j);
			sum += s;
			nowans = max(nowans, s);
		}
	}
	
	// ��Ҫ��ȥ���Լ����������ͨͼ�ȴ�С
	nowans = max(nowans, n - sum);
	
	// ����ȫ�ֵ������С���ֵ 
	ans = min(ans, nowans);
	
	return sum; 
} 



int main() {
	memset(h, -1, sizeof h);
	
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i ++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b);
		add_edge(b, a);
	}
	
	dfs(1);
	
	printf("%d", ans);
	
	return 0;
}
