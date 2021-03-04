#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	int freq[k+1]={0};
	int freq1[k+1]={0};
	int arr[n];
	int c[k+1];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		freq[arr[i]]++;
	}
	freq1[n]=freq[n];
	for(int i=n-1;i>=1;i++)
	{
		freq1[i]+=freq1[i+1];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[k];
	}
	int sub=0;
	int sum=0;
	int count=0;
	vector< vector<int> > ans;
	vector<int> val;
	
	for(int i=k;i>=1;i--)
	{
		if(!freq[i])
		{
			if(freq1[i]-sub>c[k])
			{
				int temp=c[k];
				while(temp)
				{
					val.push_back(i);
					temp--;
					freq1[i]--;
					sum++;
				}
				sub+=sum;
				ans.push_back(val);
				val.clear();
				i++;
			}
			else
			{
				while(freq[i]!=0)
				{
					val.push_back(i);
					freq[i]--;
				}
				sum+=freq[i];
			}
		}
	}
	return 0;
}
