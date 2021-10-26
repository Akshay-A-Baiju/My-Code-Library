//equal sum partition
//observation: since sum of 2 subsets must be equal, hence both subset sum = sum of array/2
//if sum of array/2 subset sum is possible, then equal sum partition

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

bool subset_sum(vll &v, ll sum, ll n)
{
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
	return dp[n][sum];
}
int main()
{
	ll n;
	cin>>n;
	vll v(n);
	for (ll i=0;i<n;i++)
		cin>>v[i];
	ll sum=accumulate(v.begin(),v.end(),0LL);
	if (sum&1)        //if sum of array is odd, then equal sum partition can not be formed
		cout<<"no";
	else
		subset_sum(v,sum/2,n)?cout<<"yes":cout<<"no";
	return 0;
}
