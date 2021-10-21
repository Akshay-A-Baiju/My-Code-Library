//cycle detection using BFS in a directed graph  -> KAHN'S ALGORITHM
//TC: O(N+E)                		    -> N is time taken for visiting N nodes, and E is for traversing through the adjacent nodes overall
//SC: O(N+E) + O(N) + O(N)		    -> for adjacency list, indegree array and queue respectively

#include<bits/stdc++.h>
using namespace std;
#define ll	long long
#define vll	vector <ll>

bool isCycleBFS(vll adj[], ll n)
{
    //we use Kahn's Algorithm to check if topological array can be created or not
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
	ll count=0;						            //length of topological array
    while (!q.empty())
    {
        ll node=q.front();
        q.pop();
        count++;
        for (auto &it: adj[node])   //decrease the indegree of adjacent nodes by 1 (as node is removed)
        {
            indegree[it]--;
            if (indegree[it]==0)    //if indegree of the adjacent node becomes 0, push it into Queue
                q.push(it);
        }
    }
    if (count==n)					          //if length of topo array < n means graph is not DAG, hence Directed Cyclic
		return false;
	else
		return true;
}


int main()
{
	ll n,m;
	cin>>n>>m;
	vll adj[n+1];
	for (ll i=1;i<=m;i++)			        //input the graph
	{
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	if (isCycleBFS(adj,n))
		cout<<"Cycle present";
	else
		cout<<"No cycle present";
	return 0;
}
