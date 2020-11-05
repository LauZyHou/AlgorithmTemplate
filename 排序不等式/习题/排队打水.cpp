#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/description/915/ 

typedef long long LL;

const int N = 1e5 + 10;

int a[N];

int main() {
    int n;
    cin >> n;

    LL res = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        res -= a[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i ++ ) {
        a[i] += a[i - 1];
        res += a[i];
    }

    cout << res << endl;

    return 0;
}
