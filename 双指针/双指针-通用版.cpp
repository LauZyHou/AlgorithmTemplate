#include <iostream>
using namespace std;

/*
双指针算法最核心的性质就是优化
本来两个指针移动有n^2种组合
在双指针算法里，两个指针之间有单调关系，每个指针移动次数不超过n
两个指针一共移动次数不超过2n
即应用某些性质将O(n^2)的算法优化到O(n) 
*/

// 检查满足某种性质 
bool check(int i, int j) {
	
}

int main() {
	for (int i = 0, j = 0; i < n; i++) {
		while (i < j && check(i, j))
			j++;
		// 每道题目的具体逻辑 
	}
	
	return 0;
} 
