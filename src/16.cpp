#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
	vector<int>v(m+1);//value
	vector<int>p(m+1);//importance
	vector<int>q(m+1);//major or minor
	vector< vector<int>  >dp(m+1,vector<int>(n+1));//dp
	//input
	for(int i=1;i<=m;++i)
	{
	    cin>>v[i]>>p[i]>>q[i];
	}
	for(int i=1;i<=m;++i)
	{
	    for(int j=1;j<=n;++j)
	    {
		if(!q[i])//major
		{
		    if(v[i]<=j)
		    {
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*p[i]);
		    }
		}
		else// minor
		{
		    if(v[i]+v[q[i]]<=j)
		    {
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*p[i]);
		    }

		}

	    }
	}//end for
	cout<<dp[m][n]<<endl;
    }
}
