//topological sort (BFS) 		      -> Kahn's Algorithm
//TC: O(N+E)                	    -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N) + O(N) -> for adjacency list, visited array, stack and recursion stack respectively
//Idea of Kahn's Algo: We observe that the first nodes in topological order has indegree = 0, thus if we remove them from the graph, the adjacent nodes indegree is decreased by 1
//and has indegree 0 as well. This forms the basis of Kahn's Algo

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

vll topoSort(vll adj[], ll n)
{
	vll topo;
	queue <ll> q;
	//compute the indegree array
	vll indegree(n+1,0);
	for (ll i=1;i<=n;i++)
	{
		for (auto &it: adj[i])
			indegree[it]++;
	}
	//add all nodes having indegree 0 to queue
	for (ll i=1;i<=n;i++)
	{
		if (indegree[i]==0)
			q.push(i);
	}
	while (!q.empty())
	{
		ll node=q.front();
		q.pop();
		topo.push_back(node);		          //push front element of Queue to topo array
		for (auto &it: adj[node])	        //decrease the indegree of adjacent nodes by 1 (as node is removed)
		{
			indegree[it]--;
			if (indegree[it]==0)	          //if indegree of the adjcacent node becomes 0, push it into Queue
				q.push(it);
		}
	}
	return topo;
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
	vll tsort=topoSort(adj,n);
	for (auto &it: tsort)
		cout<<it<<" ";
	return 0;
}
