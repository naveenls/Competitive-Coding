#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &a, int size) 
{ 
    int max_so_far = 0, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 		
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

int main()
{
	int n;
	cin>>n;
	
	string s,t;
	cin>>s>>t;
	
	vector<int> a,b;
	
	int cnt1=0,cnt2=0;
	for(int i=0;i<s.size();i++)
	{
		cnt1+=s[i]-'0';
		cnt2+=t[i]-'0';
		if(s[i]!=t[i])
		{
			a.push_back(s[i]-'0');
			b.push_back(t[i]-'0');		
		}
	}
	
	if(cnt1!=cnt2)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==0)
			a[i]=-1;
	}
	
	int ma=maxSubArraySum(a,a.size());
	
	for(int i=0;i<a.size();i++)
		a[i]*=-1;
		
	cout<<max(ma,maxSubArraySum(a,a.size()))<<endl;
	return 0;
}
