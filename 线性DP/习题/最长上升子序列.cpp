#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/897/

// ״̬��ʾ��f[i]
// ���ϣ������Ե�i������β����ֵ������������
// ���ԣ�������ÿ�����������еĳ��ȵ����ֵ
// ״̬���㣺f[i]�������������һ��������i������ǰ��һ������˭������
// ǰ��һ����������a[1]~a[i-1]���е�����a[j]<a[i]���� 
// f[i] = max(f[j] + 1), ����j��Ҫ����j < i && a[j] < a[i] 

const int N = 1010;

int a[N], f[N]; 

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d", a + i);
	
	for (int i = 1; i <= n; i ++) {
		f[i] = 1; // ������ֻ��a[i]һ����ʱ������1
		// ö��ǰһ����������˭
		for (int j = 1; j < i; j ++)
			if (a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
	}
	
	// ��������ÿ�����������ֵ
	int res = 0;
	for (int i = 1; i <= n; i ++)
		res = max(res, f[i]);
	
	printf("%d\n", res);	 
	
	return 0;
}
