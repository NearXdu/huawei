#include <iostream>
#include <string>
using namespace std;
bool condition1(const string& s)
{
    if(s.size()>8)
	return true;
    else
	return false;

}

bool condition2(const string& s)
{
    int upper=0;
    int lower=0;
    int digit=0;
    int symbol=0;
    int cnt=0;
    for(int i=0;i<s.size();++i)
    {
	if(s[i]>='0'&&s[i]<='9')
	{
	    digit=1;
	}
	else if(s[i]>='a'&&s[i]<='z')
	{
	    lower=1;
	}
	else if(s[i]>='A'&&s[i]<='Z')
	{
	    upper=1;
	}
	else
	{
	    symbol=1;
	}

    }
    cnt=upper+lower+digit+symbol;
    return cnt>2?true:false;
}

bool condition3(const string& s)
{
    for(int i=0;i<s.size()-2;++i)
    {
	string tmp=s.substr(i,3);
	string ss=s.substr(i+1);
	if(ss.find(tmp)!=string::npos)
	{
	    return false;
	}
    }
    return true;

}
int main()
{
    string s;
    while(cin>>s)
    {
	if(condition1(s)&&condition2(s)&&condition3(s))
	{
	    cout<<"OK"<<endl;
	}
	else
	{
	    cout<<"NG"<<endl;
	}
    }
    return 0;
}
