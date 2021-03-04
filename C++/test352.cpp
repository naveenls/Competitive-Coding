#include<bits/stdc++.h>
using namespace std;

const int maxB=30;

struct node{
	node* par=NULL;
	
	int count=0;
	node* left=NULL;
	node* right=NULL;
};

node* root;

void insert_into(int i,int a[],node* n)
{
	if(i==30)
	{
		n->count++;
		return;
	}
	
	if(a[i])
	{
		if(n->right)
		{
			insert_into(i+1,a,n->right);
		}
		else
		{
			node* new_node=new node();
			new_node->par=n;
			n->right=new_node;
			
			insert_into(i+1,a,new_node);
		}
		n->count=n->right->count;
		
		if(n->left)
			n->count+=n->left->count;
	}
	else
	{
		if(n->left)
		{
			insert_into(i+1,a,n->left);
		}
		else
		{
			node* new_node=new node();
			new_node->par=n;
			n->left=new_node;
			
			insert_into(i+1,a,new_node);
		}
		n->count=n->left->count;
		
		if(n->right)
			n->count+=n->right->count;
	}
}

void delete_from(int i,int a[],node* n)
{
	if(i==30)
	{
		n->count--;
		return;
	}
	
	if(a[i])
	{
		delete_from(i+1,a,n->right);
		n->count--;
		
		if(n->right->count==0)
		{
			n->right=NULL;
		}
	}
	else
	{
		delete_from(i+1,a,n->left);
		n->count--;
		
		if(n->left->count==0)
		{
			n->left=NULL;
		}
	}
}

void insert_(int temp)
{
	int a[30];

	for(int i=0;i<30;i++)
	{
		if(temp%2)
		{
			a[29-i]=1;
		}
		else
		{
			a[29-i]=0;
		}		
		temp/=2;
	}

	insert_into(0,a,root);
}

void delete_(int temp)
{
	//cout<<temp<<endl;
	
	int a[30];
	for(int i=0;i<30;i++)
	{
		if(temp%2)
			a[29-i]=1;
		else
			a[29-i]=0;
			
		temp/=2;
	}
	
	delete_from(0,a,root);
}

int count_val(int i,int c[],int mi[],node* n)
{
	if(!n)
		return 0;
		
	if(i==30)
	{
		return n->count;
	}
	else
	{
		int ans=0;
		
		if(mi[i])
		{
			if(c[i])
			{
				ans=count_val(i+1,c,mi,n->left);
			}
			else
			{
				ans=count_val(i+1,c,mi,n->right);
			}
		}
		else
		{
			if(c[i])
			{
				if(n->left)
					ans+=n->left->count;
					
				ans+=count_val(i+1,c,mi,n->right);
			}
			else
			{
				if(n->right)
					ans+=n->right->count;
					
				ans+=count_val(i+1,c,mi,n->left);
			}
		}
		return ans;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	root=new node();
	
	int n,k;
	cin>>n>>k;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int xor_val[n];
	xor_val[0]=arr[0];
	insert_(xor_val[0]);
	
	for(int i=1;i<n;i++)
	{
		xor_val[i]=arr[i]^xor_val[i-1];
		insert_(xor_val[i]);
	}
	
	int mi[30];
	
	for(int i=0;i<30;i++)
	{
		if(k%2)
			mi[29-i]=1;
		else
			mi[29-i]=0;
			
		k/=2;
	}
	
	long long f_ans=0;
	
	int c[30]={0};
	for(int i=0;i<n;i++)
	{
		f_ans+=count_val(0,c,mi,root);			
		delete_(xor_val[i]);
		
		for(int j=0;j<30;j++)
		{
			if(xor_val[i]%2)
				c[29-j]=1;
			else
				c[29-j]=0;
				
			xor_val[i]/=2;
		}
	}
	
	cout<<f_ans<<endl;
	return 0;
}
