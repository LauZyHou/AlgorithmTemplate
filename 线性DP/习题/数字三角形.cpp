#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/900/

// 状态表示-集合：f[i][j]表示所有从起点走到i,j这个点的集合
// 状态表示-属性：f[i][j]的值表示集合里所有路径的数字和的最大值 
// 状态计算：f[i][j]可以拆成来自左上方的和来自右上方的
// f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j]


const int N = 510;
const int INF = 1e9;

int f[N][N];
int a[N][N];

int main() {
	int n;
	scanf("%d", &n);
	
	// 读入这个数字三角形 
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++)
			scanf("%d", &a[i][j]);

	// 为了处理边界这里都初始化为-INF，不能初始化为0，因为有负的值
	// i可以从1开始，但是j一定要从0开始初始化，因为后面j-1可能取0 
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= i + 1; j ++) // 这里j要到i+1，因为转移时候右上角的点可能不存在，但是要算 
			 f[i][j] = -INF;
	
	f[1][1] = a[1][1];
	for (int i = 2; i <= n; i ++)
		for (int j = 1; j <= i; j ++)
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
			
	int res = -INF;
	for (int j = 1; j <= n; j ++)
		res = max(res, f[n][j]);
	
	printf("%d\n", res);
	
	return 0;
}
