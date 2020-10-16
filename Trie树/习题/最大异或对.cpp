#include <iostream>

using namespace std;


const int N = 1e5 + 10;

// Trie���ӣ�N���� * ÿ����31λ�Ƿ���λ 
int son[N * 31][2];

// ��㴦�����֣���������Բ��ã���Ϊ�ȳ��� 
bool use[N * 31]; 

// ����Trie��㣬0��ʾ�ս�㣬Ҳ��ʾ�� 
int idx;

// ��Trie�������һ����������
void insert(int x) {
	int p = 0;
	for (int k = 30; k >= 0; k --) {
		// ������ĸ�λ 
		int i = (x >> k) & 1;
		// û�н��ʹ��� 
		if (!son[p][i]) {
			son[p][i] = ++ idx;
		}
		p = son[p][i];
	}
	// ��¼��������Ǵ��ڵģ���������Բ��ã� 
	use[p] = true;
}

int v[N];

int ans = 0;

// ������x��ƥ���ֵ 
void check(int x) {
	int nowans = 0;
	int p = 0;
	for (int k = 30; k >= 0; k --) {
		// ������ĸ�λ
		int i = (x >> k) & 1;
		// 1��0��0��1�������ҵĸ�λ 
		// ������õģ�û����ȥ���Ժ��Լ���ͬ�� 
		if (son[p][1 - i]) {
			p = son[p][1 - i];
			// ������һλ��1 
			nowans = (nowans << 1) + 1; 
		}
		else if (son[p][i]) {
			p = son[p][i];
			// ������һλ��0
			nowans = nowans << 1; 
		}
		else // ��·���ߣ��������ﲻ���ܣ� 
			return ;
	}
	// 31λ�����꣬����ans���������ﵽ����use[p]һ����true��
	if (use[p] && nowans > ans) 
		ans = nowans; 
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &v[i]);
		insert(v[i]);
		// �ڲ�������о��ܼ��
		check(v[i]); 
	}
	
	printf("%d\n", ans);
	
	return 0;
} 
