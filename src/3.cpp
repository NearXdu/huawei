#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


int main()
{
    // input 
    int n;
    while(cin>>n)
    {
	vector<int>v;
	v.reserve(1024);
	int j;
	for(int i=0;i<n;++i)
	{
	    cin >> j;
	    v.push_back(j);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	if(v.capacity()<1024)
	    vector<int>(v).swap(v);

	//copy(v.begin(),v.end(),ostream_iterator<int>(cout,"\n"));
	for(int i=0;i<v.size();++i)
	    cout<<v[i]<<endl;
    }
    return 0;
}
