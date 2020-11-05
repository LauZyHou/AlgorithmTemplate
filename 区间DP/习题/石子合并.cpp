#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/284/

const int N = 310;

int s[N]; // ǰ׺�� 
int f[N][N]; // f[i][j]��ʾ�ϲ�����[i,j]��ʯ����С���� 

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i ++ )
		scanf("%d", s + i);
	
	for (int i = 1; i <= n; i ++ ) // Ԥ����ǰ׺��
		s[i] += s[i - 1];
	
	// ��С����ö�����䳤�ȣ���Ϊ���䳤����1��ʱ��ϲ�����һ����0�����Դ�2��ʼ 
	for (int len = 2; len <= n; len ++ )
		for (int i = 1; i + len - 1 <= n; i ++ ) {
			int j = i + len - 1; // �����Ҷ˵�
			f[i][j] = 1e8; // ����֮ǰ���һ���Ƚϴ��������������min������
			// ö�ٷֽ��k
			for (int k = i; k <= j - 1; k ++ )
				// �ϲ�[i..k]�ϲ�[k+1..j]���ٺϲ�����������Ĵ��� 
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]); 
		} 
	
	printf("%d\n", f[1][n]);
	 
	return 0;
} 
