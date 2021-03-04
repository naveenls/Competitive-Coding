#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int m;
bool find(int i,int l_sum,int r_sum,int no,int value[])
{
	if(i==m)
		return true;
	
	for(int j=0;j<v.size();j++)
	{
		if(v[j]!=no)
		{
			if(i%2==0)
			{
				if(l_sum+v[j]>r_sum)
				{
					if(find(i+1,l_sum+v[j],r_sum,v[j],value))
					{
						value[i]=v[j];
						return true;
					}
				}
			}
			else
			{
				if(l_sum<r_sum+v[j])
				{
					if(find(i+1,l_sum,r_sum+v[j],v[j],value))
					{
						value[i]=v[j];
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	char c;
	for(int i=1;i<=10;i++)
	{
		cin>>c;
		if(c=='1')
		{
			v.push_back(i);
		}
	}
	cin>>m;
	int value[m];
	if(find(0,0,0,-1,value))
	{
		cout<<"YES"<<endl;
		for(int i=0;i<m;i++)
			cout<<value[i]<<' ';
			
	}
	else
	{
		cout<<"NO";
	}
}
