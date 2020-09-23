#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

/*
(1)确定分界点，x=q[l]，x=q[r]，x=q[(l+r)/2]，x=q[随机位置]
(2)调整范围，使左边都<=x，右边都>=x
(3)递归处理左右两边 
*/

void quick_sort(int q[], int l, int r) {
	if (l >= r) return ;

	int x = q[l+r >> 1], i = l-1, j = r+1;
	while (i < j) {
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}
	
	// 用(q, l, j)和(q, j+1, r)时x不能取q[r]
	// 用(q, l, i-1)和(q, i, r)时x不能取q[l] 
	quick_sort(q, l, j);
	quick_sort(q, j+1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n ; i++) scanf("%d", &q[i]);
	
	quick_sort(q, 0, n-1);
	
	for (int i = 0; i < n ; i++) printf("%d ", q[i]);
	
	return 0;
}
