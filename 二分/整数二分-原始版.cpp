#include <iostream>
using namespace std;

/*
整数二分的本质是在区间[l,r]上定义了某种性质
能够找到一个将其分为两部分的位置
在其两侧，一侧满足性质，一侧不满足性质 
那么只要找到这个特殊边界位置就可以了

假设在右侧性质是满足的，而在左侧性质不满足
000000000000000111111111111111111111111
(1)找中间位置，mid=(l+r)/2
(2)判断中间位置是不是满足性质，即check(mid)
(3)满足性质了，在左边区间找分界点
(3)不满足性质，在右边区间找分界点
每次二分都要保证区间里一定有要找的那个点 

要注意“要找的分界点”是满足性质的那个还是不满足性质的那个
这两个点是相邻的
如果是找满足性质的(偏右的点)，那么mid满足性质时就不能丢掉mid
如果是找不满足性质的(偏左的点)，那么mid不满足性质时就不能丢掉mid

如果缩区间时l=mid，那么求mid时候mid=(l+r+1)/2
如果缩区间时r=mid，那么求mid时候mid=(l+r)/2 
*/


// 区间[l, r]被划分成[l, mid]和[mid+1, r]时使用 
int bsearch_1(int l, int r) {
	while (l < r) {
		int mid = l+r >> 1;
		if (check(mid)) r = mid; // 因为是r=mid，找偏右的点，移动r时不丢掉mid 
		else l = mid + 1;
	}
	return l;
}

// 区间[l, r]被划分成[l, mid-1]和[mid, r]时使用
int bsearch_2(int l, int r) {
	while (l < r) {
		int mid = l+r+1 >> 1;
		if (check(mid)) r = mid-1;
		else l = mid; // 因为是l=mid，找偏左的点，移动l时不丢掉mid 
	}
	return l;
}

