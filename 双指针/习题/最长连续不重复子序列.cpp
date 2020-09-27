#include <iostream>
using namespace std;

/*
给定一个长度为n的整数序列， 
请找出最长的不包含重复的数的连续区间，输出它的长度

j：区间右端点，i：在当前j为右端点时的最左的区间左端点
可以发现当j往右走时i不会回退，可以O(n)次扫描 
*/

const int N = 1e5 + 10;
int s[N]; // 记录每个数出现次数
int n, l, r, ans = 0;

// 检查区间[a,b]之间有重复元素
bool check(vector<int> &v, int a, int b) {
    for (int i = a; i <= b; i++)
        if (s[v[i]] > 1)
            return true;
    return false;
}

int main () {
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    // r：区间右端点
    for (l = 0, r = 0; r < n; r++) {
        s[v[r]]++; // 每次r++时记录v[r]出现一次
        // l：区间左端点
        /*
        while (l <= r && check(v, l, r))
            s[v[l]]--, l++; // 每次l++时记录v[l]消除一次
        */
        // 优化：因为新加入的数是s[v[r]]，所以重复也只可能是这个数
        // 另外，区间只剩一个数时一定满足条件，所以不需要判断l<=r
        while (s[v[r]] > 1)
            s[v[l]]--, l++;
        ans = max(ans, r-l+1);
    }
    
    cout << ans << endl;
    
    return 0;
}
