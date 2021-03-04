#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   if(n%2==0)
   {
   		for(int i=1;i<=n/2;i++)
   		{
   			cout<<2*i<<' '<<2*i-1<<' ';	
		}
		cout<<endl;
   }
   else
   {
   		cout<<1<<' ';
   		for(int i=1;i<=n/2;i++)
   		{
   			cout<<2*i+1<<' '<<2*i<<' ';	
		}
		cout<<endl;
   }
}




