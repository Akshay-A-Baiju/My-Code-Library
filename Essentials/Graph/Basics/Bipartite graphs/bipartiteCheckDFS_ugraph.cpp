//Bipartite graph check using DFS
//Observation: If the graph has odd length cycle -> NOT BIPARTITE, else (even length cycle or no cycle) -> BIPARTITE
//TC: O(N+E)                -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N)  -> for adjacency list, visited array and recursion stack respectively

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

bool bipartiteDFS(ll node, vector <int> &color, vll adj[])
{
	if (color[node]==-1)							        //if uncolored
		color[node]=0;
	for (auto &it: adj[node])
	{
		if (color[it]==-1)							        //if adjacent node is uncolored
		{
			color[it]=1-color[node];				      //color adjacent node with opposite color, and call recursive dfs on it
			if (!bipartiteDFS(it,color,adj))
				return false;
		}
		else if (color[it]==color[node])			  //if adjacent node is already colored and of same color as node, meaning NOT BIPARTITE
			return false;
	}
	return true;									            //if no bipartite detected, meaning graph is bipartite, return true
}

bool isBipartiteDFS(vll adj[], ll n)
{
	vector <int> color(n+1,-1);					      //instead of visted array, we have color array
	//color array has 3 states: -1->not visited/colored, 0->color1, 1->color2
	for (ll i=1;i<=n;i++)
	{
		if (!bipartiteDFS(i,color,adj))
			return false;
	}
	return true;									            //if no bipartite detected, meaning graph is bipartite, return true
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vll adj[n+1];
	for (ll i=1;i<=m;i++)						          //input the graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (isBipartiteDFS(adj,n))
		cout<<"Graph is Bipartite";
	else
		cout<<"Graph is not Bipartite";
	return 0;
}
