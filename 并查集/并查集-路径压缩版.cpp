#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/description/838/

���鼯
1. ���������Ϻϲ�
2. ѯ������Ԫ���Ƿ���һ�����ϵ���

����ԭ��ÿ��������һ��������ʾ
�����ı�ž������ϼ��ϵı��
ÿ�����洢���ĸ��ڵ�
p[x]��ʾx�ĸ��ڵ�

Q1: ����ж�����
	if (p[x] == x) ��ô������
Q2: �����x�Ľ����
	while (p[x] != x) x = p[x];
Q3: ��κϲ���������
	x��y�ֱ��������ϵĸ���p[x]=y����p[y]=x������ 
*/

const int N = 1e5 + 10;

// ��ÿ��Ԫ�صĸ��ڵ���±� 
int p[N];

// ��ѯx�����ڽ�㣬�����õݹ��д·��ѹ�� 
int find(int x) {
	// ·����ÿ��x�ĸ��׶�ָ������ 
	// ��������find(p[x])����д��find(x)������һֱ���������x������ 
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x]; // ѹ����x�ĸ��׾��������� 
} 

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	// ��ʼ����ÿ������Լ�һ������
	for (int i = 1; i <= n; i ++)
		p[i] = i;
	
	while (m --) {
		char op[2]; // ���� 
		int a, b; // ����Ԫ�� 
		scanf("%s%d%d", op, &a, &b);
		
		if (op[0] == 'M') // �ϲ�
			p[find(a)] = find(b); // a���ڵ����ҵ�b��
		else // ��ѯ
			if (find(a) == find(b))
				puts("Yes");
			else
				puts("No"); 
	}
	
	return 0;
}
