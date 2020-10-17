#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

/*
https://www.acwing.com/problem/content/852/

���Ż���Dijkstra��Ǹ�Ȩ��Դ�����·
ʱ�临�Ӷ���O(mlogn)���ʺ�ϡ��ͼ������m�ǲ���n^2�ļ��� 
��Ϊ��ϡ��ͼ���������ڽӱ�����
ע�����·���ⲻ��������ͼ������ͼ�����������ͼ����˫���
����д���·�㷨ֻҪ��������ͼ������ 

0. ����S 
1. dist[1] = 0, dist[i] = +����
2. for i = 1..n
	�ҳ�����S�е�dist[t]��С��t
	��t�Ž�S�У���ȷ����t�ľ������dist[i]
	�����ȵ�t�ٵ�S�еĵ�᲻���С�����¾��루��һ�����ڽӱ���ÿ��ֻҪ�Ҵ�t�����ıߣ� 

��(2.)ѭ�����������������ѭ���������ǵ�ʱ�临�Ӷȷֱ���
n-1������С��O(n^2)
n-1��ȷ�����룺O(n)
n-1�θ��¾��룺O(m)
������С�ĳ��ö���ʵ��
	ÿ��ֻҪO(1)������n-1������С��O(n^2)
�ڸ��¾���ʱ����Ϊ����Ҳ���ˣ�����Ҫ�޸Ķ�������Ԫ��
	ÿ��ҪO(logn)������n-1�θ��¾��룺O(mlogn)

STL�ĶѲ�֧���޸�����Ԫ�أ������STL�Ķѿ���������ķ�ʽ
��ÿ������в����µ�Ԫ�أ��͵����޸�Ԫ���ˣ��������������m��Ԫ��
����m�εĸ��¾��룬ʱ�临�Ӷȱ����O(mlogm)
������Ϊm<n^2������mlogm<mlog(n^2)=2mlogn������O(mlogm)��O(mlogn)��һ������� 
*/

const int N = 2e5;

int n, m;

int h[N], e[N], ne[N], idx; // �ڽӱ�
int w[N]; // �ڽӱ����Ȩ

// �ڽӱ�ӱ�a->b����ȨΪc
void add_edge(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c; // ע�����ñ�Ȩ 
	ne[idx] = h[a];
	h[a] = idx ++;
}

typedef pair<int, int> PII;

int dist[N]; // �浽ÿ����ľ��� 
bool st[N]; // ���������û�����ڸ��������� 

// �����Ż���Dijkstra�㷨���1����n�����·
int dijkstra() {
	// ��ʼ������
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; // Դ��
	
	// �ö�����ÿ��dist����С
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1}); // <����,����>
	
	while (heap.size()) {
		// ÿ��ȡ�Ѷ�Ԫ�� 
		auto t = heap.top();
		heap.pop();
		
		// ȡ�������������
		int distance = t.first;
		int vertex = t.second;
		
		// �����������¹��������ˣ�����һ������ȡ
		if (st[vertex])
			continue;
		
		// ���ˣ�Ҫ��vertex�����������㣬��vertex�ľ������distanceȷ����
		st[vertex] = true; // ��¼��������������
		// ������vertex���������бߣ�������
		for (int i = h[vertex]; i != -1; i = ne[i]) {
			// dest����j 
			int j = e[i];
			// ����ȵ�vertex�ٴ�vertex��j�����Ȩ�ؾ���w[i]����С
			if (distance + w[i] < dist[j]) {
				dist[j] = distance + w[i]; // �͸��¾���
				heap.push({dist[j], j}); // ��Ϊ�����˾��룬����ֱ�Ӳ�һ���µ���� 
			} 
		} 
	}
	
	// �����1�͵�n��ͨ����dist[n]�����¹�������֮
	if (dist[n] == 0x3f3f3f3f)
		return -1;
	return dist[n]; 
} 


int main() {
	scanf("%d%d", &n, &m);
	
	// ��ʼ���ڽӱ�
	memset(h, -1, sizeof h); 
	
	while (m --) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add_edge(x, y, z);
	}
	
	printf("%d", dijkstra());
	
	return 0;
}
