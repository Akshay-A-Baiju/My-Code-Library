//cycle detection using DFS in a graph
//TC: O(N+E)                -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N)  -> for adjacency list, visited array and recursion stack respectively

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

bool checkForCycle(ll node, ll parent, vector <bool> &vis, vll adj[])
{
	vis[node]=true;
	for (auto &it: adj[node])
	{
		if (!vis[it])
		{
			if (checkForCycle(it,node,vis,adj))     //recursive dfs call to check cycle
				return true;
		}
		else if (it!=parent)					            //if the adjacent node is already visited but is not the parent of the node, i.e. cycle exists
			return true;
	}
	return false;								                //if no cycle found, return false
}

bool isCycleDFS(vll adj[], ll n)
{
	vector <bool> vis(n+1,false);
	for (ll i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			if (checkForCycle(i,-1,vis,adj))	      //we need to pass the node and its parent to check for Cycle, initial node be -1
				return true;
		}
	}
	return false;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vll adj[n+1];
	for (ll i=1;i<=m;i++)						            //input the graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (isCycleDFS(adj,n))
		cout<<"Cycle present";
	else
		cout<<"No Cycle present";
	return 0;
}
