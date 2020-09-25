#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
(非负)大整数A / 小整数b，商是C，余数是r 
十进制位数len(A)<=10^6
因为b是一个小整数，每次将b当作一个整体和A中的每一位作除法 

注意：除法是从最高位开始算的，而加法、减法、乘法都是从最低位开始算的
所以如果题目中只有除法，那么正着来存（数组低位->高位 数高位->低位）会更好写 
一般情况下高精度的题目中都是加减乘除都有的，所以为了能有一般性
这里实现的除法的存储方式也和前面一样的从低位到高位（倒着来存） 
*/

vector<int> div(vector<int> &A, int b, int &r) {
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		r = r*10 + A[i];
		C.push_back(r / b);
		r %= b; 
	}
	
	// 到这里得到的C都应该是正序输出的，但是为了保持一致
	// 让数总是倒着来存，这里反向一下，保持定义格式一致 
	reverse(C.begin(), C.end());
	// 还有就是考虑一下前导0，因为已经反向了，所以前导0在末尾
	while (C.size() > 1 && C.back()==0)
		C.pop_back();
	
	return C;
}


int main() {
	string a;
	int b;
	
	cin >> a >> b;
	
	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	
	int r; // 余数，通过引用传回来
	auto C = div(A, b, r);
	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	printf("\n%d\n", r);
	
	return 0;
}
