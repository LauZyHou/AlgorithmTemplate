#include <iostream>
using namespace std;

/*
����һ������Ϊn���������У� 
���ҳ���Ĳ������ظ��������������䣬������ĳ���

j�������Ҷ˵㣬i���ڵ�ǰjΪ�Ҷ˵�ʱ�������������˵�
���Է��ֵ�j������ʱi������ˣ�����O(n)��ɨ�� 
*/

const int N = 1e5 + 10;
int s[N]; // ��¼ÿ�������ִ���
int n, l, r, ans = 0;

// �������[a,b]֮�����ظ�Ԫ��
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
    
    // r�������Ҷ˵�
    for (l = 0, r = 0; r < n; r++) {
        s[v[r]]++; // ÿ��r++ʱ��¼v[r]����һ��
        // l��������˵�
        /*
        while (l <= r && check(v, l, r))
            s[v[l]]--, l++; // ÿ��l++ʱ��¼v[l]����һ��
        */
        // �Ż�����Ϊ�¼��������s[v[r]]�������ظ�Ҳֻ�����������
        // ���⣬����ֻʣһ����ʱһ���������������Բ���Ҫ�ж�l<=r
        while (s[v[r]] > 1)
            s[v[l]]--, l++;
        ans = max(ans, r-l+1);
    }
    
    cout << ans << endl;
    
    return 0;
}
