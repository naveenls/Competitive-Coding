#include<bits/stdc++.h>
using namespace std;

set<long long> ss;

bool check(int n,int k,int start,int f_bit)
{
	int arr[k+1][start+2];
	
	for(int j=0;j<=k;j++)
	{		
		for(int i=1;i<=start;i++)
		{
			arr[j][i]=9;
		}
		arr[j][start+1]=0;
	}
	
	bool flag=0;
	
	for(int i=0;i<=k;i++)
	{
		arr[i][0]=(f_bit+i);
		if(arr[i][0]>=10)
		{
			arr[i][0]%=10;
			flag=1;
			
			for(int j=1;j<=start+1;j++)
			{
				if(arr[i][j]==9)
					arr[i][j]=0;
				else
					arr[i][j]=1;
			}
		}
	}
	
	int sum=0;
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=start+1;j++)
		{
			sum+=arr[i][j];
		}
	}

	if(sum>n)
	{
		return false;	
	}
	
	if((n-sum)%(k+1)==0)
	{
		int temp=(n-sum)/(k+1);
		
		vector<int> ans;
		
		long long k=0;
		
		if(flag)
		{
			if(temp<9)
			{
				ans.push_back(temp);
			}
			else
			{
				ans.push_back(8);
				temp-=8;
				
				while(temp)
				{
					ans.insert(ans.begin(),min(temp,9));
					temp-=min(temp,9);	
				}
			}
			for(auto ele:ans)
			{
				k=k*10+ele;
			}
			
			for(int i=start;i>=0;i--)
			{
				k=k*10+arr[0][i];
			}
		}
		else
		{
			while(temp)
			{
				ans.push_back(min(temp,9));
				temp-=min(temp,9);				
			}
			
			sort(ans.begin(),ans.end());
			
			for(auto ele:ans)
			{
				k=k*10+ele;
			}
			for(int i=start;i>=0;i--)
			{
				k=k*10+arr[0][i];
			}
		}
		ss.insert(k);
		
		return true;
	}
	return false;
}
void solve(int n,int k)
{
	int start=0;
	
	while(start<=16)
	{
		for(int f_bit=0;f_bit<=9;f_bit++)
		{
			check(n,k,start,f_bit);
		}
		start++;
	}
	if(ss.size()==0)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<*ss.begin()<<endl;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		
		cin>>n>>k;
		ss.clear();
		
		if(k==0)
		{
			int temp=n;
			
			vector<int> ans;
			
			while(temp)
			{
				ans.push_back(min(temp,9));
				temp-=min(temp,9);
			}
			sort(ans.begin(),ans.end());
			for(auto ele:ans)
				cout<<ele;
			
			cout<<endl;
		}
		else
			solve(n,k);
	}
	return 0;
}
