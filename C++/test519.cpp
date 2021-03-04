#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k,l;
		
		cin>>n>>k>>l;
		
		int d[n];
		for(int i=0;i<n;i++)
			cin>>d[i];
			
		bool flag[n]={0};
		int max_t[n];
		
		bool not_poss=0;
		
		for(int i=0;i<n;i++)
		{
			if(d[i]>l)
			{
				not_poss=1;
				break;
			}
			else
			{
				max_t[i]=l-d[i];
			}
		}
		
		if(not_poss)
		{
			cout<<"No"<<endl;
		}
		else
		{
			int start=-k;
			
			for(int i=0;i<n;i++)
			{
				if(max_t[i]>=k)
				{
					start=-k;
				}
				else if(max_t[i]<start+1)
				{
					not_poss=1;
					break;
				}
				else
				{
					start++;
					
					if(start<-max_t[i])
						start=-max_t[i];
				}
			}
			
			if(not_poss)
			{
				cout<<"No"<<endl;
			}
			else
			{
				cout<<"Yes"<<endl;
			}
		}
	}
	return 0;
}
