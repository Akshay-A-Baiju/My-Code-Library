//topological sort (DFS)          -> DFS + STACK
//TC: O(N+E)                	    -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N) + O(N) -> for adjacency list, visited array, stack and recursion stack respectively

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

void findTopoSort(ll node, vector <bool> &vis, stack <ll> &st, vll adj[])
{
	//simple dfs traversal
	vis[node]=true;
	for (auto &it: adj[node])
	{
		if (!vis[it])                   //if visited, the node is already in the stack, thus we are ensured that topological order is followed
			findTopoSort(it,vis,st,adj);
	}
	st.push(node);							      //while returning push the node to stack
}

vll topoSort(vll adj[], ll n)
{
	stack <ll> st;                    //stack stores the elements in topolgical order
	vector <bool> vis(n+1,false);
	for (ll i=1;i<=n;i++)
	{
		if (!vis[i])
			findTopoSort(i,vis,st,adj);
	}
	vll topo;
	while (!st.empty())						    //empty stack elements to topo array
	{
		topo.push_back(st.top());
		st.pop();
	}
	return topo;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vll adj[n+1];
	for (ll i=1;i<=m;i++)						  //input the graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	vll tsort=topoSort(adj,n);
	for (auto &it: tsort)
		cout<<it<<" ";
	return 0;
}
