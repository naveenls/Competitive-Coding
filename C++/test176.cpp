#include<bits/stdc++.h>
using namespace std;

multiset<long long> small,big;
long long sum=0;
int k;

void insert(long long a)
{
	small.insert(a);
	sum+=a;
	if(small.size()>k-1)
	{
		auto itr=small.begin();
		big.insert(*itr);
		sum-=*itr;
		
		small.erase(itr);
	}
	//cout<<sum<<' '<<small.size()<<endl;
}

void remove(long long a)
{
	if(small.find(a)==small.end())
	{	
		big.erase(big.find(a));
	}
	else
	{
		sum-=a;
		small.erase(small.find(a));
		
		long long val=*big.rbegin();
		small.insert(val);
		sum+=val;
		
		big.erase(big.find(val));
	}
	//cout<<sum<<endl;
}

int main()
{
	int n;
	cin>>n>>k;
	
	long long b;
	cin>>b;
	
	long long arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		insert(arr[i]);
	}
	for(int i=0;i<n+10;i++)
		big.insert(0);
		
	remove(arr[n-1]);
	for(int i=0;i<n-1;i++)
	{
		remove(arr[i]);
		
		//cout<<sum<<endl;
		if(sum>b-arr[i])
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
}
