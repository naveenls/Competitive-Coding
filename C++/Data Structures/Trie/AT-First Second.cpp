#include<bits/stdc++.h>
using namespace std;

struct Node{
	char c;
	vector<Node*> adj;
	bool flag=0;
};

Node* root=NULL;

void insert(string s)
{
	reverse(s.begin(),s.end());
	
	Node* node=root;
	
	for(int i=0;i<s.size();i++)
	{
		if(node->adj[s[i]-'a']==NULL)
		{
			Node* new_node=new Node();
			new_node->c=s[i];
			
			new_node->adj=vector<Node*>(26,NULL);
			node->adj[s[i]-'a']=new_node;
			
			node=new_node;
		}
		else
		{
			node=node->adj[s[i]-'a'];	
		}
	}	
	node->flag=1;
}


long long count_ans(vector<string> &s,int n)
{
	root=new Node();
	root->c='0';
	root->adj=vector<Node*>(26,NULL);
	
	long long ans=0;
	
	for(int i=0;i<n;i++)
	{	
		int temp[26]={0};
		for(int j=0;j<s[i].size();j++)
		{
			temp[s[i][j]-'a']++;	
		}
		
		Node* node=root;
		
		for(int j=s[i].size()-1;j>=0 && node!=NULL ;j--)
		{
			for(int k=0;k<26;k++)
			{
				if(temp[k] && node->adj[k]!=NULL && node->adj[k]->flag)
				{
					ans++;	
				}
			}
			
			node=node->adj[s[i][j]-'a'];	
			temp[s[i][j]-'a']--;
		}
		
		insert(s[i]);
	}
	
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	vector<string> s(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i];	
	}
	
	long long ans=count_ans(s,n);
	reverse(s.begin(),s.end());
	
	cout<<ans+count_ans(s,n)<<endl;
	
	return 0;
}
