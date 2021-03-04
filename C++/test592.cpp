#include<bits/stdc++.h>
using namespace std;

const int n = 32000;
vector<bool> is_prime(n+1, true);

void set_primes()
{
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}
}

int main()
{
	set_primes();
	set<int> primes;
	
	for(int i=2;i<=100;i++)
		if(is_prime[i])
			primes.insert(i);
			
	int t;
	cin>>t;
	
	while(t--)
	{
		long long l,r;
		cin>>l>>r;
		
		int len = r-l+1;
		
		int arr[len];
		int cnt[len] = {0};
		
		for(int i=l;i<=r;i++)
			arr[i-l] = i;
		
		for(long long i=2;i<=n;i++)
		{
			if(is_prime[i])
			{
				for(long long j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
				{
					while(arr[j-l]%i == 0)
						arr[j-l]/=i, cnt[j-l]++;
				}
			}
		}
		
		int ans = 0;
		for(int i=0;i<len;i++)
		{
			if(arr[i]>1)
				cnt[i]++;
			
			if(primes.find(cnt[i]) != primes.end()){
				ans++;
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
