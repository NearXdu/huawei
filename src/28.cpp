#if 1
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <limits>
using namespace std;

void print(vector<int>a)
{
    std::adjacent_difference(a.begin(),a.end(),ostream_iterator<int>(cout," "),
	    [](int a,int b){cout<<" ";return a;});
    //    copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

}

bool isPrime(int n)
{
    if(n==2)
	return true;
    if(n&1==0)
	return false;
    for(int i=3;i<=sqrt(n);i+=2)
    {
	if(n%i==0)
	    return false;
    }
    return true;
}

int main()
{
    int n;
    vector<int>Prime(60000,1);
    Prime[0]=Prime[1]=false;
    for(int i=4;i<60000;i+=2)
	Prime[i]=false;
    for(int i=3;i*i<60000;i+=2)
    {
	if(Prime[i])
	{
	    for(int j=i*i;j<60000;j+=2*i)
		Prime[j]=false;
	}

    }

    while(cin>>n)
    {
	vector<int>a(n);
	for(int i=0;i<n;++i)
	{
	    cin>>a[i];
	}
	sort(a.begin(),a.end());
	int mm=std::numeric_limits<int>::min();
	do{
	    int count=0;
	    for(int i=0;i<a.size()-1;i+=2)
	    {
		if(Prime[a[i]+a[i+1]])
		    ++count;
	    }
	    if(count>mm)
		mm=count;
	}while(next_permutation(a.begin(),a.end()));
	cout<<mm<<endl;
    }
}
#endif
