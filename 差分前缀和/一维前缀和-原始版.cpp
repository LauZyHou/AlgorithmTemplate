#include <iostream>
using namespace std;

/*
һάǰ׺��
s[i] = a[1]+...+a[i]
��
s[i] = s[i-1]+a[i]�����±��1��ʼ������ֻҪ����s[0]=0�����㴦��߽� 

���Կ��ٲ�ѯһ������ĺͣ�����[l, r]����ĺ�
ֻ��Ҫs[r]-s[l-1]���� 
*/

const int N = 1e5 + 10;

int n, m;
int a[N], s[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i]; 
	}
	
	int l, r;
	while (m--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	
	return 0;
} 
