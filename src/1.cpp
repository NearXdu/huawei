/*
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。 

输入描述:
一行字符串，非空，长度小于5000。

输出描述:
整数N，最后一个单词的长度。

输入例子:
hello world

输出例子:
5
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int i=str.size()-1;
    int count=0;
    while(str[i]!=' '&&i>=0)
    {
	++count;
	--i;
    }
    cout<<count<<endl;
    return 0;
}
