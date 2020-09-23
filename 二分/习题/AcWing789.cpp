#include <iostream>
using namespace std;

// https://www.acwing.com/problem/content/791/
// 整数二分

const int N = 1e5 + 10;

int n, m;
int q[N];


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	
	while (m--) {
		int x;
		scanf("%d", &x);
		
		int l = 0, r = n - 1;
		while (l < r) {
			int mid = l+r >> 1;
			if (q[mid] >= x) r = mid;
			else l = mid + 1;
		}
		
		// 无解的情况 
		if (q[l]!=x) {
			printf("-1 -1\n");
			continue;
		}
		printf("%d ", l);
		
		l = 0, r = n-1;
		while(l < r) {
			int mid = l+r+1 >> 1;
			if (q[mid] <= x) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
	
	return 0;
}
