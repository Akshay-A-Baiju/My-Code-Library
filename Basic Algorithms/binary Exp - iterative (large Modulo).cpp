//binary exponentiation - iterative (large Modulo)
//TC: O(log(a)*log(b))

const ll M = 1e9+7;

ll binMultiply(ll a, ll b, ll M)
{
	a=a%M;
	ll res=0;
	while (b)
	{
		if (b&1)
			res=(res+a)%M;
		a=(a+a)%M;
		b>>=1;
	}
	return res;
}

ll binExpIter(ll a, ll b, ll M)
{
	a=a%M;
	ll res=1;
	while (b)
	{
		if (b&1)
			res=binMultiply(res,a,M);
		a=binMultiply(a,a,M);
		b>>=1;
	}
	return res;
}
