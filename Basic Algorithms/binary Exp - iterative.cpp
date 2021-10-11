//binary exponentiation - iterative
//TC: O(log(b))

const ll M = 1e9+7;

ll binExpIter(ll a, ll b)
{
	a=a%M;
	ll res=1;
	while (b)
	{
		if (b&1)
			res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}
