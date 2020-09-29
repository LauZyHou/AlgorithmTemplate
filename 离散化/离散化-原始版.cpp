#include <iostream>
#include <vector>
using namespace std;

/*
一个数组，值域很大，但是元素个数比较少
现在需要把它的值作为数组索引
可以将其去重排序后按照顺序映射到[0,去重后元素个数-1]的区间上
这个过程称为离散化，求离散化后的值可以用二分 
这是一种保序的离散化的方式 

例：
1, 2, 100, 2000, 30000, ...
0, 1,   2,    3,     4, ...
*/

// 对给定的x，用二分求出离散化之后的值
int find(vector<int> alls, int x) {
	int l = 0, r = alls.size() - 1;
	while (l < r) {
		int mid = l+r >> 1;
		if (alls[mid] >= x)
			r = mid;
		else
			l = mid + 1; 
	}
	// 这里不加1是映射到0开头的下标，否则映射到1开头的下标 
	// 比如映射完要求前缀和的情况下，就要映射到从1开始的下标了 
	return r;
}

int main() {
	
	// 读入数组 
	vector<int> alls;
	// 对数组从小到大排序 
	sort(alls.begin(), alls.end()));
	// 去除重复的元素，这里unique的作用是在排序基础上，将不重复元素放到开头部分，并返回重复元素开始位置
	// 然后从重复元素开始位置到数组末尾调用erase删除掉就达到去重的目的了 
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	return 0;
}
