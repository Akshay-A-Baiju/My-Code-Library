//shortest path in weighted undirected graph -> DIJSTRA'S ALGORITHM -> Priority Queue + BFS
//TC: O((N+E)*logN)                -> We traverse total N+E and also logN for priority queue
//SC: O(N+E) + O(N) + O(N)  	     -> adjacency list, priority queue and distance array

#include <bits/stdc++.h>
using namespace std;
#define ll		long long
#define vll		vector <ll>
#define ff		first
#define ss		second

vll shortestPath_Dijstras(ll src, vector <pair<ll,ll>> adj[], ll n)
{
	//priorty queue hold the pair <dist,node>
	priority_queue <pair<ll,ll>> pq;
	//distance array, initially INF
	vll distTo(n+1,LLONG_MAX);
	distTo[src]=0;
	pq.push({0,src});
	while (!pq.empty())
	{
		ll dist=pq.top().ff;
		ll node=pq.top().ss;
		pq.pop();
		for (auto &pr: adj[node])			      //traverse the adjacent node
		{
			ll adj_node=pr.ff;
			ll wt=pr.ss;
			if (dist+wt<distTo[adj_node])	    //if new distance to adjacent node through node < dist[adj node]
			{								                  //then update dist[adj node] and push {newdist,adj node} to priority queue
				distTo[adj_node]=dist+wt;
				pq.push({distTo[adj_node],adj_node});
			}
		}
	}
	return distTo;	
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vector <pair<ll,ll>> adj[n+1];		    //input weighted graph
	for (ll i=1;i<=m;i++)
	{
		ll u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
	ll src;
	cin>>src;							                //input source node
	vll dist=shortestPath_Dijstras(src,adj,n);
	for (ll i=1;i<=n;i++)
		cout<<dist[i]<<" ";
	return 0;	
}
