#include <iostream>
using namespace std;

/*
https://www.acwing.com/problem/content/156/

�����������͵����󻬶�������������С��ֵ 
��Ϊ�������ÿ����ö���ά���������Ĺ��̾�����ӳ��ӵĹ��� 
����Ҫ�ж��ƶ�ʱ��ͷ�ǲ���Ҫ�����ˣ����Զ�����������±� 
*/

const int N = 1e6 + 10;

int n, k;
int a[N], q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    	cin >> a[i];
    
    // �󻬶�������Сֵ 
    // ��ʼ����ͷ��β 
    int hh = 0, tt = -1;
    // ����ÿ��Ԫ��������� 
    for (int i = 0; i < n; i++) {
    	// �������λ��ʱ�����ж�Ŀǰ�Ķ�ͷ�Ƿ��Ѿ�����������
		// �������˾�Ҫ���� 
		if (hh <= tt && q[hh] < i - k + 1) {
			hh++;
		}
		// ���ֶ��еĵ������ʣ�Ҫ�Ӷ�β��ʼ����ɾ��������ǰֵ��Ԫ��
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		// ��ǰԪ�أ��±꣩���
		q[++tt] = i;
		// ��Ŀ��������Ҫװ��Ԫ��ʱ������
		if (i >= k - 1)
			cout << a[q[hh]] << ' '; // ��Ϊ�ǵ����ģ���Сֵ������߶�ͷ 
	}
	cout << endl;
	
	// �󻬶��������ֵ����������һ����˼·��ֻ�Ǳ��ֵ���
	hh = 0, tt = -1;
	for (int i = 0; i < n; i++) {
		if (hh <= tt && q[hh] < i - k + 1)
			hh++;
		while (hh <= tt && a[q[tt]] <= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			cout << a[q[hh]] << ' ';
	} 
	cout << endl;
	
	return 0;
}
