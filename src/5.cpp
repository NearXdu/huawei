#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;
int main()
{
    unordered_map<char,int>mmap;
    mmap['0']=0;
    mmap['1']=1;
    mmap['2']=2;
    mmap['3']=3;
    mmap['4']=4;
    mmap['5']=5;
    mmap['6']=6;
    mmap['7']=7;
    mmap['8']=8;
    mmap['9']=9;
    mmap['a']=10;
    mmap['A']=10;
    mmap['b']=11;
    mmap['B']=11;
    mmap['c']=12;
    mmap['C']=12;
    mmap['d']=13;
    mmap['D']=13;
    mmap['e']=14;
    mmap['E']=14;
    mmap['F']=15;
    mmap['f']=15;
    string str;
    while(cin >> str)
    {
	str=str.substr(2);
	long sum=0;
	for(int i=0;i<str.size();++i)
	{
	    sum*=16;
	    sum+=mmap[str[i]];
	}
	cout<<sum<<endl;

    }

    return 0;
}
