#include <iostream>
using namespace std;

/*
一维差分
有a[1]...a[n]，构造b[1]...b[n]使得a[i]=b[1]+...+b[i]
只要让
b[1]=a[1]，b[2]=a[2]-a[1]，b[3]=a[3]-a[2]...
a数组是b数组的前缀和，b数组即是a数组的差分

只要对b数组计算前缀和就能得到a数组，所以只要用O(n)时间就能把b数组转换成a数组
差分是解决这样的问题，给定一个原始数组a，给定区间[l,r]，要将这个区间为下标的a数组里的数都加上c
即a[l]+=c，...,a[r]+=c 

只要让b[l]+=c，这样因为a数组是b数组的前缀和，所以从l往后的位置就全都加上c了
但是a[r+1]及其后的位置不希望加上c，所以让b[r+1]-=c即可
这样就实现了恢复出的a[l]..a[r]全都加上了c，只需要O(1)的时间

不需要去思考差分数组b是怎么构造出来的
可以假定a数组一开始都是0，所以差分的b数组也全是0
然后a[1]这个值是将[1,1]区间内的数加上a[1]实现的
同理a[i]这个值是将[i,i]区间内的数加上a[i]实现的 
*/

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

void add(int l, int r, int c) {
	b[l] += c;
	b[r+1] -= c; 
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i++) add(i, i, a[i]); // 构造b数组的过程
	
	int l, r, c;
	while (m--) {
		scanf("%d%d%d", &l, &r, &c);
		add(l, r, c);		
	} 
	
	// 把差分数组b变成前缀和数组，也就是变回a数组
	for (int i = 1; i <= n; i++) {
		b[i] += b[i-1];
		printf("%d ", b[i]);
	} 
	
	return 0;
} 
