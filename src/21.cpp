#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map< char,char> m;
    m['a']='2';  
    m['b']='2';  
    m['c']='2';  
    m['d']='3';  
    m['e']='3';  
    m['f']='3';  
    m['g']='4';  
    m['h']='4';  
    m['i']='4';  
    m['j']='5';  
    m['k']='5';  
    m['l']='5';  
    m['m']='6';  
    m['n']='6';  
    m['o']='6';  
    m['p']='7';  
    m['q']='7';  
    m['r']='7';  
    m['s']='7';  
    m['t']='8';  
    m['u']='8';  
    m['v']='8';  
    m['w']='9';  
    m['x']='9';  
    m['y']='9';  
    m['z']='9';  
    string str;
    while(cin >> str)
    {
	for(int i=0;i<str.size();++i)
	{
	    if(str[i]<='z'&&str[i]>='a')
	    {
		str[i]=m[str[i]];
	    }
	    else if(str[i]<='Z'&&str[i]>='A')
	    {
		str[i]=std::tolower(str[i]);
		if(str[i]=='z')
		    str[i]='a';
		else
		    str[i]+=1;
	    }
	}
	cout<<str<<endl;

    }
    return 0;
}
