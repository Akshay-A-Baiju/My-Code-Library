#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
int main()
{
	ll n;
	cin>>n;
	vll v(n);
	for (ll i=0;i<n;i++)
		cin>>v[i];
	//using Bitmasking
	ll total=(1LL<<n);
	vector <vll> subsets(total);
	for (ll mask=0;mask<total;mask++)
	{
		vll subset;
		for (ll i=0;i<n;i++)
		{
			if (mask&(1ll<<i))
				subset.push_back(v[i]);
		}
		subsets[mask]=subset;
	}
	for (ll i=0;i<total;i++)
	{
		for (ll j=0;j<subsets[i].size();j++)
			cout<<subsets[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
