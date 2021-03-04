#include<bits/stdc++.h>
using namespace std;

string f_ans;

bool check(int n,string temp,int val)
{
	for(int j=temp.size()-1;j>=0;j--)
	{	
		//cout<<val<<' '<<n<<' '<<temp[j]<<endl;
		if(val<n && temp[j]!='9')
		{
			f_ans=temp;
			f_ans[j]=temp[j]+1;
			
			n-=(val+1);
			
			for(int p=j+1;p<temp.size();p++)
			{
				f_ans[p]='0';
			}
			
			int k=temp.size()-1;
			
			while(n)
			{
				f_ans[k]='0'+min(n,9);
				n-=min(n,9);
				k--;
			}
			
			return true;
		}
		
		val-=(temp[j]-'0');
	}
	return false;
}

bool check1(int n,string temp)
{
	f_ans=temp;

	int k=temp.size()-1;
	while(k>=0 && n)
	{
		if(f_ans[k]=='9')
		{
			k--;	
		}
		else
		{
			f_ans[k]++;
			n--;	
		}
	}
	
	if(n==0)
		return true;
		
	return false;
}
int main()
{
	int n;
	cin>>n;
	
	int b[n];
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	
	string ans[n];
	
	ans[0]="";
	
	int temp=b[0];
	
	while(temp)
	{		
		char c='0'+min(temp,9);
		
		ans[0].push_back((char)('0'+min(temp,9)));
		
		temp-=min(temp,9);
	}
	
	sort(ans[0].begin(),ans[0].end());
		
	//cout<<ans[0]<<endl;
	
	for(int i=1;i<n;i++)
	{
		if(b[i]>b[i-1])
		{
			//cout<<"hi"<<endl;
			if(check1(b[i]-b[i-1],ans[i-1]))
			{
				ans[i]=f_ans;
			}
			else
			{
				int len=ans[i-1].size()+1;
				
				while(9*len<b[i])
				{
					len++;
				}
				
				ans[i]="";
				for(int j=0;j<len;j++)
				{
					ans[i].push_back('0');
				}
				len--;
				ans[i][0]='1';
				
				int tt=b[i]-1;
				while(tt)
				{
					if(ans[i][len]=='9')
						len--;
					else
					{
						ans[i][len]++;
						tt--;	
					}	
				}
			}
		}
		else
		{
			if(check(b[i],ans[i-1],b[i-1]))
			{
				ans[i]=f_ans;
			}
			else
			{
				int len=ans[i-1].size()+1;

				ans[i]="";
				for(int j=0;j<len;j++)
				{
					ans[i].push_back('0');
				}
				
				len--;
				ans[i][0]='1';
				
				int tt=b[i]-1;
				while(tt)
				{
					if(ans[i][len]=='9')
						len--;
					else
					{
						ans[i][len]++;
						tt--;	
					}	
				}
			}	
		}
	}
	
	for(int i=0;i<n;i++)
	{
		//cout<<b[i]<<' ';
		cout<<ans[i]<<endl;
	}
	return 0;
}
