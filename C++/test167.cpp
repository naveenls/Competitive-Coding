#include<bits/stdc++.h>
using namespace std;

vector<int> v[27];
long long sum[27];

void clear_all()
{
	for(int i=0;i<27;i++)
	{
		v[i].clear();
		sum[i]=0;
	}
}

int main()
{
	string s;
	cin>>s;
	
	long long n=s.size();
	
	long long k;
	cin>>k;
	
	if(k>n*(n+1)/2)
	{
		cout<<"No such line."<<endl;
		return 0;
	}
	
	set<int> ss;
	for(int i=0;i<n;i++)
	{
		ss.insert(i);
	}
	int len=0;
	
	string ans="";
	
	while(k)
	{
		clear_all();
		
		sum[0]= len ? ss.size() : 0;
		
		for(auto i:ss)
		{
			if(i+len<n)
			{
				v[s[i+len]-'a'+1].push_back(i);
				sum[s[i+len]-'a'+1]+=(n-i-len);	
			}
		}
		
		long long presum=0;
		int ind=-1;
		
		for(int i=0;i<27;i++)
		{
			presum+=sum[i];
			if(presum>=k)
			{
				ind=i;
				break;
			}
		}
		
		ans.push_back(ind+'a'-1);
		presum-=sum[ind];
		
		k-=presum;
					
		for(int i=0;i<27;i++)
		{
			if(i!=ind)
			{
				for(auto ele:v[i])
					ss.erase(ele);
			}
		}
		len++;	
	}
	cout<<ans<<endl;
	return 0;
}
