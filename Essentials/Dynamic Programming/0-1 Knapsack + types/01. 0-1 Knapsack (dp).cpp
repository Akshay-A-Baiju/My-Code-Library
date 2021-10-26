#include<bits/stdc++.h>
using namespace std;
#define ll		long long
#define vll		vector <ll>
const ll N = 100;
const ll W = 1000;

ll Knapsack(vll &wt, vll &val, ll k, ll n)
{
	ll dp[n+1][k+1];					//dp[i][j] gives the maximum profit for first 'i' items with knapsack size 'j'
	//initialize
	for (ll i=0;i<=n;i++)
	{
		for (ll j=0;j<=k;j++)
		{
			if (i==0 || j==0)
				dp[i][j]=0;
		}
	}
	//iterative
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=k;j++)
		{
			if (wt[i]<=j)				  //if wt[i]<=j, 2 choice include or not include
				dp[i][j]=max(dp[i-1][j], val[i]+dp[i-1][j-wt[i]]);
			else						      //if wt[i]>j, only choice to exclude
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][k];
}

int main()
{
	ll n,k;
	cin>>n>>k;
    vll wt(n+1),val(n+1);
    for (ll i=1;i<=n;i++)
    	cin>>wt[i];
    for (ll i=1;i<=n;i++)
    	cin>>val[i];
    cout<<Knapsack(wt,val,k,n);
    return 0;
}
