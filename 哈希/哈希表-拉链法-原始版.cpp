#include <iostream>
#include <cstring>

using namespace std;

/*
https://www.acwing.com/problem/content/842/

��ϣ���ϴ�Ŀռ������ӳ�䵽һ��С��Χ��
���������ڷ�����ͻʱֱ�Ӽӵ����λ���������������� 
*/

// ��ϣ���ȣ�ѡ������������������2����Զ���ܼ��ٳ�ͻ 
const int N = 100003;

// ��ϣ�� 
int h[N];

// ����Ľ��������� 
int e[N];

// �����next���ָ��
int ne[N];

// ����Ľ������±�
int idx; 

// ��ϣ��������
void insert(int x) { 
	// ��ϣ�������ֵ 
	int k = (x % N + N) % N;
	// ����������
	e[idx] = x;
	// ͷ�嵽��ϣ���kλ�������� 
	ne[idx] = h[k]; 
	h[k] = idx;
	// �����±������
	idx ++; 
}

// ��ϣ��Ĳ��Ҳ���
bool find(int x) {
	// �������������ֱ��ȥ��Ӧ����������
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == x)
			return true;
	return false; 
} 

int n;

int main() {
	scanf("%d", &n);
	
	// ��ʼ��������ϣ������-1�������������ǿյ�
	memset(h, -1, sizeof h); 
	
	while (n --) {
		char op[2];
		int x;
		scanf("%s%d", op, &x);
		
		if (op[0] == 'I') // ����
			insert(x);
		else { // ���� 
			if (find(x))
				puts("Yes");
			else
				puts("No");
		} 
	}
	
	return 0;
}
