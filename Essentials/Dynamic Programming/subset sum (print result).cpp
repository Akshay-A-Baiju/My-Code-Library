#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
int main()
{
	ll n,sum;
	cin>>n>>sum;
	vll v(n);
	for (ll i=0;i<n;i++)
		cin>>v[i];
	//using top down Dp -> Linear space
	vll dp(sum+1,0);
	//dp[i] = stores the number which made that sum i
	//initialization
	dp[0]=1;
	for (ll i=0;i<n;i++)
	{
		//traverse from back of dp array
		for (ll j=sum;j>=0;j--)
		{
			if (dp[j]==0)
			{
				if (j-v[i]>=0 && dp[j-v[i]]!=0)
					dp[j]=v[i];
			}
		}
	}
	if (dp[sum]==0)
		cout<<"No result";
	else
	{
		ll i=sum;
		while (i!=0)
		{
			cout<<dp[i]<<" ";
			i-=dp[i];
		}
	}
	return 0;
}
