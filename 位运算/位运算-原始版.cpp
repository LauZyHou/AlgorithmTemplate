#include <iostream>
using namespace std;


// n的二进制表示中第k位是几，个位是第0位，即k=0,1,2.. 
// 先把第k位移到个位，再看个位是几 
bool calk(int x, int k) {
	return x >> k & 1;
}

// 返回x的最后一位1
// 如x二进制表示为1010，则lobit(x)=二进制10
// 如x二进制表示为101000，则loit(x)=二进制1000
// -x == ~x + 1 所以 x & (-x) == x & (~x + 1) 
// 这个也是树状数组的基础 
bool lowbit(int x) {
	return x & -x;
}
