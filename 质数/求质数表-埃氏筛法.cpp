#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/870/

�Ȱ�Ҫ��ķ�Χ2~n��д����
��С�����ÿ�����ı�����ɾ��
���ʣ�µľ��������Χ�ڵ������� 
��ÿ��ö�ٵ�һ����ʱ�������û����ǰ��Ĺ����б�ɸ�������������� 
�Ż�������Ҫ��ÿ�����ı�����ɸһ�飬ֻ��Ҫ�������ı�����ɸһ�� 
�Ż�ǰ��ʱ�临�Ӷ���O(nlogn)���Ż�����O(nloglogn) 
*/

const int N = 1e6 + 10;

int cnt; // ��������
int primes[N]; // ��õ���������
bool st[N]; // st[i]��ʾi��û�б�ɸ��

void get_primes(int n)
{
	for (int i = 2; i <= n; i ++)
	{
		if (!st[i]) // û��ɸ�� 
		{
			primes[cnt ++] = i;
			// ɸ�������б���
			for (int j = i + i; j <= n; j += i)
				st[j] = true; 
		}
	}
} 


int main()
{
	int n;
	scanf("%d", &n);
	
	get_primes(n);
	printf("%d\n", cnt);

	return 0;
}
