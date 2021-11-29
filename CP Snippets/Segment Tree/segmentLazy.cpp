ll df_sgtree=0;						//default segment tree value
vll sgtree(4*N,df_sgtree),lazy(4*N,0);

ll merge_sgtree(ll a, ll b)
{
	return a+b;
}

void update_lazy(ll ind, ll lo, ll hi)
{
	if (lazy[ind]!=0)				//if pending update
	{
		ll upd=lazy[ind];
		sgtree[ind]+=upd*(hi-lo+1);	//update in segment tree
		lazy[ind]=0;
		if (lo!=hi)					  //if not leaf node, update left and right segments of lazy tree
		{
			lazy[2*ind+1]+=upd;
			lazy[2*ind+2]+=upd;
		}

	}
}

void build_sgtree(vll &v, ll ind, ll lo, ll hi)
{
	//TC: O(n*logn)
	if (lo==hi)						//if leaf node
	{
		sgtree[ind]=v[lo];
		return;
	}
	ll mid=(hi+lo)>>1;
	build_sgtree(v,2*ind+1,lo,mid);
	build_sgtree(v,2*ind+2,mid+1,hi);
	sgtree[ind]=merge_sgtree(sgtree[2*ind+1],sgtree[2*ind+2]);
}

void update(ll ind, ll lo, ll hi, ll l, ll r, ll val)
{
	//TC: O(logn)
	update_lazy(ind,lo,hi);			//first check for any pending update in lazy tree, if yes update

	if (lo>r || hi<l)				//no overlap
		return;
	else if (lo>=l && hi<=r)		//complete overlap
	{
		sgtree[ind]+=val*(hi-lo+1);
		if (lo!=hi)		//if not leaf node, update left and right node in lazy tree
		{
			lazy[2*ind+1]+=val;
			lazy[2*ind+2]+=val;
		}
	}
	else							//partial overlap
	{
		ll mid=(hi+lo)/2;
		update(2*ind+1,lo,mid,l,r,val);
		update(2*ind+2,mid+1,hi,l,r,val);
		sgtree[ind]=merge_sgtree(sgtree[2*ind+1],sgtree[2*ind+2]);
	}
}

ll query(ll ind, ll lo, ll hi, ll l, ll r)
{
	//TC: O(logn)
	update_lazy(ind,lo,hi);			//first check for any pending update in lazy tree, if yes update

	//3 cases : normal query
	if (lo>=l && hi<=r)				  //complete overlap
		return sgtree[ind];
	else if (lo>r || hi<l)			//no overlap, return default value
		return df_sgtree;
	else							          //partial overlap
	{
		ll mid=(hi+lo)>>1;
		ll left=query(2*ind+1,lo,mid,l,r);
		ll right=query(2*ind+2,mid+1,hi,l,r);
		return merge_sgtree(left,right);
	}
}
