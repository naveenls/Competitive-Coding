#include<bits/stdc++.h>
using namespace std;


void updateBIT(int BITree[],int n, int index, int val) 
{ 
  
    while (index <= n) 
    { 
        BITree[index] += val; 
  
        index += index & (-index); 
    } 
} 
  
int *constructBITree(int n) 
{ 

    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 

    return BITree; 
} 

int getSum(int BITree[], int index) 
{ 
    int sum = 0;
    
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n+1];
		int a;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			arr[a]=i;
		}
		int *BITree = constructBITree(n); 
		int cnt=0;
		vector<pair<int,int> > ops;
		for(int i=1;i<=n;i++)
		{
			int ind=arr[i]+getSum(BITree,arr[i]);
			//cout<<i<<' '<<ind<<endl;
			ind=min(n,ind);
			if(i!=ind)
			{
				//cout<<i<<endl;
				ops.push_back({i,ind});
				ops.push_back({i+1,ind});
				update(BITree,1,ind-1,n,1);
			}
		}
		cout<<ops.size()<<endl;
		for(int i=0;i<ops.size();i++)
		{
			cout<<ops[i].first<<' '<<ops[i].second<<endl;
		}
	}
	return 0;
}
