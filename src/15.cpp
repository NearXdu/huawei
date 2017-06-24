#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
	int count=0;
	while(n)
	{
	    n&=(n-1);
	    ++count;
	}
	cout<<count<<endl;
    }
}
