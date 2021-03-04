#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
using namespace std; 
 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    index = index + 1; 
  
    while (index <= n) 
    { 
        BITree[index] += val;   
        index += index & (-index); 
    } 
} 

int *constructBITree(int arr[], int n) 
{ 
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    for (int i=0; i<n; i++) 
    {
    	updateBIT(BITree, n, i, arr[i]); 
		updateBIT(BITree, n, i+1,-arr[i]); 	
	}

    return BITree; 
} 

int getSum(int BITree[], int index) 
{ 
    int sum = 0;  
    index = index + 1; 
 
    while (index>0) 
    {
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
 
void update(int BITree[], int l, int r, int n, int val) 
{ 
    updateBIT(BITree, n, l, val);   
    updateBIT(BITree, n, r+1, -val); 
} 

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	int cnt2[n]={0},cnt3[n]={0},cnt5[n]={0};
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
		while(arr[i]%2==0)
			cnt2[i]++,arr[i]/=2;
			
		while(arr[i]%3==0)
			cnt3[i]++,arr[i]/=3;
			
		while(arr[i]%5==0)
			cnt5[i]++,arr[i]/=5;
	
	}
	
	int* bitTree2=constructBITree(cnt2,n);
	int* bitTree3=constructBITree(cnt3,n);
	int* bitTree5=constructBITree(cnt5,n);
	
	int m;
	cin>>m;
	
	int type,l,r,a;
	
	while(m--)
	{
		cin>>type;
		if(type==1)
		{
			cin>>l>>r>>a;
			l--,r--;
			
			if(a==2)
			{
				update(bitTree2,l,r,n,-1);
			}
			else if(a==3)
			{
				update(bitTree3,l,r,n,-1);
			}
			else
			{
				update(bitTree5,l,r,n,-1);
			}
		}
		else
		{
			cin>>l>>a;
			l--;
			
			arr[l]=a;
			
			cnt2[l]=0;
			cnt3[l]=0;
			cnt5[l]=0;
			
			while(arr[l]%2==0)
				cnt2[l]++,arr[l]/=2;
			
			while(arr[l]%3==0)
				cnt3[l]++,arr[l]/=3;
			
			while(arr[l]%5==0)
				cnt5[l]++,arr[l]/=5;
				
			int c2=getSum(bitTree2,l);
			int c3=getSum(bitTree3,l);
			int c5=getSum(bitTree5,l);
			
			update(bitTree2,l,l,n,cnt2[l]-c2);
			update(bitTree3,l,l,n,cnt3[l]-c3);
			update(bitTree5,l,l,n,cnt5[l]-c5);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		int c2=getSum(bitTree2,i);
		int c3=getSum(bitTree3,i);
		int c5=getSum(bitTree5,i);
		
		cnt2[i]=max(0,c2);
		cnt3[i]=max(0,c3);
		cnt5[i]=max(0,c5);
				
		while(cnt2[i]--)
			arr[i]*=2;
		
		while(cnt3[i]--)
			arr[i]*=3;
			
		while(cnt5[i]--)
			arr[i]*=5;
			
		cout<<arr[i]<<' ';
	}
	return 0;
}
