#include<bits/stdc++.h>
using namespace std;

int n;
const int maxN=3*1e5+20;
long long arr[maxN];

long long Sparse[maxN][20]={0};
long long min_val[maxN][20];

void BuildTable()
{        
        for(int i=0;i<n;i++)
        {
        	Sparse[i][0]=arr[i];
		}
		for(int j=1;j<20;j++)
		{
			for(int i=0; i+(1<<j)<=n;i++)
			{
				Sparse[i][j]=__gcd(Sparse[i][j-1],Sparse[i+(1<<(j-1))][j-1]);
			}
		}
}

void BuildTableMin()
{        
        for(int i=0;i<n;i++)
        {
        	min_val[i][0]=arr[i];
		}
		for(int j=1;j<20;j++)
		{
			for(int i=0; i+(1<<j)<=n;i++)
			{
				min_val[i][j]=min(min_val[i][j-1],min_val[i+(1<<(j-1))][j-1]);
			}
		}
}

long long get_gcd(int l,int r)
{
	long long res=0;
	for(int j=19;j>=0;j--)
	{
		if((1<<j)<=r-l+1)
		{
			res=__gcd(res,Sparse[l][j]);
			l+=(1<<j);
		}
	}
	return res;
}

long long get_min(int l,int r)
{
	long long res=1e18;
	for(int j=19;j>=0;j--)
	{
		if((1<<j)<=r-l+1)
		{
			res=min(res,min_val[l][j]);
			l+=(1<<j);
		}
	}
	return res;
}

bool check(int len)
{	
	for(int i=0;i<n-len+1;i++)
	{
		int j=i+len-1;

		if(get_gcd(i,j)==get_min(i,j))
		{
			return true;
		}
	}
	return false;
}

void find_all(int len)
{
	//cout<<len<<endl;
	vector<int> pos;

		
	for(int i=0;i<n-len+1;i++)
	{
		int j=i+len-1;

		if(get_gcd(i,j)==get_min(i,j))
		{
			pos.push_back(i);
		}
	}
	cout<<pos.size()<<' '<<len-1<<endl;
	for(auto ele:pos)
	{
		cout<<ele+1<<' ';
	}
}

int main()
{
	    ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	    cout.tie(NULL);
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>arr[i];
		

	BuildTable();
	BuildTableMin();
	int l=1;
	int r=n;
	
	int ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	find_all(ans);
	
	return 0;
}
