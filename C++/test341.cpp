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
	string s,t;
	cin>>s>>t;
	
	int z_s=0;
	int o_s=0;
	
	int LPS[t.size()];
	calculate_lp_string(LPS,t);
	
	int len=LPS[t.size()-1];
	
	int z_t=0;
	int o_t=0;
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
			o_s++;
		else
			z_s++;
	}
	
	for(int i=0;i<t.size();i++)
	{
		if(t[i]=='1')
			o_t++;
		else
		 	z_t++;
	}
	
	int z_t_n=0;
	int o_t_n=0;
	
	for(int i=len;i<t.size();i++)
	{
		if(t[i]=='1')
			o_t_n++;
		else
		 	z_t_n++;
	}
	
	string t_n=t.substr(len,t.size()-len);
	
	if(o_s>=o_t && z_s>=z_t)
	{
		cout<<t;
		o_s-=o_t;
		z_s-=z_t;
		
		while(o_s>=o_t_n && z_s>=z_t_n)
		{
			cout<<t_n;
			o_s-=o_t_n;
			z_s-=z_t_n;
		}
	}
	
	while(o_s--)
		cout<<1;
	while(z_s--)
		cout<<0;
		
	return 0;
}
