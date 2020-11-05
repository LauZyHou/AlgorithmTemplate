#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/106/

const int N = 1e5 + 10;

int q[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ )
        cin >> q[i];

    sort(q, q + n);

    int mid = n >> 1;
    int res = 0;
    for (int i = 0; i < n; i ++ )
        res += abs(q[i] - q[mid]);
    cout << res << endl;

    return 0;
}

