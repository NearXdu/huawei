#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main()
{
    string str;
    unordered_set<char>s;
    std::getline(cin,str);

    int count=0;
    for(int i=0;i<str.size();++i)
    {
	if(str[i]<128&&str[i]>=0)
	{
	    if(s.find(str[i])==s.end())
	    {
		++count;
		s.insert(str[i]);
	    }
	}
    }
    cout<<count<<endl;

    return 0;
}
