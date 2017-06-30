#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {

    	vector<int>a(n);
	vector<int>dp1(n+1,1);//
	vector<int>dp2(n+1,1);//
	for(int i=0;i<n;++i)
	{
	    cin>>a[i];
	}
	vector<int>ra(a.rbegin(),a.rend());
	for(int i=1;i<a.size();++i)
	{
	    for(int j=0;j<i;++j)
	    {
		if(a[i]>a[j])
		{
		    dp1[i]=max(dp1[i],dp1[j]+1);
		}
	    }
	}
	for(int i=1;i<ra.size();++i)
	{
	    for(int j=0;j<i;++j)
	    {
		if(ra[i]>ra[j])
		{
		    dp2[i]=max(dp2[i],dp2[j]+1);
		}
	    }
	}

	int mm=std::numeric_limits<int>::min();
	for(int i=0;i<a.size();++i)
	{
	    int j=a.size()-i-1;
	    if(dp1[i]+dp2[j]>mm)
	    {
		mm=dp1[i]+dp2[j];
	    }
	}
	cout<<a.size()-mm+1<<endl;
    }

    return 0;
}

