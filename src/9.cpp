#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
	string str=to_string(n);
	unordered_set<char>s;
	int sum=0;
	for(int i=str.size()-1;i>=0;--i)
	{
	    if(s.find(str[i])==s.end())
	    {
		sum*=10;
		sum+=(str[i]-'0');
		s.insert(str[i]);
	    }
	}
	cout<<sum<<endl;;
    }
    return 0;
}
