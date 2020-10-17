#include <iostream>
#include <cstring>

using namespace std;

/*
https://www.acwing.com/problem/content/855/

BF�㷨�ʺ��и�Ȩ�ߵĵ�Դ�����·

�㷨���̣�
for n �� // �������ѭ��k�Σ�����õ��Ǿ���"������k����"�����·
	����dist���飬��֤ÿ��ֻ���ϴθ��µ�dist��������� 
	for ���б� // ÿ����(a,b,w) ��ʾ ��a��b����Ȩ��w
		dist[b] = min(dist[b], _dist[a] + w) // �ɳڲ��� 
��Ϊÿ��ֻҪ���б߶�������������
����BF�㷨�ﲻ���ڽӾ��󡢲����ڽӱ�Ҳ���� 
ֱ�Ӱ����б�(a,b,w)������������
�ṹ�����飬���������ȳ����鶼���Ե� 

����n�ζ����бߵ��ɳڲ�����һ���������µ����ǲ���ʽ��
�����б�(a,b,w)��dist[b] <= dist[a] + w 

ע������и�Ȩ��·����ô���·���ܲ�����
��Ϊ����һֱ�ڸ�Ȩ��·��ԽתԽС
BF�㷨�����������û�и�Ȩ��· 
��Ϊѭ��k�Σ���õ��Ǿ���"������k����"�����·
�����n��ѭ��ʱ��dist���и��£�˵����ʱ���ҵ��˳���Ϊn�����·
����·������n+1���㣬�ɳ���ԭ��֪һ�����ظ��㣬����һ�����и���

BF��Ȼ�����󸺻�������ʱ�临�ӶȱȽϸߣ����Բ���������
BF�������㷨���õľ��ǡ�ѭ��k�Σ���õ��Ǿ���"������k����"�����·��������� 
*/

const int N = 5e2 + 10;
const int M = 1e5 + 10;

int n, m, k;

struct Edge {
	int a, b, w;
}e[M];

int dist[N], backup[N]; // dist�����ı������� 

int bellman_ford() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	// ��Ϊ��೤����k����������ѭ��k�� 
	for (int i = 0; i < k; i ++) {
		// ����dist����
		memcpy(backup, dist, sizeof dist);
		// ��ÿ�������ɳڲ���
		for (int j = 0; j < m; j ++) {
			int a = e[j].a, b = e[j].b, w = e[j].w;
			dist[b] = min(dist[b], backup[a] + w); // ע�������ñ��ݵ�backup[a]ȡ��a�ľ��� 
		} 
	}
	
	// ��Ϊ����Ҳ���ܱ�����+��Ȩ�߸��±�С�����������ô���һ���ϴ�������ж�
	if (dist[n] > 0x3f3f3f3f / 2) 
		return -1;
	return dist[n];
}


int main() {
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 0; i < m; i ++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[i] = {x, y, z};
	}
	
	int ans = bellman_ford();
	
	if (ans == -1)
		puts("impossible");
	else
		printf("%d\n", ans);
	
	return 0;
}
