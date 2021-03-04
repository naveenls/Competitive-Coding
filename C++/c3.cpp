#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		/*
		int arr[26]={0};
		for(int i=0;i<s.size();i++)
		{
			arr[s[i]-'a']++;
		}
		*/
		vector<string> v(k);
		for(int i=0;i<k;i++)
		{
			v[i]=""+s[i];
		}
		bool flag=0;
		for(int i=1;i<k;i++)
		{
			if(s[i]!=s[i-1])
			{
				flag=1;
				break;	
			}	
		}
		if(flag)
		{
			cout<<s[k-1]<<endl;
		}
		else
		{
			bool flag1=0;
			for(int i=k+1;i<n;i++)
			{
				if(s[i]!=s[i-1])
				{
					flag1=1;
					break;
				}
			}
			if(flag1)
			{
				cout<<v[0]+s.substr(k,n-k)<<endl;
			}
			else
			{
				int p=(n-1)/k;
				while(p--)
				{
					v[0]+=v[k];
				}
				cout<<v[0]<<endl;
			}
		}
	}
	return 0;
}
