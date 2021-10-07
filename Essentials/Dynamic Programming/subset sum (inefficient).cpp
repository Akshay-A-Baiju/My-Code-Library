#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,sum;
	cin>>n>>sum;
	vll v(n);
	for (ll i=0;i<n;i++)
		cin>>v[i];
	vector <vector<bool>> dp(n+1, vector<bool> (sum+1,false));
	//initialization
	dp[0][0]=true;
	//top-down dp
	for (ll i=1;i<=n;i++)
	{
		for (ll j=0;j<=sum;j++)
		{
			if (j-v[i-1]>=0)
				dp[i][j] = dp[i-1][j] | dp[i-1][j-v[i-1]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	dp[n][sum]?cout<<"True":cout<<"False";
	return 0;
}
