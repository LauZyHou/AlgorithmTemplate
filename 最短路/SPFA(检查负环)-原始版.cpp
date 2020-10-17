#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

/*
https://www.acwing.com/problem/content/854/

dist[j]��¼Դ�㵽j��ĵ�ǰ���·����
cnt[j]��¼������·�ı���

��t�㵽j�㣬��Ȩ��c�������ʱ��
dist[j] = dist[t] + c
cnt[j] = cnt[t] + 1

ֻҪĳ��cnt[j] >= n�����ɳ���ԭ��֪�л�·�ˣ���һ���и���·�� 

ע���ʼʱҪ�����е㶼�ŵ��������Ϊ��Щ�㲻һ������ͨ��
Ҫ�����Ǵ��κ�һ���������û�и��� 
*/

const int N = 2e3 + 10;
const int M = 1e4 + 10;

int n, m;
int h[N], e[M], ne[M], idx, w[M];

void add_edge(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
}

int dist[N], cnt[N];
bool st[N];

// ������û�и��� 
bool spfa() {
	// �жϸ���ʱ���ó�ʼ��dist�ˣ�����0����
	// Ҫ�����еĵ㶼����Ҫ���³��ߵĶ���
	queue<int> q;
	for (int i = 1; i <= n; i ++) {
		q.push(i), st[i] = true;
	}
	
	while (q.size()) {
		int t = q.front();
		q.pop(), st[t] = false;
		
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[t] + w[i] < dist[j]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n)
					return true;
				if (!st[j])
					q.push(j), st[j] = true;
			}
		}
	}
	return false;
}
 

int main() {
	memset(h, -1, sizeof h);
	
	scanf("%d%d", &n, &m);
	while (m --) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a, b, c);
	}
	
	if (spfa())
		puts("Yes");
	else
		puts("No");

	return 0;
}
