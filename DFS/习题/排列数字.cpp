#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/844/
// ��DFS����Ҫ���Ǻ���ʲô����˳��������еķ��� 

const int N = 10;

int path[N]; // DFSʱ·���ϵĽ�
bool st[N]; // ��¼ÿ�������Ƿ��ù�

int n;

// �����±�Ϊu��path[u]���Ե�ֵ 
void dfs(int u) {
	// �ҵ��˽� 
	if (u == n) {
		for (int i = 0; i < n ; i ++)
			printf("%d ", path[i]);
		puts("");
		return ;
	}
	// ���λ�����ÿ�����ܵ�ȡֵ
	for (int i = 1; i <= n; i ++)
		if (!st[i]) { // û�ù� 
			path[u] = i; // ��䵽���λ��
			st[i] = true; // ���ñ�ʹ�ù�
			dfs(u + 1); // ����һ������
			st[i] = false; // �ָ��ֳ���������ֲ��ٱ�ʹ�� 
		}
}

int main() {
	scanf("%d", &n);
	
	dfs(0);
	
	return 0;
} 

