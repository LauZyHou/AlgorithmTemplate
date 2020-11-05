#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/908/

const int N = 1e5 + 10;

struct Range{
    int l, r;
    bool operator< (Range& W)const {
        return l < W.l;
    }
}range[N];

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i ++ )
        cin >> range[i].l >> range[i].r;
    
    // ����˵�����
    sort(range, range + n);
    
    // ÿ����������Ҷ˵������Ҷ˵�ֵ����ɵ���С��
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for (int i = 0; i < n; i ++ ) {
        if (heap.empty() || heap.top() >= range[i].l) { // �����е������н���
            heap.push(range[i].r);
        }
        else {
            heap.pop();
            heap.push(range[i].r);
        }
    }
    
    cout << heap.size() << endl;
    
    return 0;
}
