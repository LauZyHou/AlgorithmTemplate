#include <iostream>
#include <cstring>
using namespace std;

/*
输入一个字符串，其中每个单词是用空格隔开的
现在要把其中的单词提取出来 
*/

int main() {
	const char* str = " I am sb lzh. good   bye world. ";
	
	int n = strlen(str); 
	
	for (int i = 0; i < n; i++) {
		// 跳过开头空格 
		if (str[i] == ' ')
			continue;
		// 双指针 
		int j = i;
		while (j < n && str[j] != ' ')
			j++;
		// 这道题的具体逻辑，即提取非空格部分 
		for (int k = i; k < j; k++)
			cout << str[k];
		cout << endl;
		i = j; 
	}
	
	return 0;
}
