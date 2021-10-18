//cycle detection using DFS in a directed graph
//TC: O(N+E)                		-> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N) + O(N)   -> for adjacency list, visited array, dfs visited array and recursion stack respectively

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

bool checkForCycle_dfs(ll node, vector <bool> &vis, vector <bool> &dfsvis, vll adj[])
{
	vis[node]=true;                               //mark both vis and dfsvis array for the current dfs call
	dfsvis[node]=true;
	for (auto &it: adj[node])
	{
		if (!vis[it])                               //here we check in vis array and not dfsvis array, as if cycle was present it would have being detected earlier, so no need to go through the vis array nodes
		{
			if (checkForCycle_dfs(it,vis,dfsvis,adj))	//recursive dfs call to check cycle
				return true;
		}
		else if (dfsvis[it])							          //if elements is visited both in vis and dfsvis, it means cycle is present for current dfs call
			return true;
	}
	dfsvis[node]=false;									          //backtracking step -> unmark dfsvis array for the dfs call
	return false;										              //if no cycle found, return false
}

bool isCycleDFS(vll adj[], ll n)
{
	vector <bool> vis(n+1,false),dfsvis(n+1,false);
	for (ll i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			if (checkForCycle_dfs(i,vis,dfsvis,adj))	//we need to pass the node, here parent node isnt required as we have vis and dfsvis array
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
	for (ll i=1;i<=m;i++)								//input the graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	if (isCycleDFS(adj,n))
		cout<<"Cycle present";
	else
		cout<<"No cycle present";
	return 0;
}
