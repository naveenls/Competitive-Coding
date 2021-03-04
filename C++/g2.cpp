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
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.size();
		int LPS[n];
		calculate_lp_string(LPS,s);
		int LPSR[n];
		reverse(s.begin(),s.end());
		calculate_lp_string(LPSR,s);
		
		int cnt=0;
		for(int i=1;i<n-2;i+=2)
		{
			if(LPS[i]>=(i+1)/2 && LPSR[n-i-2]>=(n-i-1)/2)
			{
				int temp1=(i+1)/2;
				int temp=LPS[i]-temp1;
				
				int temp3=(n-i-1)/2;
				int temp4=LPSR[n-i-2]-temp3;
								
				temp=temp1-temp;
				temp4=temp3-temp4;
				
				if((temp1)%temp==0 && (temp3)%temp4==0)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
