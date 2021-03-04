#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+1;
int arr1[maxN]={0};
int arr2[maxN]={0};

int n,winner;

vector<pair<int,int> > v;

void check(int b)
{
	int cnt1=0,cnt2=0;
	
	int s1=0;
	int s2=0;
	
	int ind,ind1;
	
	int last_ind=0;
	
	while(true)
	{
		ind=lower_bound(arr1+last_ind,arr1+n,s1+b)-arr1;
		ind1=lower_bound(arr2+last_ind,arr2+n,s2+b)-arr2;
		
		if(ind==n && ind1==n)
			break;

		if(ind<ind1)
		{
			s1=arr1[ind];
			s2=arr2[ind];
			last_ind=ind;
			
			cnt1++;
		}
		else
		{
			s1=arr1[ind1];
			s2=arr2[ind1];
			last_ind=ind1;
			
			cnt2++;
		}
	}
	
	if(winner==0)
	{
		if(last_ind==n-1 && cnt2<cnt1)
		{
			v.push_back({cnt1,b});
		}
	}
	else
	{
		if(last_ind==n-1 && cnt1<cnt2)
		{
			v.push_back({cnt2,b});
		}
	}
}

int main()
{
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			arr1[i]=1;
		else
			arr2[i]=1;
	}
	
	winner= a[n-1]-1;
	
	for(int i=1;i<n;i++)
	{
		arr1[i]+=arr1[i-1];
		arr2[i]+=arr2[i-1];
	}

	for(int t=1;t<=n;t++)
	{
		check(t);
	}
	
	sort(v.begin(),v.end());
	
	cout<<v.size()<<endl;
	for(auto ele:v)
	{
		cout<<ele.first<<' '<<ele.second<<endl;
	}
	
	return 0;
}
