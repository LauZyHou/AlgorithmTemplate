#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/837/

Trie�����Կ��ٴ�ȡ�ַ������ϣ��ַ����Ͳ���ܶ� 
*/

// ������ַ������ܳ����Ͻ磨�����ַ������������������ֵ�� 
const int N = 1e5 + 10;

// �ַ���ÿ��λ�ÿ�����26��Сд��ĸ��������26���ӽ��
// ����son[i][j]����ǽ�ռ��i����'a'~'z'�ӽ����±�
// ֵ0�ȱ�ʾ�ǿս�㣬Ҳ��ʾTrie���ĸ��ڵ� 
int son[N][26];

// ����ָʾson�����õ����������Ҫʹ�õĽ��ʱ������� 
int idx; // ����ģ��ָ�� 

// cnt[i]��¼��ռ��i����β���ַ��������˶��ٴ�
int cnt[N]; 

// Trie������һ���ַ���
void insert(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i ++) {
		int u = str[i] - 'a';
		// ������ӽ�㲻���ڣ��ͷ���һ�� 
		if (!son[p][u])
			son[p][u] = ++ idx; // ������++����Ϊ0��ʾ�ս��
		// ������ 
		p = son[p][u]; 
	}
	// ����Ҫ��¼�ô���β���ַ�������+1
	cnt[p] ++; 
}

// ��ѯ�ַ�����Trie���г��ֶ��ٴ�
int query(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i ++) {
		int u = str[i] - 'a';
		// ���ĳ��λ�÷��ֺ��ӽ�㲻���� 
		if (!son[p][u])
			return 0; // ��û���������ˣ��ַ����϶�û���ֹ�
		// ������
		p = son[p][u]; 
	}
	// ���귵�ؼ�¼�ĳ��ִ���
	return cnt[p]; 
}

char str[N];
char op[2];

int main() {
	int n;
	scanf("%d", &n);
	
	while (n --) {
		scanf("%s%s", op, str);
		if (op[0] == 'I')
			insert(str);
		else
			printf("%d\n", query(str));
	}
	
	return 0;
}
