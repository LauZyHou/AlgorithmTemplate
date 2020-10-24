#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/904/

// 状态表示：f[i,j]
// 集合：所有将a[1..i]变成b[1..j]的操作方式
// 属性：集合里所有操作方式步数的最小值
// 状态计算（集合划分）：依据最后一步对a[i]的操作来划分
// 将a[i]删除后使得a和b[1..j]相等，则此前要将a[1..i-1]变成b[1..j]
// 在a[i]后插入一个（和b[j]一样的）数使得a和b[1..j]相等，则此前要将a[1..i]变成b[1..j-1]
// 把a的第i个数修改（改成和b[j]一样的）后使得a和b[1..j]相等，则此前要将a[1..i-1]变成b[1..j-1]
// 最后这个修改的操作要比较一下a[i]和b[j]是不是已经相等了，如果已经相等了，就不用做这步骤（就不用+1） 

const int N = 1010;

char a[N], b[N];

int f[N][N];


int main() {
	int n, m;
	scanf("%d%s", &n, a + 1);
	scanf("%d%s", &m, b + 1);
	
	// 初始化两个维度是0的情况
	// 把0个字母变成j个字母，插入j次
	for (int j = 0; j <= m; j ++)
		f[0][j] = j; 
	// 把i个字母变成0个字母，删除i次 
	for (int i = 0; i <= n; i ++)
		f[i][0] = i;
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			// 删除和插入操作 
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			// 修改操作 
			if (a[i] == b[j])
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			else
				f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}
	}
	
	printf("%d\n", f[n][m]);
	
	return 0;
}
