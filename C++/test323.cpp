#include<bits/stdc++.h>
using namespace std;

const int maxB=20;

struct node{
	bool bit;
	int val;
	
	node* left=NULL;
	node* right=NULL;
};

node* root;

void insert_into(int x)
{
	int arr[maxB];
	
	for(int i=0;i<maxB;i++)
	{
		arr[i]=x%2;
		x/=2;	
	}
	
	node* n=root;
	
	for(int i=maxB-1;i>=0;i--)
	{
		if(arr[i])
		{
			if(n->right!=NULL)
				n=n->right;
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

int dfs(node* r)
{
	if(r==NULL)
		return 0;
		
	r->val=1;
	r->val+=dfs(r->left)+dfs(r->right);
	
	return r->val;
}

int find_mex(int x)
{
	int arr[maxB];
	
	for(int i=0;i<maxB;i++)
	{
		arr[i]=x%2;
		x/=2;	
	}
	
	node* n=root;
	
	int ans[maxB]={0};
	
	int depth=(1<<(maxB));
	
	for(int i=maxB-1;i>=0;i--)
	{
		if(n==NULL)
			break;
			
		if(arr[i])
		{
			if(n->right==NULL)
				break;
				
			if(n->right->val==depth-1)
			{
				n=n->left;
				ans[i]=1;
			}
			else
			{
				n=n->right;
			}
		}
		else
		{
			//cout<<n->left->val<<' '<<depth-1<<endl;
			if(n->left==NULL)
				break;
				
			if(n->left->val==depth-1)
			{
				n=n->right;
				ans[i]=1;
			}
			else
			{
				n=n->left;
			}
		}
		depth/=2;
	}
	
	int f_ans=0;
	
	int s=1;
	
	for(int i=0;i<maxB;i++)
	{
		//cout<<ans[i]<<' ';
		if(ans[i])
			f_ans+=s;
		
		s*=2;
	}
	//cout<<endl;
	return f_ans;
	
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	root=new node();
	
	set<int> s;
	
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		
		if(s.find(a)==s.end())
		{
			s.insert(a);
			insert_into(a);
		}
	}
	dfs(root);
	
	int prev=0;
	for(int i=0;i<m;i++)
	{
		cin>>a;
		prev=prev^a;
		
		if(s.find(prev)==s.end())
		{
			cout<<0<<endl;
		}
		else
		{			
			cout<<(find_mex(prev))<<endl;
		}
	}
	return 0;
}
