#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int minVal=21;
    string str;
    while(cin >> str)
    {
	unordered_map<char,int>m;
	for(int i=0;i<str.size();++i)
	{
	    m[str[i]]++;
	}//init

	for(auto it = m.begin();it!=m.end();++it)
	{
	    if(it->second<minVal)
		minVal=it->second;
	}
	string res;
	for(int i=0;i<str.size();++i)
	{
	    if(m[str[i]]!=minVal)
		res+=str[i];
	}
	cout<<res<<endl;

    }
    return 0;
}
