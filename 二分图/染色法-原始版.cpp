#include <iostream>
#include <cstring>

using namespace std;

/*
https://www.acwing.com/problem/content/862/

һ��ͼ�Ƕ���ͼ�����ҽ���ͼ�в���������
�����Ⱦɫ������û��ì�ܾ�һ���Ƕ���ͼ 

�㷨���̣�
for (int i = 1; i <= n; i ++)
	if iδȾɫ
		dfs(i, 1); // ��iȾ��1����ɫ���������Ѱ�i���ڵ���ͨ��Ⱦɫһ�� 
*/

const int N = 1e5 + 10;
// ����ͼÿ���ߴ������������Կ�����
const int M = 2e5 + 10;

int n, m;

// �ڽӱ� 
int h[N], e[M], ne[M], idx;

// �ڽӱ�ӱ� 
void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

// ��¼Ⱦɫ�����0ûȾɫ��1Ⱦ����ɫ1��2Ⱦ����ɫ2 
int color[N];

// ����ͨ��Ⱦɫ������Ⱦɫ��������û��ì��
// ��ɫֻ�����֣�1��2
bool dfs(int u, int val) {
	// �������Ⱦɫ
	color[u] = val; 
	// �����б�
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i]; // ��һ�˵ĵ�
		// ���j�Ѿ��к��Լ���ͬ����ɫ��ô�д���
		if (color[j] == val)
			return false;
		// ����������Ⱦ����һ����ɫ�����з�������ҲҪ���ϴ�
		if (!color[j] && !dfs(j, 3 - val))
			return false; 
	}
	return true;
} 

int main() {
	scanf("%d%d", &n, &m);
	
	// �������
	memset(h, -1, sizeof h); 
	
	while (m --) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b), add_edge(b, a);
	}
	
	// Ⱦɫ��
	bool ok = true; // ��¼Ⱦɫʱ�Ƿ���ì�� 
	for (int i = 1; i <= n; i ++) {
		// ���ûȾɫ��
		if (!color[i]) {
			// Ⱦɫ���������ì�ܾͽ���
			if (!dfs(i, 1)) {
				ok = false;
				break;
			}
		} 
	} 
	
	// �鿴��û��ì��
	if (ok)
		puts("Yes");
	else
		puts("No");
	
	return 0;
}
