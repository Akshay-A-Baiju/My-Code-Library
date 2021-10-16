//segment tree for minimum - Range Minimum query (RMQ)
//TC: O(n+q*logn)
//SC: O(n)

#include<bits/stdc++.h>
using namespace std;
#define ll		long long
#define vll		vector <ll>
const int N = 1e5+7;

vll sgtree(4*N,LLONG_MAX);
 
void build_sgtree(vll &v, ll ind, ll lo, ll hi)
{
    if (lo==hi)
    {
        sgtree[ind]=v[lo];
        return;
    }
    //partition into 2 segments
    ll mid=(hi+lo)/2;
    build_sgtree(v,2*ind+1,lo,mid);
    build_sgtree(v,2*ind+2,mid+1,hi);
    sgtree[ind]=min(sgtree[2*ind+1],sgtree[2*ind+2]);
}
 
void update(ll ind, ll lo, ll hi, ll pos, ll val)
{
    if (hi<pos || lo>pos)
        return;
    if (lo!=hi)
    {
        //partition into 2 segments
        ll mid=(hi+lo)/2;
        update(2*ind+1,lo,mid,pos,val);
        update(2*ind+2,mid+1,hi,pos,val);
        sgtree[ind]=min(sgtree[2*ind+1],sgtree[2*ind+2]);
    }
    else
        sgtree[ind]=val;
}
 
ll query(ll ind, ll lo, ll hi, ll l, ll r)
{
    //3 cases
    if (lo>=l && hi<=r)     //full overlap
        return sgtree[ind];
    else if (hi<l || lo>r)  //no overlap
        return LLONG_MAX;
    else                    //partial overlap
    {
        //partition into 2 segments
        ll mid=(hi+lo)/2;
        ll left=query(2*ind+1,lo,mid,l,r);
        ll right=query(2*ind+2,mid+1,hi,l,r);
        return min(left,right);
    }
}
 
int main()
{
    ll n,q;
	  cin>>n>>q;
    vll v(n);
    for (ll i=0;i<n;i++)
    	  cin>>v[i];
    build_sgtree(v,0,0,n-1);
    while (q--)
    {
        ll op;
        cin>>op;
        //op 1. update
        //op 2. query - minimum element in range [l,r)
        if (op==1)
        {
            ll pos,val;     cin>>pos>>val;
            //update vector
            v[pos]=val;
            //update segment tree
            update(0,0,n-1,pos,val);
        }
        else
        {
            ll l,r;         cin>>l>>r;
            cout<<query(0,0,n-1,l,r-1)<<endl;
        }
    }
    return 0;
}
