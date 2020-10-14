#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// https://www.acwing.com/problem/content/description/841/
// ��Ϊ����֮��˳��ͺ�����Ĳ�һ����
// ����Ҫ��¼�����ÿ��Ԫ���ǵڼ�������ģ�������hp
// ҲҪ��¼�ڼ���������Ƕ�����ĸ�Ԫ�أ�������ph

const int N = 1e5 + 10;

int n;

int m; // �ڼ���������� 
int hp[N]; // ���±� -> �ڼ����������
int ph[N]; // �ڼ���������� -> ���±� 

int h[N]; // ������ 
int sz = 0; // �������õ������� 

// ����h[a]��h[b]��ͬʱά��hp��ph 
void heap_swap(int a, int b) {
	swap(h[a], h[b]); // ����ֵ 
	swap(ph[hp[a]], ph[hp[b]]); // ������¼���ڼ�����������Ķ��±� 
	swap(hp[a], hp[b]); // ������¼��������λ�õ����ǵڼ���������� 
}

// ��ǰλ�ñȽϴ�ʱ�����µ����ɶ� 
void down(int u) {
	int t = u;
	if (u * 2 <= sz && h[u * 2] < h[t])
		t = u * 2;
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])
		t = u * 2 + 1;
	if (t != u) {
		heap_swap(t, u);
		down(t);
	}
}

// ��ǰλ�ñȽ�Сʱ�����ϵ����ɶ�
void up(int u) {
	while (u / 2 && h[u / 2] > h[u]) {
		heap_swap(u / 2, u);
		u /= 2;
	}
} 

int main() {
	scanf("%d", &n);
	while (n --) {
		char op[3];
		scanf("%s", op);
		if (!strcmp(op, "I")) { // ���� 
			m ++;
			int x;
			scanf("%d", &x);
			h[++ sz] = x;
			hp[sz] = m;
			ph[m] = sz;
			up(sz);
		}
		else if (!strcmp(op, "PM")) { // �����Сֵ 
			printf("%d\n", h[1]);
		}
		else if (!strcmp(op, "DM")) { // ɾ����Сֵ 
			heap_swap(sz, 1);
			sz --;
			down(1);
		}
		else if (!strcmp(op, "D")) { // ɾ����k��������� 
			int k;
			scanf("%d", &k);
			int x = ph[k]; // �ڶ��е�λ��
			heap_swap(sz, x);
			sz --;
			down(x), up(x); 
		}
		else if (!strcmp(op, "C")) { // �޸ĵ�k��������� 
			int k, v;
			scanf("%d%d", &k, &v);
			int _x = ph[k]; // ��k�������Ԫ�������ڶ��е�λ��
			h[_x] = v;
			down(_x), up(_x); 
		}
	}
	return 0;
}
