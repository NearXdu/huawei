#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct pair_
{
    int key;
    int value;

    bool operator==(const struct pair_ &x)
    {
	return x.key==this->key;
    }
};
typedef vector<pair_> Pairs;
class comp{
    public:
	bool operator()(const pair_&a,const pair_&b)
	{
	    return a.key<b.key;
	}
};
int main(int argc,char **argv)
{
    int N;
    Pairs pairs;
    pairs.reserve(1024);
    while(cin>>N)
    {
	Pairs::iterator it;
	for(int i=0;i<N;++i)
	{
	    pair_ tmp;
	    cin>>tmp.key>>tmp.value;
#if 1
	    if((it =find(pairs.begin(),pairs.end(),tmp))!=pairs.end())
		it->value+=tmp.value;
	    else
		pairs.push_back(tmp);
#endif
	}
	sort(pairs.begin(),pairs.end(),comp());
	for(int i=0;i<pairs.size();++i)
	{
	    cout<<pairs[i].key<<" "<<pairs[i].value<<endl;

	}


    }

    return 0;
}
