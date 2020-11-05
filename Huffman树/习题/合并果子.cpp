#include <iostream>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i ++ ) {
        int a;
        cin >> a;
        heap.push(a);
    }
    
    int res = 0;
    for (int i = 0; i < n - 1; i ++ ) {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res += a + b;
        heap.push(a + b);
    }
    
    cout << res << endl;
    
    return 0;
}
