#include <bits/stdc++.h>
using namespace std;

const int maxVAL=2*1e5;

vector<int> t1[maxVAL];
vector<int> t2[maxVAL];

long long arr[maxVAL];

long long p1[maxVAL];
long long p2[maxVAL];

int inT1[maxVAL];
int outT1[maxVAL];

int inT2[maxVAL];
int outT2[maxVAL];

int size1[maxVAL];
int size2[maxVAL];

int in_time=0;

int dfs(int i,long long value,bool flag)
{
	if(flag)
	{
		inT2[i]=++in_time;
		
		p2[i]=arr[i]+value;
		
		for(auto ch:t2[i])
		{
			size2[i]+=dfs(ch,p2[i],flag);
		}
		
		outT2[i]=++in_time;
		
		size2[i]++;
		return size2[i];
	}
	else
	{

		inT1[i]=++in_time;
		p1[i]=arr[i]+value;
		
		for(auto ch:t1[i])
		{
			size1[i]+=dfs(ch,p1[i],flag);
		}
		
		outT1[i]=++in_time;
		
		size1[i]++;
		return size1[i];
	}
}

void updateBIT(long long BITree[], int n, int index, long long val) 
{ 
    index = index + 1; 
	  
    while (index <= n) 
    { 
        BITree[index] += val;   
        index += index & (-index); 
    } 
} 

long long getSum(long long BITree[], int index) 
{ 
    long long sum = 0;  
    index = index + 1; 
	  
    while (index>0) 
    { 
        sum += BITree[index];   
        index -= index & (-index); 
    }
    
    return sum; 
} 

void update(long long BITree[], int l, int r, int n, long long val) 
{ 
    updateBIT(BITree, n, l, val);   
    updateBIT(BITree, n, r+1, -val); 
} 

void find_right(int rr[],int n,int arr[])
{
	stack<int> s;
	
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && arr[s.top()]<arr[i])
		{
			rr[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
}

void find_left(int ll[],int n,int arr[])
{
	stack<int> s;
	for(int i=n-1;i>=0;i--)
	{
		while(!s.empty() && arr[s.top()]<arr[i])
		{
			ll[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
}

int main() {
	int n,q;
	cin>>n>>q;
	
	int height[n];

	for(int i=0;i<n;i++)
	{
	    cin>>height[i];
	}
	
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	
	int rr[n];
	int ll[n];

    memset(rr,-1,sizeof(rr));
    memset(ll,-1,sizeof(ll));
    
	find_right(rr,n,height);
	find_left(ll,n,height);
	
	int outD[n]={0},outD1[n]={0};

	for(int i=0;i<n;i++)
	{
		if(rr[i]!=-1)
		{
			t1[rr[i]].push_back(i);
			outD[i]++;
		}
		
		if(ll[i]!=-1)
		{
			t2[ll[i]].push_back(i);
			outD1[i]++;
		}
	}

	for(int i=0;i<n;i++)
	{
		if(!outD[i])
		{
			dfs(i,0,0);
		}
		if(!outD1[i])
		{
			dfs(i,0,1);
		}
	}

	vector<pair<int,int> > vec1(n),vec2(n);
	
	for(int i=0;i<n;i++)
	{
		vec1[i]=make_pair(inT1[i],i);
		vec2[i]=make_pair(inT2[i],i);
	}

	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	
	map<int,int> mp1,mp2;
	
	long long temp[n];
	
	for(int i=0;i<n;i++)
	{		
		temp[i]=p1[vec1[i].second];
		mp1[vec1[i].second]=i;
	}
	
	long long bitTree1[n+1];
		
	for (int i=0; i<=n; i++) 
        bitTree1[i] = 0; 
  
    for (int i=0; i<n; i++) 
    {
        updateBIT(bitTree1, n, i, temp[i]); 
        updateBIT(bitTree1, n, i+1, -temp[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		temp[i]=p2[vec2[i].second];
		mp2[vec2[i].second]=i;
	}
	
	long long bitTree2[n+1];
	
	for (int i=0; i<=n; i++) 
        bitTree2[i] = 0; 
  
    for (int i=0; i<n; i++) 
    {
        updateBIT(bitTree2, n, i, temp[i]); 
        updateBIT(bitTree2, n, i+1, -temp[i]);
	}

	int left,right;
	int typ;
	long long x;

	while(q--)
	{
		cin>>typ;
		
		if(typ==1)
	   {
	        cin>>left>>x;
	        left--;
	        
	        update(bitTree1,mp1[left],mp1[left]+size1[left]-1,n,x-arr[left]);
	        update(bitTree2,mp2[left],mp2[left]+size2[left]-1,n,x-arr[left]);
	        
	        arr[left]=x;
	   }
	   else
	   {
	       cin>>left>>right,left--,right--;
	       
	       if(right<left)
	       {
	           if(inT1[left]<=inT1[right] && outT1[left]>=outT1[right])
	           {
	           		cout<<getSum(bitTree1,mp1[right])-getSum(bitTree1,mp1[left])+arr[left]<<endl;
			   }
			   else
			   {
			   		cout<<-1<<endl;
			   }
	       }
	       else
	       {
	           if(inT2[left]<=inT2[right] && outT2[left]>=outT2[right])
	           {
	           		cout<<getSum(bitTree2,mp2[right])-getSum(bitTree2,mp2[left])+arr[left]<<endl;
			   }
			   else
			   {
			   		cout<<-1<<endl;
			   }
	       }
		}
	}

	return 0;
}

