#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<char ,char>idx;
string & change(string &tmp)
{
    for(int i=0;i<tmp.size();++i)
    {
	if(std::isdigit(tmp[i]))
	{
	    tmp[i]=idx[tmp[i]];
	    if(std::isalpha(tmp[i]))
		tmp[i]=toupper(tmp[i]);
	}
	else if((tolower(tmp[i])<='f'&&tolower(tmp[i])>='a'))
	{
	    tmp[i]=idx[tolower(tmp[i])];
	    if(std::isalpha(tmp[i]))
		tmp[i]=std::toupper(tmp[i]);
	}

    }
    return tmp;
}
int main()
{
    idx['0']='0';
    idx['1']='8';
    idx['2']='4';
    idx['3']='C';
    idx['4']='2';
    idx['5']='a';
    idx['6']='6';
    idx['7']='e';
    idx['8']='1';
    idx['9']='9';
    idx['a']='5';
    idx['b']='d';
    idx['c']='3';
    idx['d']='b';
    idx['e']='7';
    idx['f']='f';
    string str1;
    string str2;
    while(cin>>str1>>str2)
    {
	string tmp = str1+str2;
	string s1;//odd
	string s2;//even
	for(int i=0;i<tmp.size();++i)
	{
	    if((i&1)==0)//even
	    {
		s2+=tmp[i];
	    }
	    else//odd
	    {
		s1+=tmp[i];
	    }
	}
	sort(s1.begin(),s1.end());//odd
	sort(s2.begin(),s2.end());//even
	int ii=0;//even
	int jj=0;//odd
	string tmp2;
	for(int i=0;i<tmp.size();++i)
	{
	    if((i&1)==0)//even
	    {
		tmp2+=s2[ii++];
	    }
	    else//odd
	    {
		tmp2+=s1[jj++];
	    }
	}
	tmp2=change(tmp2);
	cout<<tmp2<<endl;
    }
    return 0;
}
