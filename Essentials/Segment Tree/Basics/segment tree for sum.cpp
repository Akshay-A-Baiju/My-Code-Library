//segment tree for sum
//TC: O(n+q*logn)
//SC: O(n)

#include<bits/stdc++.h>
using namespace std;
#define ll		long long
#define vll		vector <ll>
const int N = 1e5+7;

vll sgtree(4*N,0);
 
void build_sgtree(vll &v, ll ind, ll lo, ll hi)
{
    if (lo==hi)				       //leaf node
    {
        sgtree[ind]=v[lo];
        return;
    }
    //partition into 2 segments
    ll mid=(hi+lo)/2;
    build_sgtree(v,2*ind+1,lo,mid);
    build_sgtree(v,2*ind+2,mid+1,hi);
    sgtree[ind]=sgtree[2*ind+1]+sgtree[2*ind+2];
}
 
void update(ll ind, ll lo, ll hi, ll pos, ll diff)
{
    if (lo>pos || hi<pos)
        return;
    sgtree[ind]+=diff;
    if (lo!=hi)
    {
        //partition into 2 segments
        ll mid=(hi+lo)/2;
        update(2*ind+1,lo,mid,pos,diff);
        update(2*ind+2,mid+1,hi,pos,diff);
    }
}
 
ll query(ll ind, ll lo, ll hi, ll l, ll r)
{
    //3 cases
    if (lo>=l && hi<=r)     //full overlap
        return sgtree[ind];
    else if (hi<l || lo>r)  //no overlap
        return 0;
    else                    //partial overlap
    {
        //partition into 2 segments
        ll mid=(hi+lo)/2;
        ll left=query(2*ind+1,lo,mid,l,r);
        ll right=query(2*ind+2,mid+1,hi,l,r);
        return left+right;
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
      //op 2. query - sum of range [l,r)
      if (op==1)
      {
          ll pos,val;     cin>>pos>>val;
          ll diff=val-v[pos];
          //update vector
          v[pos]=val;
          //update seg tree
          update(0,0,n-1,pos,diff);
      }
      else
      {
          ll l,r;         cin>>l>>r;
          cout<<query(0,0,n-1,l,r-1)<<endl;
      }
  }
  return 0;
}
