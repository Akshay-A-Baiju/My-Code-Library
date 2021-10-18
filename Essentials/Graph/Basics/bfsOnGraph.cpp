//BFS traversal on Graph
//TC: O(N+E)                -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N)  -> for adjacency list, visited array and queue respectively

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

vll bfsOnGraph(vll adj[], ll n)
{
	vll bfs;
	vector <bool> vis(n+1,false);
	for (ll i=1;i<=n;i++)					  //for traversing all connected components
	{
		if (!vis[i])
		{
			queue <ll> q;					      //Queue DS is used in BFS for level order/breadth traversal
			q.push(i);
			vis[i]=true;
			while (!q.empty())				  //queue becomes empty when all nodes in a connected component are traversed
			{
				ll node=q.front();
				q.pop();
				bfs.push_back(node);
				for (auto &it: adj[node])	//traverse adjacent nodes
				{
					if (!vis[it])			      //if not visited, add to queue and mark visited
					{
						q.push(it);
						vis[it]=true;
					}
				}
			}
		}
	}
	return bfs;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vll adj[n+1];
	for (ll i=1;i<=m;i++)					  //input the graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vll bfs=bfsOnGraph(adj,n);
	for (auto &it: bfs)
		cout<<it<<" ";
	return 0;
}
