#include <iostream>

using namespace std;

/*
https://www.acwing.com/activity/content/problem/content/936/1/

ö�ٵ�����n���������������һ�����ӣ�����������
�����ܻ�ʣ��һ�����ڸ���n��������������� 
*/

// ÿ��ö�٣���ö�ٵ�iʱ������ζ���Ѿ��Ѵ�2��i-1�������������ɾ���
// ������ʱ��i������Ϊn�����ӣ���ôiһ����һ������
void divide(int n)
{
	// n�����ֻ����һ�����ڸ���n������
	// ��������iֻҪ����������n������ 
	for (int i = 2; i <= n / i; i ++)
	{
		if (n % i == 0)
		{
			int s = 0; // i��Ϊ���ӳ��ִ���
			while (n % i == 0)
			{
				n /= i;
				s ++;
			}
			printf("%d %d\n", i, s);
		}
	}
	// ������ж�nʣ�µ�ֵ�ǲ���1������1�����Ǹ�ʣ�µ�Ψһ������
	if (n > 1)
		printf("%d 1\n", n); 
} 

int n;

int main()
{
	scanf("%d", &n);
	while (n --)
	{
		int a;
		scanf("%d", &a);
		divide(a);
		puts("");
	}
	
	return 0;
}
