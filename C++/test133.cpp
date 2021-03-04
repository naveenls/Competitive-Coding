#include<bits/stdc++.h>
using namespace std;

void calculate_lp_string(int lps[],string s)
{
    lps[0]=0;
    int len=0;
    
    for(int i=1;i<s.size();i++)
    {
        while(len!=0 && s[i]!=s[len])
        {
            len=lps[len-1];
        }
        
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
        }
        else
        {
            lps[i]=0;
        }
    }
    
}

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	
	int lps[n];
	calculate_lp_string(lps,s);
	
	vector<int> ans;
	
	int temp=lps[n-1];
	
	while(temp!=0)
	{
		ans.push_back(temp);
		temp=lps[temp-1];
	}
	
	int DP[n]={0};
	int arr[n];
	
	memset(arr,-1,sizeof(arr));
	for(int i=0;i<n;i++)
	{
		DP[lps[i]]++;
		arr[lps[i]]=i;
	}
	
	for(int i=n-1;i>0;i--)
	{
		if(DP[i])
		{
			int temp=lps[arr[i]]-1;
			DP[lps[temp]]+=DP[i];
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		cout<<DP[i]<<' ';
	}
	cout<<endl;
	*/
	vector<pair<int,int> > v;
	for(auto ele:ans)
	{
		v.push_back({ele,DP[ele]+1});
	}
	v.push_back({n,1});
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(auto ele: v)
	{
		cout<<ele.first<<' '<<ele.second<<endl;
	}
	return 0;
}
