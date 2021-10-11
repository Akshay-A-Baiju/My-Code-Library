//sieve of eratosthenes
//TC: O(n*log(log(n)))

const int N = 1e6;
vector <bool> isPrime(N+1,true);

void sieveOfErato()
{
	isPrime[0]=isPrime[1]=false;
	for (ll i=2;i<=N;i++)
	{
		if (isPrime[i])
		{
			for (ll j=i*i;j<=N;j+=i)
				isPrime[j]=false;
		}
	}
}
