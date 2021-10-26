//rod cutting problem - unbounded knapsack
#include<bits/stdc++.h>
using namespace std;
#define ll		long long
#define vll		vector <ll>

ll rodCutting(vll &prices, ll n)
{
	//unbounded knapsack
	vector <vll> dp(n+1, vll (n+1,0));
	//initilization
	for (ll i=0;i<=n;i++)
		dp[i][0]=0;
	for (ll j=1;j<=n;j++)
		dp[0][j]=0;
	//iterative
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=n;j++)
		{
			if (i<=j)		//unlike 0-1 Knapsack dp[i] can be taken multiple times, hence dp[i] instead of dp[i-1]
				dp[i][j]=max(dp[i-1][j],prices[i-1]+dp[i][j-i]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][n];
}

int main()
{
	ll n;
	cin>>n;
	vll prices(n);
	for (ll i=0;i<n;i++)
		cin>>prices[i];
	cout<<rodCutting(prices,n);
	return 0;
}
