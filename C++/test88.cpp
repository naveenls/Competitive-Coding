#include<bits/stdc++.h>
using namespace std;

int find(int i,int par[])
{
	if(par[i]==i)
	{
		return i;
	}
	par[i]=find(par[i],par);
	return par[i];
}
int main(){
    string s;
    cin>>s;
    
    int freq[26]={0};
    for(int i=0;i<s.size();i++)
    {
    	freq[s[i]-'a']++;
	}
	
    int n=s.size();
    bool mark[n+1]={0};
    
    int cnt=n;
    cnt--;
    
    for(int i=2;i<=n;i++)
    {
    	if(!mark[i])
    	{
    		int j=2*i;
    		while(j<=n)
    		{
    			mark[j]=1;
    			j+=i;
			}
		}
	}
	for(int i=3;i<=n;i++)
	{
		if(!mark[i] && i*2>n)
		{
			cnt--;
		}
	}
	int ind=-1;
	for(int i=0;i<26;i++)
	{
		if(freq[i]>=cnt)
		{
			ind=i;
			freq[i]-=cnt;
			break;	
		}
	}
	if(ind=-1)
	{
		cout<<"NO";
		return 0;
	}
	char ans[n+1];
	for(int i=2;i<=n;i++)
	{
		if(mark[i] || (!mark[i] && i*2<=n))
		{
			ans[i]='a'+ind;
		}
	}
	vector<char> v;
	for(int i=0;i<26;i++)
	{
		while(freq[i])
		{
			freq[i]--;
			v.push_back('a'+i);
		}
	}
	
	int j=0;
	for(int i=1;i<=n;i++)
	{
		if(!mark[i] && i*2>n)
		{
			ans[i]=v[j];
			j++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[j];
	}
    return 0;
}
