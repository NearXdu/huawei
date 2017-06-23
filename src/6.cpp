#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long input;
    while(cin>>input)
    {
	while(input>static_cast<int>(1))
	{
	    for(int i=2;i<=input;++i)
	    {
		if(input%i==0)
		{
		    input/=i;
		    cout<<i<<" ";
		    break;
		}

	    }
	}
	cout<<endl;
    }
    return 0;
}
