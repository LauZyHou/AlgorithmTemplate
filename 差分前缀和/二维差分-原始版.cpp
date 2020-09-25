#include <iostream>
using namespace std;

/*
二维差分
对于一个矩阵a，找到一个矩阵b，使得a是b的前缀和矩阵
即b[i][j]及其左上角的子矩阵所有元素加起来=a[i][j]

二维差分可以用于给a中的一个子矩阵（左上角(x1,y1)，右下角(x2,y2)）的全部元素加上c 
如果在b数组中某个位置b[i][j]+=c，则相当于在前缀和矩阵a中，这个位置开始右下角的所有位置都加上了c
所以针对子矩阵（左上角(x1,y1)，右下角(x2,y2)），只要：
b[x1][y1] += c
b[x2+1][y1] -= c
b[x1][y2+1] -= c
b[x2+1][y2+1] += c

初始化还是a矩阵和b矩阵全都是0
然后读到值a[i][j]=val后，就只要把左上角(i,j)右下角(i,j)这个子矩阵加上val 
这样可以统一操作，不用思考b怎么构造 
*/

const int N = 1e3 + 10;

int n, m, q;
int a[N][N], b[N][N];

void add(int x1, int y1, int x2, int y2, int c) {
	b[x1][y1] += c;
	b[x2+1][y1] -= c;
	b[x1][y2+1] -= c;
	b[x2+1][y2+1] += c;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			add(i, j, i, j, a[i][j]);
		
	int x1, y1, x2, y2, c;	
	while (q--) {
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
		add(x1, y1, x2, y2, c);
	}
	
	// 把b数组变成其前缀和数组，即可还原出a 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%d ", b[i][j]);
		puts("");
	}
	
	return 0;
}
