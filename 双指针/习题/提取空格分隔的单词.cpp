#include <iostream>
#include <cstring>
using namespace std;

/*
����һ���ַ���������ÿ���������ÿո������
����Ҫ�����еĵ�����ȡ���� 
*/

int main() {
	const char* str = " I am sb lzh. good   bye world. ";
	
	int n = strlen(str); 
	
	for (int i = 0; i < n; i++) {
		// ������ͷ�ո� 
		if (str[i] == ' ')
			continue;
		// ˫ָ�� 
		int j = i;
		while (j < n && str[j] != ' ')
			j++;
		// �����ľ����߼�������ȡ�ǿո񲿷� 
		for (int k = i; k < j; k++)
			cout << str[k];
		cout << endl;
		i = j; 
	}
	
	return 0;
}
