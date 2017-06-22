#include <iostream>
#include <string>
using namespace std;
int main(int argc,char **argv)
{
    string str;
    char c;

    getline(cin,str);
    cin>>c;

    int count=0;
    for(int i=0;i<str.size();++i)
    {
	if(tolower(str[i])==tolower(c))
	    ++count;
    }
    cout << count<<endl;


    return 0;
}
