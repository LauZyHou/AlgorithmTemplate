#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

/*
(1)ȷ���ֽ�㣬x=q[l]��x=q[r]��x=q[(l+r)/2]��x=q[���λ��]
(2)������Χ��ʹ��߶�<=x���ұ߶�>=x
(3)�ݹ鴦���������� 
*/

void quick_sort(int q[], int l, int r) {
	if (l >= r) return ;

	int x = q[l+r >> 1], i = l-1, j = r+1;
	while (i < j) {
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}
	
	// ��(q, l, j)��(q, j+1, r)ʱx����ȡq[r]
	// ��(q, l, i-1)��(q, i, r)ʱx����ȡq[l] 
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
