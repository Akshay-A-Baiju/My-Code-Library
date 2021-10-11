//primality test
//TC: O(sqrt(n))

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(ll n)
{
	if (n==1)
		return false;
	for (ll i=2;i*i<=n;i++)
	{
		if (n%i==0)
			return false;
	}
	return true;
}

int main()
{
	ll n;
	cin>>n;
	if (isPrime(n))
		cout<<"Prime number";
	else
		cout<<"Composite number";
	return 0;
}
	
