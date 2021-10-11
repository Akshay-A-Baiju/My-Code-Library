//binary exponentiation - recursive
//TC: O(log(b))

const ll M = 1e9+7;

ll binExpRecurr(ll a, ll b)
{
	if (b==0)
		return 1;
	a=a%M;
	ll pw=binExpRecurr(a,b/2);
	pw=(pw*pw)%M;
	if (b&1)
		return (pw*a)%M;
	else
		return pw;	
}
