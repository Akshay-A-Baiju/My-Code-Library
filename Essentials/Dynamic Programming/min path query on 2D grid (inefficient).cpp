//Problem link : https://leetcode.com/problems/minimum-path-sum/
//inefficient -> 2D Dp array
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
	vector <vll> dp(n,vll (m));
	//initialization
	dp[0][0]=grid[0][0];
	for (ll i=1;i<n;i++)
		dp[i][0] = grid[i][0] + dp[i-1][0];
	for (ll i=1;i<m;i++)
		dp[0][i] = grid[0][i] + dp[0][i-1];
	//iterative 
	for (ll i=1;i<n;i++)
	{
		for (ll j=1;j<m;j++)
			dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
	}
	cout<<"Minimum cost : "<<dp[n-1][m-1];
	return 0;
}
