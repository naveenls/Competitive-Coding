#include<bits/stdc++.h>
using namespace std;

int main()
{
    
	int n,k;
	cin>>n>>k;
	int arr[n];
	bool ispossible[k]={0};
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr[i]=arr[i]%k;
		ispossible[arr[i]]=1;
	}
	ispossible[0]=1;
	
	for (int i = 0; i < k; ++i) { 
        int val = i; 
  		

        if (!ispossible[val]) 
            continue; 
  		
        for (int j = 0; j + val < k; ++j) 
            if (ispossible[j]) 
                ispossible[j + val] = 1; 
    } 
    int cnt=0;
    for(int i=0;i<k;i++)
    {
    	if(ispossible[i])
			cnt++;	
	}
	cout<<cnt<<endl;
	for(int i=0;i<k;i++)
    {
    	if(ispossible[i])
			cout<<i<<' ';
	}
	return 0;
}
