//DFS traversal on Graph
//TC: O(N+E)                -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N)  -> for adjacency list, visited array and recursion stack respectively

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

void dfs(ll node, vll adj[], vector <bool> &vis, vll &storeDFS)
{
	storeDFS.push_back(node);
	vis[node]=true;
	for (auto &it: adj[node])
	{
		if (!vis[it])						          //if adjacent node not visited, call dfs for the adjacent node
			dfs(it,adj,vis,storeDFS);
	}
}

vll dfsOnGraph(vll adj[], ll n)
{
	vll storeDFS;
	vector <bool> vis(n+1,false);       //visited array
	for (ll i=1;i<=n;i++)
	{
		if (!vis[i])						          //if node not visited, call dfs for the node
			dfs(i,adj,vis,storeDFS);
	}
	return storeDFS;	
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vll adj[n+1];
	for (ll i=1;i<=m;i++)					      //input the graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vll dfs=dfsOnGraph(adj,n);
	for (auto &it: dfs)
		cout<<it<<" ";
	return 0;
}
