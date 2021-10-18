//Bipartite graph check using BFS
//Observation: If the graph has odd length cycle -> NOT BIPARTITE, else (even length cycle or no cycle) -> BIPARTITE
//TC: O(N+E)                -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N)  -> for adjacency list, visited array and queue respectively

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

bool bipartiteBFS(ll src, vector <int> &color, vll adj[])
{
	//let initial color of source node be 0
	color[src]=0;
	queue <ll> q;
	q.push(src);
	while (!q.empty())
	{
		ll node=q.front();
		q.pop();
		for (auto &it: adj[node])
		{
			if (color[it]==-1)					      //adjacent node is not colored
			{
				q.push(it);
				color[it]=1-color[node];		    //color the opposite color of node
			}
			else if (color[it]==color[node])	//if adjacent node is colored and of same color as node, i.e not bipartite
				return false;
		}
	}
	return true;
}

bool isBipartiteBFS(vll adj[], ll n)
{
	vector <int> color(n+1,-1);					   //instead of visted array, we have color array
	//color array has 3 states: -1->not visited/colored, 0->color1, 1->color2
	for (ll i=1;i<=n;i++)
	{
		if (color[i]==-1)
		{
			if (!bipartiteBFS(i,color,adj))
				return false;
		}
	}
	return true;								           //if no bipartite detected, meaning graph is bipartite, return true
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vll adj[n+1];
	for (ll i=1;i<=m;i++)						       //input the graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (isBipartiteBFS(adj,n))
		cout<<"Graph is Bipartite";
	else
		cout<<"Graph is not Bipartite";
	return 0;
}
