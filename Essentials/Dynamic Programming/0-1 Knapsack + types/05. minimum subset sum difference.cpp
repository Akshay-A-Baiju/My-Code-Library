//minimum subset sum difference
//observation: since difference of 2 subsets must be minimum, both subset must be close to sum of array/2
//i.e (sum1<=sum of array/2) and (sum2>=sum of array/2) and should be closest

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

ll minDifference(vll &v, ll n)
{
	//using logic of equal sum partition
	//find the closest sum possible to sum of array/2
	ll sum=accumulate(v.begin(),v.end(),0LL);
	vector <vector<bool>> dp(n+1, vector<bool> (sum/2+1,false));
	//initialization
	dp[0][0]=true;
	//top-down dp
	for (ll i=1;i<=n;i++)
	{
		for (ll j=0;j<=sum/2;j++)
		{
			if (j-v[i-1]>=0)
				dp[i][j] = dp[i-1][j] | dp[i-1][j-v[i-1]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	ll sum1=sum/2;
	for (;sum1>=0;sum1--)
	{
		if (dp[n][sum1]==true)
			break;
	}
	ll sum2=sum-sum1;
	return (sum2-sum1);
}

int main()
{
	ll n;
	cin>>n;
	vll v(n);
	for (ll i=0;i<n;i++)
		cin>>v[i];
	cout<<minDifference(v,n);
	return 0;
}
