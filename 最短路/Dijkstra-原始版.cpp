#include <iostream>
#include <cstring>
using namespace std;

/*
https://www.acwing.com/problem/content/description/851/

���ذ�Dijkstra��Ǹ�Ȩ��Դ�����·
ʱ�临�Ӷ���O(n^2)���ʺϳ���ͼ������m��n^2���� 
��Ϊ�ǳ���ͼ���������ڽӾ������� 
ע�����·���ⲻ��������ͼ������ͼ�����������ͼ����˫���
����д���·�㷨ֻҪ��������ͼ������ 

0. ����S 
1. dist[1] = 0, dist[i] = +����
2. for i = 1..n
	�ҳ�����S�е�dist[t]��С��t
	��t�Ž�S�У���ȷ����t�ľ������dist[i]
	�����ȵ�t�ٵ�S�еĵ�᲻���С�����¾��� 
*/

const int N = 510;

int g[N][N]; // �ڽӾ���
int dist[N]; // ���Դ�㵽�����ľ���
bool st[N]; // ĳ������û�и��¹������㣨������ĳ���������û�б�ȷ���� 

int n, m;


// ����Dijkstra�������· 
int dijkstra() {
	// ��ʼ��dist����
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; // Դ�㵽Դ�����
	// ע�⣬���ﲻ��дst[1]=true����Ϊ1��û���������¹������� 
	
	// ��ѭ��n-1�Σ�ÿ�ζ���ȷ����һ����ľ��룬���һ����һ���Ѿ�ȷ���� 
	for (int i = 0; i < n - 1; i ++) {
		// ��ʹ��dist[t]��Сδȷ�������t��
		int t = -1; // -1��ʾt��û����ֵ�� 
		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		// ������Դ���ȵ�t�ٴ�t��������������е����
		// ʵ����ֻ����δȷ������Щ�㣬�������ﲻ�ж�δȷ��Ҳ��
		// ��Ϊ�Ѿ�ȷ�����Լ�û���ٱ�С��
		for (int j = 1; j <= n; j ++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		// ��������ľ��뱻ȷ����
		st[t] = true; 
	} 
	
	// ����Ҫ����ǵ�n�ŵ�ģ������n�ŵ�ľ���û���¹���˵��n�ŵ��1�ŵ��ǲ���ͨ��	
	// memset���ÿ���ֽڶ�д��0x3f��dist[n]��int�ͱ���������4���ֽڣ�����һ��Ҫд��0x3f3f3f3f
	if (dist[n] == 0x3f3f3f3f)
		return -1;
	return dist[n];
}



int main() {
	scanf("%d%d", &n, &m);
	
	// �ڽӾ����� 
	memset(g, 0x3f, sizeof g);
	while (m --) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c); // a->bֱ�Ӿ�����c
		g[a][b] = min(g[a][b], c); // ��Ϊ���رߣ�����Ҫȡ�ر�����С�� 
	}
	// ÿ���㵽�Լ��ľ�����0
	for (int i = 1; i <= n; i ++) 
		g[i][i] = 0;

	printf("%d", dijkstra()); 
	
	return 0;
} 
