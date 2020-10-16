#include <iostream>

using namespace std;


const int N = 1e5 + 10;

// Trie孩子，N个数 * 每个数31位非符号位 
int son[N * 31][2];

// 结点处有数字（这题里可以不用，因为等长） 
bool use[N * 31]; 

// 分配Trie结点，0表示空结点，也表示根 
int idx;

// 向Trie树里插入一个二进制数
void insert(int x) {
	int p = 0;
	for (int k = 30; k >= 0; k --) {
		// 这个数的该位 
		int i = (x >> k) & 1;
		// 没有结点就创建 
		if (!son[p][i]) {
			son[p][i] = ++ idx;
		}
		p = son[p][i];
	}
	// 记录这个数字是存在的（这题里可以不用） 
	use[p] = true;
}

int v[N];

int ans = 0;

// 检查和数x最匹配的值 
void check(int x) {
	int nowans = 0;
	int p = 0;
	for (int k = 30; k >= 0; k --) {
		// 这个数的该位
		int i = (x >> k) & 1;
		// 1变0，0变1，是想找的该位 
		// 先找最好的，没有再去尝试和自己相同的 
		if (son[p][1 - i]) {
			p = son[p][1 - i];
			// 异或后，这一位是1 
			nowans = (nowans << 1) + 1; 
		}
		else if (son[p][i]) {
			p = son[p][i];
			// 异或后，这一位是0
			nowans = nowans << 1; 
		}
		else // 无路可走（在这题里不可能） 
			return ;
	}
	// 31位都跑完，更新ans（在这题里到这里use[p]一定是true）
	if (use[p] && nowans > ans) 
		ans = nowans; 
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &v[i]);
		insert(v[i]);
		// 在插入过程中就能检查
		check(v[i]); 
	}
	
	printf("%d\n", ans);
	
	return 0;
} 
