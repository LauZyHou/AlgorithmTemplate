#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/127/

const int N = 5e4 + 10;

typedef pair<int, int> PII;

PII cow[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        int s, w;
        cin >> s >> w;
        cow[i] = {s + w, s}; // ���㰴��һ������
    }
    
    sort(cow, cow + n);
    int res = -2e9, sum = 0; // sum��¼��������ţ��w�Ӻ�
    for (int i = 0; i < n; i ++ ) {
        int w = cow[i].second;
        int s = cow[i].first - w;
        res = max(res, sum - s);
        sum += w;
    }
    
    cout << res << endl;
    
    return 0;
}
