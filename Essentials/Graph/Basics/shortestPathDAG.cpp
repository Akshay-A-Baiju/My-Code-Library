//shortest path in DAG
//TC: O(N+E)  					          -> topological sort + vis all adjacents of nodes
//SC: O(N+E) + O(N) + O(N) + O(N) -> adjacent list, visited array, stack and distance array

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

void findTopoSort(ll node, vector <bool> &vis, stack <ll> &st, vector <pair<ll,ll>> adj[])
{
	//Toposort using DFS
	vis[node]=true;
	for (auto &it: adj[node])
	{
		if (!vis[it.first])
			findTopoSort(it.first,vis,st,adj);
	}
	//while returning push node to stack
	st.push(node);
}

vll shortestPathDAG(ll src, vector <pair<ll,ll>> adj[], ll n)
{
	//generate the topo sort for the graph
	vector <bool> vis(n+1,false);
	stack <ll> st;
	for (ll i=1;i<=n;i++)
	{
		if (!vis[i])
			findTopoSort(i,vis,st,adj);
	}
	//take distance array and mark all nodes as infinity
	vll dist(n+1,LLONG_MAX);
	dist[src]=0;						            //distance to reach source from source is 0
	while (!st.empty())
	{
		ll node=st.top();
		st.pop();
		if (dist[node]!=LLONG_MAX)		    //i.e node has been reached before
		{
			for (auto &it: adj[node])	      //traverse the adjacent nodes
			{
				if (dist[node]+it.second < dist[it.first])
					dist[it.first]=dist[node]+it.second;
			}
		}
	}
	return dist;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vector <pair<ll,ll>> adj[n+1];
	for (ll i=1;i<=m;i++)				        //input graph
	{
		ll u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
	}
	ll src;								              //input source
	cin>>src;
	vll dist=shortestPathDAG(src,adj,n);
	for (ll i=1;i<=n;i++)
		(dist[i]==LLONG_MAX)?cout<<"inf ":cout<<dist[i]<<" ";
	return 0;
}
