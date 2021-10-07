//Problem link : https://leetcode.com/problems/minimum-path-sum/
//efficient -> 1D Dp array
//logic -> we need only the previous row to calculate min cost
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
int main()
{
	ll n,m;
	cin>>n>>m;
	vector <vll> grid(n, vll (m));
	for (ll i=0;i<n;i++)
	{
		for (ll j=0;j<m;j++)
			cin>>grid[i][j];
	}
	//top down Dp
	vll dp(m);
	//initialization
	dp[0]=grid[0][0];
	for (ll i=1;i<m;i++)
		dp[i] = grid[0][i] + dp[i-1];
	//iterative 
	for (ll i=1;i<n;i++)
	{
		for (ll j=0;j<m;j++)
		{
			if (j==0)
				grid[i][j] = grid[i][j] + dp[j];
			else
				grid[i][j] = grid[i][j] + min(grid[i][j-1],dp[j]);
		}
		dp=grid[i];
	}
	cout<<"Minimum path sum : "<<dp[m-1];
	return 0;
}
