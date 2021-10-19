//shortest path in undirected graph with unit weights -> BFS
//TC: O(N+E)                -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(E) + O(E)  -> adjacency list, queue and distance array

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

vll shortestPath_bfs(ll src, vll adj[], ll n)
{
	queue <ll> q;
	q.push(src);
	vll dist(n+1,LLONG_MAX);				  //initial distance be INF
	dist[src]=0;							        //distance from source to source node is 0
	while (!q.empty())
	{
		ll node=q.front();
		q.pop();
		for (auto &it: adj[node])			  //traverse the adjacent nodes
		{
			if (dist[node]+1<dist[it])		//if distance of adjacent node from node is less than previous dist, update distance and push to Queue
			{
				dist[it]=dist[node]+1;
				q.push(it);
			}
		}
	}
	return dist;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vll adj[n+1];
	for (ll i=1;i<=m;i++)					    //input graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll src;
	cin>>src;								          //input source node
	vll dist = shortestPath_bfs(src,adj,n);
	for (ll i=1;i<=n;i++)
		cout<<dist[i]<<" ";
	return 0;
}
