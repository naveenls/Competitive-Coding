#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

bool check(long long x)
{
	vector<int> zeros;
	
	int dig = 0;
	while(x)
	{
		if(x%2 == 1){
			zeros.push_back(dig);
		}
		dig++;
		x/=2;
	}
	
	reverse(zeros.begin(),zeros.end());

	for(int i=0;i+1<zeros.size();i+=2)
		if(zeros[i] - 1 != zeros[i+1])
			return false;

	if(zeros.size()%2 && zeros.back() != 0)
		return false;
	
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,l;
	cin>>n>>l;
	
	vector<pair<int,int> > v(l);
	
	int next[n+1];
	memset(next,-1,sizeof(next));
	
	int a,b;
	for(int i=0;i<l;i++)
	{
		cin>>a>>b;
	//	a--,b--;
		
		v[i].first = a;
		v[i].second = b;
		
		next[a] = b;
	}
	
	long long ways_left[n+1] = {0};
	long long ways_right[n+1];
	
	ways_left[0] = 1;
	
	for(int i=0;i<n;i++)
	{
		if(next[i]!=-1)
			ways_left[next[i]] = (ways_left[next[i]] + ways_left[i])%mod;
		else
		{
			for(int j=1;(j<=6) && (i+j<=n);j++){
				ways_left[i+j] = (ways_left[i+j] + ways_left[i])%mod;
			}
		}
	}
		
	ways_right[n] = 1;
	
	for(int i=n-1;i>=0;i--)
	{
		ways_right[i] = 0;
		
		if(next[i]!=-1)
			ways_right[i] = (ways_right[i] + ways_right[next[i]])%mod;
		else
		{
			for(int j=1;(j<=6) && (i+j<=n);j++){
				ways_right[i] = (ways_right[i] + ways_right[i+j])%mod;
			}
		}
	}
	
	for(int i=0;i<l;i++){
		cout<<ways_left[v[i].first]*ways_right[v[i].second]%mod<<endl;
	}
	
	return 0;
}

