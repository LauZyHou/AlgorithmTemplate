#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

// https://www.acwing.com/problem/content/895/
// ÿ��ʯ���ܱ�ȡ�����������һ�������ľ���ͼ
// ����Ѿ���ͼ�����������ֹ״̬��SGֵ��0�����ܰ�ÿ��ͼ���ڵ��SGֵ�����
// Ȼ�����README��������ͼ�������������ͼ�ĳ�ʼ״̬��SGֵ�������ж��� 

const int N = 110; // ʯ�����100��
const int M = 1e4 + 10; // ȡʯ�ӻ���ÿ��ʯ�ӵĸ��������10000 

int s[N]; // ������ÿ������������������Ժ�k��һ����ģ 
int f[M]; // f[x]��x��ʯ�ӳ����Ľ��SG������ֵ�����Ժ�ʯ�ӹ�ģ�й� 


// ������k������ʯ����n�� 
int k, n;

// ���仯������SG������ֵ 
int sg(int x) {
	// �������˾ͷ��أ���֤ÿ��״̬SG����ֻ�ᱻ��һ�� 
	if (f[x] != -1)
		return f[x];
	// ��ϣ���ϴ浱ǰ�����������Ե���ľ����SG����ֵ 
	unordered_set<int> dest_sgs;
	// ���ڼ���s���ÿ����
	for (int i = 0; i < k; i ++) {
		int num = s[i]; // �������������������ȡ�����٣�
		// �����ǰ����x������ȡ����ô����
		if (x >= num) {
			// ���µ�״̬��SGֵ�ӽ���
			dest_sgs.insert(sg(x - num));
		}
	}
	// �����к��״̬�����SG����ֵ����������һ��Mex����
	// ����һ�����ﲻ���ڵ���С����Ȼ���Ƕ��٣����ǵ�ǰ��SGֵ
	for (int v = 0; ; v ++)
		if (!dest_sgs.count(v))
			return f[x] = v;
}


int main() {
	// ���뼯��s��k���� 
	scanf("%d", &k);
	for (int i = 0; i < k; i ++)
		scanf("%d", s + i);

	// ���仯�����������SG������ֵ�����飬û���������-1
	memset(f, -1, sizeof f);
	
	// ����n��ʯ�ӵ�����
	scanf("%d", &n);
	int res = 0; // �𰸣�ÿһ��ʯ���γɵľ���ͼ��SG����ֵ����� 
	// ����ÿһ��ʯ�� 
	for (int i = 0; i < n; i ++) {
		// ����ÿһ��ʯ�ӵĸ��� 
		int x;
		scanf("%d", &x);
		res ^= sg(x);
	}
	
	// ���ݾ���ͼ���SG���������ֵ�ǲ���0֪�����ֱ�ʤ/�ذ� 
	if (res)
		puts("Yes");
	else
		puts("No");
	
	return 0;
}
