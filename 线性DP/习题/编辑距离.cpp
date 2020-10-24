#include <iostream>
#include <cstring>

using namespace std;

// https://www.acwing.com/problem/content/901/

const int N = 15; // 串长最大是10 
const int M = 1010;

char str[M][N];

int f[M][M];

// 求两个串的编辑距离 
int edit_distance(char a[], char b[]) {
	int la = strlen(a + 1), lb = strlen(b + 1);
	// 初始化边界
	for (int i = 0; i <= la; i ++)
		f[i][0] = i;
	for (int j = 0; j <= lb; j ++)
		f[0][j] = j;
	// dp
	for (int i = 1; i <= la; i ++)
		for (int j = 1; j <= lb; j ++) {
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
		}
	return f[la][lb];
}


int main() {
	int n, m; // n个串，m个查询
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		scanf("%s", str[i] + 1);
	
	while (m --) {
		char s[N];
		int limit;
		scanf("%s%d", s + 1, &limit);
		// 和每个串求编辑距离，看不超过limit的有几个
		int res = 0;
		for (int i = 0; i < n; i ++)
			if (edit_distance(str[i], s) <= limit)
				res ++;
		printf("%d\n", res);
	}
	 
	return 0;
}
