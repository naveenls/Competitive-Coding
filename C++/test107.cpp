#include<bits/stdc++.h>
using namespace std;

set<string> ans;

string rotate_1(string s)
{
	string temp=s;
	temp[2]=s[1];
	temp[3]=s[2];
	temp[4]=s[3];
	temp[1]=s[4];
	return temp;
}

string rotate_2(string s)
{
	string temp=s;
	temp[1]=s[0];
	temp[3]=s[5];
	temp[0]=s[3];
	temp[5]=s[1];
	return temp;
}

string rotate_3(string s)
{
	string temp=s;
	temp[2]=s[0];
	temp[4]=s[5];
	temp[0]=s[4];
	temp[5]=s[2];
	return temp;
}
string rotate(char a[])
{
	string ans_t="";
	for(int i=0;i<6;i++)
	{
		ans_t.push_back(a[i]);
	}
	string min_val=ans_t;
	
	string temp=ans_t;	
	for(int i=0;i<6;i++)
	{
		temp=rotate_1(temp);
		min_val=min(min_val,temp);
	}
	
	temp=ans_t;	
	for(int i=0;i<6;i++)
	{
		temp=rotate_2(temp);
		min_val=min(min_val,temp);
	}
	
	temp=ans_t;	
	for(int i=0;i<6;i++)
	{
		temp=rotate_3(temp);
		min_val=min(min_val,temp);

	}
	return min_val;
}
void heapPermutation(char a[], int size, int n) 
{ 
    if (size == 1) 
    { 
  	     ans.insert(rotate(a)); 
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 

        if (size%2==1) 
            swap(a[0], a[size-1]); 
            
        else
            swap(a[i], a[size-1]); 
    } 
} 

int main()
{
	char arr[6];
	for(int i=0;i<6;i++)
		cin>>arr[i];
		
	heapPermutation(arr,6,6);
	for(auto ele:ans)
	{
		cout<<ele<<endl;
	}
	cout<<ans.size()<<endl;
	return 0;
}
