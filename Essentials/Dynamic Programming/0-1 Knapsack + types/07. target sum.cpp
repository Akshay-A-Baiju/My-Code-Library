//target sum
//target sum is nothing but count no of subsets with given difference
//edge case: when array element is 0, it can be added to either subset, hence it has 2 choices
//no of target sum=(no of subsets with given difference)*(2^(count of 0 in array))

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

int count_subset_sum(vector <int> &nums, int sum)
{
	int n=nums.size();
	vector <vector <int>> dp(n+1, vector <int> (sum+1,0));
	//initialize
	for (int i=0;i<=n;i++)
		dp[i][0]=1;
	for (int j=1;j<=sum;j++)
		dp[0][j]=0;
	//iterative
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=sum;j++)
		{
			if (nums[i-1]<=j && nums[i-1]!=0)		//we shouldnt add for element 0 here, taken care afterwards
				dp[i][j]=dp[i-1][j] + dp[i-1][j-nums[i-1]];
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][sum];
}
int findTargetSumWays(vector<int>& nums, int target) {
	//observation: the target sum problem is nothing but count the number of subset with given difference!!!
	target=abs(target);
	int sum=accumulate(nums.begin(),nums.end(),0);
	if (target>sum || (sum+target)%2==1)    //when target is not possible or sum1 is fractional, not possible
		return 0;
	int count0=count(nums.begin(),nums.end(),0);
	int sum1=(sum+target)/2;
	return count_subset_sum(nums,sum1)*(1<<count0);
}

int main()
{
	ll n,target;
	cin>>n>>d;
	vll nums(n);
	for (ll i=0;i<n;i++)
		cin>>nums[i];
	cout<<findTargetSumWays(nums,target);
	return 0;
}
