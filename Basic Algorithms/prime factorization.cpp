//prime factorization
//TC: O(sqrt(n))

void primeFact(ll n)
{
	for (ll i=2;i*i<=n;i++)
	{
		if (n%i==0)
		{
			ll count=0;
			while (n%i==0)
			{
				n/=i;
				count++;
			}
			cout<<i<<"^"<<count<<" ";
		}
	}
	if (n>1)
		cout<<n<<"^"<<1;
}
