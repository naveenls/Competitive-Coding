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
	int LPS[n];
	
	calculate_lp_string(LPS,s);
	reverse(s.begin(),s.end());
	
	int LPSR[n];
	calculate_lp_string(LPSR,s);
	reverse(LPSR,LPSR+n);
	int ma=0;
	
	for(int i=1;i<n-1;i++)
	{
		int temp=LPS[i];
		
		if(!temp)
			continue;
			
		int ind=i-temp+1;
		
		if(temp>=LPSR[ind])
			ma=max(ma,LPSR[ind]);
	}
	reverse(s.begin(),s.end());
	if(ma==0)
	{
		cout<<"Just a legend"<<endl;
	}
	else
	{
		cout<<s.substr(0,ma)<<endl;
	}
	return 0;
}
