#include <iostream>
#include <vector>

using namespace std;

/*
https://www.acwing.com/problem/content/890/

�߾�����������Ȱ�2-a֮������ɸ����
Ȼ���������ֽ�����������¼���ִ��������߾��ȳ����� 
*/

const int N = 5010;

// ����ɸ 
int primes[N], cnt;
bool st[N];

void get_primes(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i])
			primes[cnt ++] = i;
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0)
				break;
		}
	}
}

// ����n!��p���ִ���
int get(int n, int p) {
	int res = 0;
	while (n) {
		res += n / p;
		n /= p; 
	}
	return res;
}

// �߾��ȳ˷�
vector<int> mul(vector<int> &a, int b) {
	vector<int> c; // ���
	int t = 0; // ��λ
	// �ӵ�λ����λ���γ˹�ȥ 
	for (int i = 0; i < a.size(); i ++) {
		t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	// �����ʣ�Ľ�λ���ӵ�ĩβ����λ�ϣ� 
	while (t) {
		c.push_back(t % 10);
		t /= 10;
	}
	return c;
} 

// ÿ���������ֶ��ٴ� 
int sum[N];

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	
	get_primes(a);
	
	// ͳ��C_a^b��ÿ���������ִ���
	for (int i = 0; i < cnt; i ++) {
		int p = primes[i]; // ��ǰ����
		sum[i] = get(a, p) - get(b, p) - get(a - b, p);
	}
	
	// �߾��ȳ˷��ѽ���˳���
	vector<int> res;
	res.push_back(1); // ��1��ʼ��
	
	// ÿ������primes[i]��Ҫ��sum[i]��
	for (int i = 0; i < cnt; i ++)
		for (int j = 0; j < sum[i]; j ++)
			res = mul(res, primes[i]);
	
	// �Ӹ�λ����λ������
	for (int i = res.size() - 1; i >= 0; i --)
		printf("%d", res[i]);
	puts("");
	 
	return 0;
}
