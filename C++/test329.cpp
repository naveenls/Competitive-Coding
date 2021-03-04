#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[15]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	
	int x1=-1;
	int x2=-1;
	
	string s;
	
	for(int i=0;i<15;i++)
	{
		cout<<arr[i]<<endl;
		cin>>s;
		
		if(s=="yes")
		{
			if(x1==-1)
				x1=arr[i];
			else if(x2==-1)
				x2=arr[i];
		}
	}
	
	if(x2!=-1)
	{
		cout<<"composite"<<endl;
		return 0;
	}
	
	if(x1==-1)
	{
		cout<<"prime"<<endl;
		return 0;
	}
	
	int temp=x1;
	temp*=x1;
	
	bool flag=0;
	
	while(temp<=100)
	{
		cout<<temp<<endl;
		
		cin>>s;
		if(s=="yes")
		{
			flag=1;
			break;
		}
		temp*=x1;
	}
	
	if(flag)
	{
		cout<<"composite"<<endl;
	}
	else
	{
		cout<<"prime"<<endl;
	}
	return 0;
}
