#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(int argc,char **argv)
{
    string raw;
    while(getline(cin,raw))
    {
	vector<string>sorted(26);
	for(int i=0;i<raw.size();++i)
	{
	    if(std::isalpha(raw[i]))
	    {
		if(raw[i]>='a'&&raw[i]<='z')
		{
		    sorted[raw[i]-'a']+=raw[i];
		}
		else
		{
		    sorted[raw[i]-'A']+=raw[i];
		}
	    }
	}
	string tmp;
	for(int i=0;i<sorted.size();++i)
	{
	    tmp+=sorted[i];
	}
	int count=0;
	for(int i=0;i<raw.size();++i)
	{
	    if(std::isalpha(raw[i]))
	    {
		cout<<tmp[count++];
	    }
	    else
	    {
		cout<<raw[i];
	    }
	}
	cout<<endl;
    }
   
    return 0;
}

