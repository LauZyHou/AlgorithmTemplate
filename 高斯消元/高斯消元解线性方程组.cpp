#include <iostream>
#include <cmath>

using namespace std;

// https://www.acwing.com/problem/content/885/

const int N = 110;
const double eps = 1e-6; // 小于0的判定阈值

int n;
double a[N][N]; // 增广矩阵

// 高斯消元将n行n+1列的增广矩阵的左边n*n的系数矩阵部分尝试变成单位矩阵
// 返回值：0表示无解，1表示有唯一解，2表示有无穷多解 
int gauss() {
	// 当前处理的列号，当前处理的行号（小于r的行全都处理完了，应当固定） 
	int c, r;
	// 枚举系数部分的每一列
	for (c = 0, r = 0; c < n; c ++) {
		// 从r行往下找该列的绝对值最大的一行t
		int t = r;
		for (int i = r; i < n; i ++)
			if (fabs(a[i][c]) > fabs(a[t][c]))
				t = i;
		// 如果绝对值最大的列这个值都是0，那么就说明这一列全是0，不用处理了
		if (fabs(a[t][c]) < eps)
			continue; // 去下一轮看下一列去
		// 把这一行t交换到最上面（第r行）去
		for (int j = 0; j < n + 1; j ++)
			swap(a[t][j], a[r][j]);
		// 对该行（换完是r行）用乘法变换，将该行第一个数（指c列的数）变成1
		// 这里从后往前变，防止a[r][c]先变成1了
		for (int j = n; j >= c; j --)
			a[r][j] /= a[r][c];
		// 除了这一行（r），将下面所有行的第c列都消成0
		// 因为a[r][c]已经是1了，所以只要第i行每个数减去第r行相应的数乘以a[i][c]就行了 
		for (int i = r + 1; i < n; i ++)
			if (fabs(a[i][c])) // 非0才消
				for (int j = n; j >= c; j --) // 从后往前，都是减去a[i][c]
					a[i][j] -= a[r][j] * a[i][c];
		// 操作完一行，行数+1，接下来如果操作也总是操作从r开始的行
		r ++; 
	}
	// 如果r没有达到n，说明底下从r开始的行系数都是0，没有唯一解 
	if (r < n) {
		// 因为r开始的行系数都是0，所以右边必须是0，如果不是0就无解
		for (int i = r; i < n; i ++)
			if (fabs(a[i][n]) > eps)
				return 0;
		// 否则就都是0=0的式子，有无穷解
		return 2; 
	}
	// 至此，一定是完美的阶梯矩阵，有唯一解
	// 从后往前遍历每一行
	for (int i = n - 1; i >= 0; i --) {
		// 对于i行，把它下面的i+1一直到n-1行做个倍法加到当前行上
		// 使得i列往后的系数列也都变成0，i列保持值1
		// 这里实际上只算答案列，其它列的值用不到就用变了（变也就是变成0） 
		for (int j = i + 1; j < n; j ++) {
			a[i][n] -= a[j][n] * a[i][j]; // a[i][j]就是倍法变换乘的数 
		} 
	}
	return 1; // 指示有唯一解 
} 

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n + 1; j ++)
			scanf("%lf", &a[i][j]);
	
	int t = gauss();
	
	if (t == 0) // 无解 
		puts("No solution");
	else if (t == 1) // 唯一解，就在最后一列 
		for (int i = 0; i < n; i ++)
			printf("%.2lf\n", a[i][n]);
	else // 无穷解 
		puts("Infinite group solutions");
	
	return 0;
}
