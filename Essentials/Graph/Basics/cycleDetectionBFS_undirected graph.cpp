//cycle detection using BFS in a graph
//TC: O(N+E)                -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N)  -> for adjacency list, visited array and queue respectively

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

bool checkForCycle_bfs(ll src, vector <bool> &vis, vll adj[])
{
	queue <pair<ll,ll>> q;				    //pair <node,parent> because we need to check the adjacent node is parent of current node or not
	q.push({src,-1});
	vis[src]=true;
	while (!q.empty())
	{
		ll node=q.front().first;
		ll parent=q.front().second;
		q.pop();
		for (auto &it: adj[node])
		{
			if (!vis[it])                 //if adjacent node is not visited, push pair <it,node> to queue
			{
				q.push({it,node});
				vis[it]=true;
			}
			else if (it!=parent)		      //if node is already visited but not parent, i.e. cycle exists
				return true;
		}
	}
	return false;                     //if no cycle is detected, return false
}

bool isCycleBFS(vll adj[], ll n)
{
	vector <bool> vis(n+1,false);
	for (ll i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			if (checkForCycle_bfs(i,vis,adj))
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
	for (ll i=1;i<=m;i++)						    //input the graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (isCycleBFS(adj,n))
		cout<<"Cycle present";
	else
		cout<<"No cycle present";
	return 0;
}
