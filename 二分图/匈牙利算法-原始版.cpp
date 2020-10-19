#include <cstring>
#include <iostream>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/927/1/

��Ȼ������ͼ�������������㷨������ֻ�������ÿ���㵽�ұߵ����б�
����ȥ���ұߵĵ㵽��ߵıߣ�����ֻҪ������ҵı߾Ϳ�����	
Ҫ��һ�������¼һ���ұߵĵ����ߵ��ĸ���ƥ����һ�� 
*/

const int N = 510; // �����ڽӱ�h�±�ʱ��ʾ����id������match�����±�ʱ��ʾŮ��id 
const int M = 1e5 + 10;

// �ڽӱ�
int h[N], e[M], ne[M], idx;

// �ڽӱ�ӱ� 
void add_edge(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
} 

// ���ұߵ�Ů��������ĸ�������һ��
int match[N];
// ��ݹ��ж�ʱ��ЩŮ���Ѿ����ǹ��ˣ���ֹ�ڲ�ͬ�Ĳ�ݹ�ͬһ��Ů����
bool st[N];

// �������㷨�ݹ���Һ͸���������ƥ���Ů�����ҵ�ʱ��¼������true 
bool find(int x) {
	// �������г��ߣ�Ҳ���ǿ���ƥ���Ů��
	for (int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		// ������ǹ��˾�����
		if (st[j])
			continue;
		// û���ǹ������ڿ����ܲ��ܺ����Ů��jƥ�� 
		st[j] = true;
		// ������Ů��ûƥ�䣬���ߺ���ƥ������������ҵ��¼� 
		if (!match[j] || find(match[j])) {
			// ��ô�Ͱ����Ů��jƥ�������x
			match[j] = x;
			// �ҵ���
			return true; 
		}
	} 
	// �Ҳ���ƥ��
	return false; 
}

// ��������Ů���������� 
int n1, n2, m;

int main() {
	scanf("%d%d%d", &n1, &n2, &m);
	
	memset(h, -1, sizeof h);
	
	while (m --) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b); // ֻ���������Ů���ľͿ��� 
	}
	
	int ans = 0; // ���ƥ����
	// ���������������1~n1�������ܲ���ƥ��
	for (int i = 1; i <= n1; i ++) {
		// ���ݹ��find����ǰҪ�Ѽ�¼����Ů��û���ǹ�������st��Ϊfalse
		memset(st, false, sizeof st); 
		if (find(i))
			ans ++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
