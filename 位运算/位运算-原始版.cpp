#include <iostream>
using namespace std;


// n�Ķ����Ʊ�ʾ�е�kλ�Ǽ�����λ�ǵ�0λ����k=0,1,2.. 
// �Ȱѵ�kλ�Ƶ���λ���ٿ���λ�Ǽ� 
bool calk(int x, int k) {
	return x >> k & 1;
}

// ����x�����һλ1
// ��x�����Ʊ�ʾΪ1010����lobit(x)=������10
// ��x�����Ʊ�ʾΪ101000����loit(x)=������1000
// -x == ~x + 1 ���� x & (-x) == x & (~x + 1) 
// ���Ҳ����״����Ļ��� 
bool lowbit(int x) {
	return x & -x;
}
