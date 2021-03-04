#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

struct node{
	bool bit;
	node* left=NULL;
	node* right=NULL;
};

node* root;

void insert_into(int x)
{
	int arr[30];
	
	for(int i=0;i<30;i++)
	{
		arr[i]=x%2;
		x/=2;	
	}
	
	node* n=root;
	
	for(int i=29;i>=0;i--)
	{
		if(arr[i])
		{
			if(n->right!=NULL)
			{
				n=n->right;
			}
			else
			{
				node* new_node =new node();
				new_node->bit=1;
				
				n->right=new_node;
				n=n->right;
			}
		}
		else
		{
			if(n->left!=NULL)
			{
				n=n->left;
			}
			else
			{
				node* new_node =new node();
				new_node->bit=0;
				
				n->left=new_node;
				n=n->left;
			}
		}
	}
}

void delete_from(int x)
{
	int arr[30];
	
	for(int i=0;i<30;i++)
	{
		arr[i]=x%2;
		x/=2;	
	}
	
	node* n=root;
	
	vector<node*> v;
	for(int i=29;i>=0;i--)
	{
		if(arr[i])
		{
			n=n->right;
		}
		else
		{
			n=n->left;
		}
		v.push_back(n);
	}
	reverse(v.begin(),v.end());
	
	for(int i=1;i<v.size();i++)
	{
		if(v[i]->left && v[i]->right)
		{
			//cout<<i<<' '<<v[i]->bit<<' '<<v[i-1]->bit<<endl;
			if(v[i-1]->bit)
			{
				v[i]->right=NULL;
			}
			else
			{
				v[i]->left=NULL;
			}
			return;
		}
	}
}

int find_max(int x)
{
	int arr[30];
	
	for(int i=0;i<30;i++)
	{
		arr[i]=x%2;
		x/=2;	
	}
	
	int val=(1<<29);
	int ans=0;
	
	node* n=root;
	 
	for(int i=29;i>=0;i--)
	{
		if(arr[i])
		{
			if(n->left!=NULL)
			{
				ans+=val;
				n=n->left;
			}
			else
			{
				n=n->right;
			}
		}
		else
		{
			if(n->right!=NULL)
			{
				ans+=val;
				n=n->right;
			}
			else
			{
				n=n->left;
			}
		}
		val/=2;
	}
	return ans;
}
void insert(int x)
{
	mp[x]++;
	
	if(mp[x]==1)
		insert_into(x);
}

void delete_(int x)
{
	mp[x]--;
	if(mp[x]==0)
		delete_from(x);
}
int main()
{
	root=new node();
	insert(0);
	
	int q;
	cin>>q;
	
	char c;
	int val;
	
	while(q--)
	{
		cin>>c>>val;
		if(c=='+')
		{
			insert(val);	
		}	
		else if(c=='-')
		{
			delete_(val);
		}
		else
		{
			cout<<find_max(val)<<endl;
		}
	}
	return 0;
}
