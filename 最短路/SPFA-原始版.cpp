#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

/*
https://www.acwing.com/problem/content/853/

SPFA���ÿ��ѵ�˼���Bellman-Ford�㷨�����Ż�
��ΪBellman-Ford�㷨�е� dist[b] = min(dist[b], _dist[a] + w)
��һ��ÿ�ζ���ִ��
����dist[a]��Сʱ��dist[a]+w�Ż��С����ôdist[b]�ſ��ܱ�����
������һ��û���£���һ��Ҳ������£�������һ����������¼��һ�ָ��µĵ�

��һ������queue��ά�����б�С�˵Ľ�㣬ֻ�����ĳ�����Ҫ����
�������̣�
�Ƚ�Դ��1���queue
while queue����
	ȡ����ͷ���t
	����t�����г��ߣ���t��b��������w��
	����������ȷʵ�����ˣ���b��ӣ���Ϊdist[b]��С�ˣ�������һ�ִ�b������Ҫ�����£� 

ʱ�临�Ӷ� һ��O(m)���O(nm) �����ݽṹ���ڽӱ�����ڽӾ��� 
*/

const int N = 1e5 + 10;

int n, m;

// �ڽӱ�
int h[N], e[N], ne[N], idx, w[N];

// ��ӱ�
void add_edge(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
} 

bool st[N]; // ��ĳ������û���ڶ������ֹ�ظ���� 

int dist[N];

// spfa���1�ŵ㵽n�ŵ�����· 
int spfa() {
	// ��ʼ��dist
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	// ���д�Ҫ��������������ĵ�
	queue<int> q;
	q.push(1); // Դ��
	st[1] = true;

	while (q.size()) {
		int t = q.front();
		q.pop();
		st[t] = false;
		
		// ������t���������б�
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[t] + w[i] < dist[j]) {
				dist[j] = dist[t] + w[i];
				if (!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}		
	}
	
	if (dist[n] == 0x3f3f3f3f)
		return -1;
	return dist[n];
}

int main() {
	scanf("%d%d", &n, &m);
	
	// ����ڽӱ�
	memset(h, -1, sizeof h);
	
	while (m --) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add_edge(x, y, z);
	}
	
	int t = spfa();
	if (t == -1)
		puts("impossible");
	else
		printf("%d", t);
	
	return 0;
}
