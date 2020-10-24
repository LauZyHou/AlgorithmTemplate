#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/897/

// 状态表示：f[i]
// 集合：所有以第i个数结尾的数值上升的子序列
// 属性：集合里每个上升子序列的长度的最大值
// 状态计算：f[i]的所有序列最后一个数都是i，基于前面一个数是谁来分类
// 前面一个数可能是a[1]~a[i-1]所有的满足a[j]<a[i]的数 
// f[i] = max(f[j] + 1), 其中j需要满足j < i && a[j] < a[i] 

const int N = 1010;

int a[N], f[N]; 

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i ++)
		scanf("%d", a + i);
	
	for (int i = 1; i <= n; i ++) {
		f[i] = 1; // 序列里只有a[i]一个数时长度是1
		// 枚举前一个数可能是谁
		for (int j = 1; j < i; j ++)
			if (a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
	}
	
	// 最后遍历以每个集合里最大值
	int res = 0;
	for (int i = 1; i <= n; i ++)
		res = max(res, f[i]);
	
	printf("%d\n", res);	 
	
	return 0;
}
