
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool contain(int n,int i)
{
    string x1=to_string(n);
    string x2=to_string(i);

    return (x1.find(x2)==string::npos)?false:true;


}
int main(int argc,char **argv)
{
#if 1

    int In;
    int Rn;

    while(cin>>In)
    {
	int tmp;
	vector<int>I;
	vector<int>R;
	I.reserve(1024);
	R.reserve(1024);
	for(int i=0;i<In;++i)
	{
	    cin>>tmp;
	    I.push_back(tmp);
	}
	cin>>Rn;
	for(int i=0;i<Rn;++i)
	{
	    cin>>tmp;
	    R.push_back(tmp);
	}
	sort(R.begin(),R.end());
	R.erase(unique(R.begin(),R.end()),R.end());
	bool flag;

	vector<int> fin;
	for(int i=0;i<R.size();++i)
	{
	    vector<int>result;
	    flag=false;
	    int count=0;
	    for(int j=0;j<In;++j)
	    {
		if(contain(I[j],R[i]))
		{
		    flag=true;
		    ++count;
		    result.push_back(j);
		    result.push_back(I[j]);
		}

	    }
	    if(flag)
	    {
		fin.reserve(1024);
		fin.push_back(R[i]);
		fin.push_back(result.size()/2);
		for(int i=0;i<result.size();++i)
		{
		    fin.push_back(result[i]);
		}
	    }

	}
	cout<<fin.size()<<" ";
	for(int i=0;i<fin.size()-1;++i)
	{
	    cout<<fin[i]<<" ";
	}
	cout<<fin[fin.size()-1]<<endl;
    }


#endif

}

