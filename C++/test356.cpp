#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int arr[2*n-1];
		int brr[2*n-1];
		
		vector<pair<long long,int> > a(2*n-1);
		vector<pair<long long,int> > b(2*n-1);
		
		long long sum1=0,sum2=0;
		
		for(int i=0;i<2*n-1;i++)
		{
			cin>>a[i].first>>b[i].first;
			
			arr[i]=a[i].first;
			brr[i]=b[i].first;
			
			sum1+=a[i].first;
			sum2+=b[i].first;
			
			a[i].second=i;
			b[i].second=i;
		}
		
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		
		int i=0;
		int j=0;
		
		sum1=sum1-sum1/2;
		sum2=sum2-sum2/2;
		
		set<int> s;
		
		while(s.size()<n)
		{
			if(sum1>sum2)
			{
				int ind=a[i].second;
				
				if(s.find(ind)!=s.end())
				{
					i++;
				}
				else
				{
					sum1-=a[i].first;
					sum2-=brr[ind];
					
					s.insert(ind);
					i++;
				}
			}
			else
			{
				int ind=b[j].second;
				
				if(s.find(ind)!=s.end())
				{
					j++;
				}
				else
				{
					sum1-=b[j].first;
					sum2-=arr[ind];
					
					s.insert(ind);
				}
			}
		}
	
		if(sum1>0 || sum2>0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			for(auto ele: s)
			{
				cout<<ele+1<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
