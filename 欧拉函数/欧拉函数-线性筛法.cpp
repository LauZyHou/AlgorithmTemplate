#include <iostream>

using namespace std;

/*

���ڶ�����ŷ����������һ������ŷ������
��Щʱ��Ҫ��1~n��������ŷ������
��������û��ڶ�����󷨣���ô��n������ŷ��������ʱ�临�Ӷ���O(n����n) 
���ʱ��Ϳ�����ɸ��ȥ���ˣ�ʱ�临�Ӷ���O(n)
ע������ɸ������˳��������ܶණ�� 
*/

typedef long long LL;

const int N = 1e6 + 10;

// ����ɸ
int primes[N], cnt;
bool st[N];
// ŷ��������
int phi[N]; 

// ����ɸ����1~nÿ������ŷ�������ļӺ�
LL get_eulers(int n) {
	phi[1] = 1;
	for (int i = 2; i <= n; i ++) {
		// ���û��ɸ����������
		if (!st[i]) {
			primes[cnt ++] = i;
			phi[i] = i - 1; // ������ŷ��������������ȥ1 
		}
		// ɸ�����������primes[j] * i������primes[j] <= ��������С������ 
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = true; // ɸ��primes[j] * i
			// ���primes[j]�Ѿ�����С��������
			if (i % primes[j] == 0) {
				phi[primes[j] * i] = phi[i] * primes[j];
				break; // ���� 
			}
			// �����primes[j]�ǻ��ʵĸ�С��һ������ 
			else {
				phi[primes[j] * i] = phi[i] * (primes[j] - 1);
			}
		}
	}
	
	// ���㱾��Ҫ�ģ���1��n��ŷ�������ĺ�
	LL ans = 0;
	for (int i = 1; i <= n; i ++)
		ans += phi[i]; 
	return ans;
} 

int main() {
	int n;
	scanf("%d", &n);
	
	printf("%lld\n", get_eulers(n));
	
	return 0;
}
