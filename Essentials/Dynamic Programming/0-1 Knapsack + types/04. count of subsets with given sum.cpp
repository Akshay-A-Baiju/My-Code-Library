//count of subset with given sum
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

ll subset_sum(vll &v, ll sum, ll n)
{
	vector <vll> dp(n+1, vll (sum+1));
	//initialization
	for (ll i=0;i<=n;i++)
		dp[i][0]=1;			    //as sum 0 can always be formed by not choosing any elements from the array
	for (ll j=1;j<=sum;j++)
		dp[0][j]=0;			    //as sum j can always be formed by choosing 0 elements from the array
	//iterative
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=sum;j++)
		{
			if (j-v[i-1]>=0)
				dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];
}

int main()
{
	ll n,sum;
	cin>>n>>sum;
	vll v(n);
	for (ll i=0;i<n;i++)
		cin>>v[i];
	cout<<subset_sum(v,sum,n);
	return 0;
}
