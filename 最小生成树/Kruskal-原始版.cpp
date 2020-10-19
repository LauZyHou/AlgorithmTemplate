#include <iostream>
#include <algorithm>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/925/1/

���裺 
1. �����б߰���Ȩ�ش�С��������O(mlogm)
   // ��һ����Kruskal�㷨��ƿ�������������㷨�ĳ�����С������Kruskal�ܿ�
2. ö��ÿ���ߣ�a-b��Ȩ����c��O(m) 
   if ��ǰa��b����ͨ then �������߼��뵽����������a��bҲ��ͨ�� 
   // ��һ������������ͨ�Ĳ��鼯������Ҳ����ά��������Ϣ 

ֻҪ��ÿ����ֱ�Ӵ����������ˣ������ڽӱ���ڽӾ��� 
һ����ϡ��ͼ�����Kruskal�㷨 
*/

const int M = 2e5 + 10;

int p[M]; // ���鼯

// �� 
struct Edge {
	int a, b, w;
	bool operator< (const Edge &e)const {
		return w < e.w;
	}
}edges[M];

// ���鼯���� + ·��ѹ��
int find(int x) {
	if (p[x] != x) { // �Լ����и���������� 
		p[x] = find(p[x]); // ·��ѹ�� 
	}
	return p[x];
} 

int n, m; 

int main() {
	scanf("%d%d", &n, &m);
	
	// �������б� 
	for (int i = 0; i < m; i ++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = {a, b, w};
	}
	
	// ��Ȩ�ش�С�������� 
	sort(edges, edges + m);
	
	// ��ʼ�����鼯
	for (int i = 1; i <= n; i ++)
		p[i] = i; 
	
	int ans = 0, cnt = 0;
	
	// �������еı� 
	for (int i = 0; i < m; i ++) {
		// ������
		int a = edges[i].a;
		int b = edges[i].b;
		int w = edges[i].w;
		// ���鼯��������
		a = find(a);
		b = find(b);
		// ����ͬһ����ͨ�鼯����
		if (a != b) {
			p[a] = b; // ��һ��
			ans += w; // ��¼�𰸣��߳���
			cnt ++; // �Ѿ������˶��ٱ� 
		} 
	} 
	
	// ������õ��Ĳ���n-1���ߣ�˵������ͨ
	if (cnt < n - 1)
		puts("impossible");
	else
		printf("%d\n", ans); 
	
	return 0;
} 
