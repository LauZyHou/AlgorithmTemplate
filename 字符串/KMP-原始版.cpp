#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/833/

这里是从1开始索引字符串的写法 

模式串p上的next[j]表示头和尾匹配的最大长度
如p="ababc"，下标1~5，则next[4]=2
可以看到如果j+1位置不匹配了，直接j=next[j]就能继续对齐失配点之前的位置 

待匹配串：...   ...  i-1, i
模式串：  1, 2, ...   j, j+1
在i和j+1的地方失配，j退到next[j]
即模式串右移，以让1..next[j]的位置能和待匹配串从i-1往前相应的位置继续匹配 
*/

const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m;
int ne[N]; // next可能会和库里的东西重名，这里用ne 
char s[M], p[N]; // s是待匹配的串，p是模式串 

int main() {
	// 读入长为n的p串，长为m的s串，从1开始索引 
	cin >> n >> p + 1 >> m >> s + 1; 
	
	// 计算模式串上的next数组，因为ne[1]=0，所以从2开始算
	for (int i = 2, j = 0; i <= n; i++) {
		// 下一个位置不匹配，就用ne数组挪动模式串指针j
		// j如果到0就相当于这个失配点让模式串从头开始匹配了 
		while (j && p[i] != p[j + 1])
			j = ne[j];
		// 如果失配点能匹配上，则模式串指针可以右移了 
		if (p[i] == p[j + 1])
			j++;
		// 因为总是从1开始计算下标的，当前模式串指针就是头和尾匹配的最大长度
		ne[i] = j; 
	}
	
	// 利用计算好的next数组，拿模式串p（长n）匹配待匹配串s（长m） 
	for (int i = 1, j = 0; i <= m; i++) {
		while (j && s[i] != p[j + 1])
			j = ne[j];
		if (s[i] == p[j + 1])
			j++;
		// j指针到n时候就匹配成功了
		if (j == n) {
			// 这题是输出所有匹配成功的位置下标 
			cout << i - n << ' ';
			// 所以找到一个之后还要缩一下j然后继续找
			j = ne[j]; 
		}
	}
	
	return 0;
}
