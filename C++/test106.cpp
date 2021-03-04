#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,m,s;
   cin>>n>>m>>s;
   int arr[m]={0};
   int ma=0;
   for(int i=1;i<=m;i++)
   {
   		int left=-(i-1)/s;
   		int right=(m-i)/s;
   		arr[i]=right-left+1;
   		ma=max(ma,arr[i]);
   }
   long long cnt1=0;
   for(int i=1;i<=m;i++)
   {
   		if(arr[i]==ma)
   		{
   			cnt1++;	
		}
   }
   
   arr[m]={0};
   ma=0;
   for(int i=1;i<=n;i++)
   {
   		int left=-(i-1)/s;
   		int right=(n-i)/s;
   		arr[i]=right-left+1;
   		ma=max(ma,arr[i]);
   }
   long long cnt2=0;
   for(int i=1;i<=m;i++)
   {
   		if(arr[i]==ma)
   		{
   			cnt2++;	
		}
   }
   cout<<cnt1*cnt2<<endl;
}




