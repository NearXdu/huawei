#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    priority_queue<string,vector<string>,greater<string> >q;
    
    string str;
    while(cin>>n)
    {
	for(int i=0;i<n;++i)
	{
	    cin>>str;
	    q.push(str);
	}
	while(!q.empty())
	{
	    cout<<q.top()<<endl;
	    q.pop();
	}
    }
    return 0;
}
