#include<bits/stdc++.h>
using namespace std;

int N;

int cnt(int arr[])
{
	int ans = 0;
	
	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			bool flag = 1;
			
			for(int k=i;k<=j;k++)
			{
				if(arr[k] != arr[j-k+i])
					flag = 0;
			}
			
			ans += flag;
		}
	}
	
	return ans;
}

int main()
{
	for(int nn=1;nn<=16;nn++)
	{
		N = nn;
		
		int arr[N];
	
	int min_ans = 100000;
	int mask = (1<<N);
	
	for(int i=0;i<mask;i++)
	{		
		for(int j=0;j<N;j++)
			arr[j] = (i & (1<<j))>0;
				
		min_ans = min(min_ans, cnt(arr));
		
		if(min_ans == 6)
		{
			for(int j=0;j<N;j++)
				cout<<arr[j]<<' ';
			
			cout<<endl;
		}
	}
	cout<<min_ans<<endl;
	}
	
	
	return 0;
}
