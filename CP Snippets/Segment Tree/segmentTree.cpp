ll df_sgtree=0;				      //default segment tree value
vll sgtree(4*N,df_sgtree);	//initialize segment tree with default value

ll merge_sgtree(ll a, ll b)
{
	return a+b;
}

void build_sgtree(vll &v, ll ind, ll lo, ll hi)
{
	//TC: O(n)
	if (lo==hi)				//if leaf node
	{
		sgtree[ind]=v[lo];
		return;
	}
	ll mid=(hi+lo)>>1;
	build_sgtree(v,2*ind+1,lo,mid);
	build_sgtree(v,2*ind+2,mid+1,hi);
	sgtree[ind]=merge_sgtree(sgtree[2*ind+1],sgtree[2*ind+2]);
}

void update(ll ind, ll lo, ll hi, ll pos, ll val)
{
	//TC: O(logn)
	if (lo>pos || hi<pos)
		return;
	if (lo!=hi)				//if not leaf node, partition and update
	{
		ll mid=(hi+lo)>>1;
		update(2*ind+1,lo,mid,pos,val);
		update(2*ind+2,mid+1,hi,pos,val);
		sgtree[ind]=merge_sgtree(sgtree[2*ind+1],sgtree[2*ind+2]);
	}
	else					    //if leaf node, update node value
		sgtree[ind]=val;
}

ll query(ll ind, ll lo, ll hi, ll l, ll r)
{
	//TC: O(logn)
	//3 cases
	if (lo>=l && hi<=r)		  //complete overlap
		return sgtree[ind];
	else if (lo>r || hi<l)	//no overlap, return default value
		return df_sgtree;
	else					          //partial overlap
	{
		ll mid=(hi+lo)>>1;
		ll left=query(2*ind+1,lo,mid,l,r);
		ll right=query(2*ind+2,mid+1,hi,l,r);
		return merge_sgtree(left,right);
	}
}
