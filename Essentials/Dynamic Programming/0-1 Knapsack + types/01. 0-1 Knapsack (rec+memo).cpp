#include<bits/stdc++.h>
using namespace std;
#define ll		long long
#define vll		vector <ll>
const ll N = 100;
const ll W = 1000;

ll tab[N+1][W+1];		            //initialize all elements to -1

ll Knapsack(vll &wt, vll &val, ll k, ll n)
{
	if (n==0 || k==0)	            //base condition, if n=0 or k=0, profit=0
		return 0;
	if (tab[n][k]!=-1)
		return tab[n][k];
	if (wt[n]<=k)		              //if wt[n]<=k, 2 choice include or not include
		return tab[n][k]=max(val[n]+Knapsack(wt,val,k-wt[n],n-1),Knapsack(wt,val,k,n-1));
	else				                  //if wt[n]>k, only choice is to exclude wt[n]
		return tab[n][k]=Knapsack(wt,val,k,n-1);
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
    memset(tab,-1,sizeof(tab));
    cout<<Knapsack(wt,val,k,n);
    return 0;
}
