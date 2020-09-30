#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/156/

单调队列最经典就的是求滑动窗口里的最大（最小）值 
因为窗口正好可以用队列维护，滑动的过程就是入队出队的过程 
由于要判断移动时队头是不是要出队了，所以队列里存数组下标 
*/

const int N = 1e6 + 10;

int n, k;
int a[N], q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    	cin >> a[i];
    
    // 求滑动窗口最小值 
    // 初始化队头队尾 
    int hh = 0, tt = -1;
    // 遍历每个元素依次入队 
    for (int i = 0; i < n; i++) {
    	// 到这个新位置时，先判断目前的队头是否已经滑出窗口了
		// 滑出来了就要出队 
		if (hh <= tt && q[hh] < i - k + 1) {
			hh++;
		}
		// 保持队列的单增性质，要从队尾开始不断删除超过当前值的元素
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		// 当前元素（下标）入队
		q[++tt] = i;
		// 题目窗口里是要装满元素时候才输出
		if (i >= k - 1)
			cout << a[q[hh]] << ' '; // 因为是单增的，最小值是最左边队头 
	}
	cout << endl;
	
	// 求滑动窗口最大值，和上面是一样的思路，只是保持单减
	hh = 0, tt = -1;
	for (int i = 0; i < n; i++) {
		if (hh <= tt && q[hh] < i - k + 1)
			hh++;
		while (hh <= tt && a[q[tt]] <= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			cout << a[q[hh]] << ' ';
	} 
	cout << endl;
	
	return 0;
}
