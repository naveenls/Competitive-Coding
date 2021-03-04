#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+3;

int main()
{
	string s;
	cin>>s;
	
	int n=s.size();
	int arr[n];
	
	vector<int> v(26);
	string temp;
	cin>>temp;
	for(int i=0;i<26;i++)
	{
		if(temp[i]=='0')
			v[i]=0;
		else
			v[i]=1;
	}
	
	int k;
	cin>>k;
	
	for(int i=0;i<s.size();i++)
	{
		arr[i]=1-v[s[i]-'a'];
	}
	int ans=0;
	
	for(int l=1;l<=n;l++)
	{
		unordered_set<long long> ss;
		long long pp=0;
		int tt=0;
		
		long long power=1;
		
		for(int i=0;i<l-1;i++)
			power=power*26%mod;
			
		for(int i=0;i<l;i++)
		{
			tt+=arr[i];
			pp=((pp*26)%mod+s[i]-'a'+1)%mod;
		}
		//cout<<pp<<"hi"<<power<<endl;
		if(tt<=k)
			ss.insert(pp);
			
		for(int i=0;i<n-l;i++)
		{
			int j=i+l;
			tt+=(arr[j]-arr[i]);
			pp=(pp-power*(s[i]-'a'+1)%mod +mod)%mod;
			//cout<<pp<<' '<<l<<endl;
			pp=((pp*26)%mod+s[j]-'a'+1)%mod;
			
			if(tt<=k)
			{
				ss.insert(pp);
			}
		}
		//cout<<ss.size()<<endl;
		ans+=ss.size();
	}

	cout<<ans<<endl;
	return 0;
}
