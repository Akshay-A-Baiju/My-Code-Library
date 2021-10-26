//count no of subset with given difference
//observation: say sum1 and sum2 be the sum of 2 subset partitions, let sum1>sum2
//sum1-sum2=diff (given)
//sum1+sum2=array sum
//so sum1=(array sum+diff)/2, sum2=(array sum-diff)/2
//hence no of subset with given difference = count of subset with sum = sum1 or sum2

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

ll count_subset_sum(vll &v, ll sum, ll n)
{
	vector <vll> dp(n+1, vll (sum+1));
	//initialization
	for (ll i=0;i<=n;i++)
		dp[i][0]=1;			//as sum 0 can always be formed by not choosing any elements from the array
	for (ll j=1;j<=sum;j++)
		dp[0][j]=0;			//as sum j can always be formed by choosing 0 elements from the array
	//top-down dp
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

ll subsetDiffCount(vll &v, ll diff, ll n)
{
	ll sum=accumulate(v.begin(),v.end(),0LL);
	ll sum1=(sum+diff)/2;
	if ((sum+diff)%2==1)	//as sum1 cannot be a fraction, hence given subset difference not possible
		return 0;
	else
		return count_subset_sum(v,sum1,n);
}

int main()
{
	ll n,d;
	cin>>n>>d;
	vll v(n);
	for (ll i=0;i<n;i++)
		cin>>v[i];
	cout<<subsetDiffCount(v,d,n);
	return 0;
}
