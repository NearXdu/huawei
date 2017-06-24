#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
	string str;
	while(n)
	{
	    str+=to_string(n%10);
	    n/=10;
	}
	cout<<str<<endl;
    }
    return 0;

}
