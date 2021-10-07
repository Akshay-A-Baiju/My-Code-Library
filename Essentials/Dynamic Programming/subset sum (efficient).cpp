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
	vector <bool> dp(sum+1,false);
	//initialization
	dp[0]=true;
	for (ll i=0;i<n;i++)
	{
		//traverse from back of dp array
		for (ll j=sum;j>=0;j--)
		{
			if (dp[j]==false)
			{
				if (j-v[i]>=0 && dp[j-v[i]]==true)
					dp[j]=true;
			}
		}
	}
	dp[sum]?cout<<"True":cout<<"False";
	return 0;
}
