#include <iostream>

using namespace std;

/*
https://www.acwing.com/problem/content/893/

Nim游戏异或值不为0，先手必胜，否则先手必败 
*/

int main() {
	int n;
	scanf("%d", &n);
	
	int res = 0;
	
	while (n --) {
		int x;
		scanf("%d", &x);
		res ^= x;
	}
	
	if (res)
		puts("Yes");
	else
		puts("No");
	
	return 0;
}
