#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10;
const int P = 131; // 表示成P进制数

ULL h[N], p[N]; // 哈希值和P的次幂
char str[N]; // 字符串，从1开始标号

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int n, m;
    scanf("%d%d%s", &n, &m, str + 1);
    
    // 计算P的次幂和哈希值
    p[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    
    // 处理m此询问
    while (m -- ) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        // 比较区间内子串的哈希值是否相等
        if (get(l1, r1) == get(l2, r2))
            puts("Yes");
        else
            puts("No");
    }
    
    return 0;
}