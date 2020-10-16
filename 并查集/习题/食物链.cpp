#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/description/242/
// ʹ����Ҫʹ��ά��������Ϣ�Ĳ��鼯 
// ά�����鼯����ÿ����㵽���ڵ�ľ���
// ������·��ѹ��ʱ���֪��ÿ����㵽���ڵ�ľ���
// �����������%3��ֵ���ж�������һ�� 

const int N = 5e4 + 10;

// ÿ��Ԫ�ظ�����±� 
int p[N];

// ÿ��Ԫ�ص����鼯�ļ������ϸ��ڵ�ľ���
// �Լ����Լ��ľ������0 
int d[N];

// ����x�ĸ��ڵ� + ·��ѹ�� + ά�������ڵ�ľ��� 
int find(int x) {
	// ����������ĸ� 
	if (p[x] != x) {
		// ά��d[x] = ��d[x] + d[��p[x]]
		// ��p[x]��find���̼Ȳ��ı�d[x]Ҳ���ı�p[x]��ֵ
		// ���Ǹ�ֵ�ͻ�ı�p[x]��ֵ�ˣ������ȼ�¼һ��
		int px = p[x]; 
		p[x] = find(px);
		d[x] += d[px];
	}
	return p[x];
} 


int n, k;
int ans = 0; // �ٻ�����

int main() {
	scanf("%d%d", &n, &k);
	
	// ��ʼ����ÿ���ڵ���һ��������
	for (int i = 1; i <= n; i ++)
		p[i] = i; 
	
	while (k --) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (x > n || y > n) { // ������Χ 
			ans ++;
			continue;
		}
		int fx = find(x);
		int fy = find(y);
		if (op == 1) { // x��y��ͬһ�� 
			// ���������ͬһ�����ϣ�ͬһ�������ϣ��Ϳ��Ը��ݾ����ж��ǲ���ͬһ��
			// ǰ�������find֮�����ǾͶ����ڸ��ڵ�����
			// ��������d[x]��d[y]���ǵ����ڵ�ľ���
			// ���ģ3��һ���Ͳ���ͬһ�࣬�Ǽٻ� 
			if (fx == fy && (d[x] - d[y]) % 3)
				ans ++;
			// �������ͬһ�������ϣ�Ҫ�ϲ���һ�� 
			// ��fx�ҵ�fy�ϣ���֤(d[fx]+d[x])%3 = d[y]%3
			else if (fx != fy) {
				p[fx] = fy;
				d[fx] = d[y] - d[x];
			}
		}
		else { // x��y 
			// �����ͬһ�����ϣ�ͬһ�������ϣ�����ݾ����ж�
			// ���x��y��Ӧ����x�����ڵ����%3��y�����ڵ����%3��1 
			if (fx == fy && (d[x] - d[y] - 1) % 3)
				ans ++;
			// �������ͬһ�������ϣ�Ҫ�ϲ���һ��
			// ��fx�ҵ�fy�ϣ���֤(d[x]+d[fx])%3 = d[y]%3 + 1
			else if (fx != fy) {
				p[fx] = fy;
				d[fx] = d[y] + 1 - d[x];
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
} 
