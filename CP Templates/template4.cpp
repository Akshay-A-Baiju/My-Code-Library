// Author: Akshay A Baiju
// Problem: 
// Contest: 
// URL: 

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ff first
#define ss second
#define ins insert
#define vll vector <ll>
#define vvll vector <vll>
#define vbool vector <bool>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define YY cout<<"YES"
#define NN cout<<"NO"
#define yy cout<<"Yes"
#define nn cout<<"No"
#define set_bits __builtin_popcountll
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define desc() greater <ll>()
#define fill1(a,x) for (auto &it: a) it=x;
#define fill2(a,x) for (auto &v: a) { for (auto &it: v) it=x; }
#define endl '\n'   //not to be used in interactive problems
#define random(l,r,T) uniform_int_distribution<T>(l,r)(rng)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ******Policy based data structures******
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class key, class value> using omap = tree <key,value,less<key>,rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k) -> returns iterator to kth element from start 0
// order_of_key(k) -> returns count of elements < k

#ifndef ONLINE_JUDGE
    #define debug(x)        cerr<<#x<<" = "; _print(x); cerr<<"\n";
#else
    #define debug(x)
#endif

const int M = 1e9+7;
const int MM = 998244353;
const int N = 2e5+7;
const ll inf = 1e18;
const ld eps = 1e-9;
#define PI 3.141592653589793238462

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int Dx[]={0,1,1,1,0,-1,-1,-1};
int Dy[]={1,1,0,-1,-1,-1,0,1};

void _print(ll t) { cerr<<t; }
void _print(int t) { cerr<<t; }
void _print(ld t) { cerr<<t; }
void _print(string t) { cerr<<t; }
void _print(char t) { cerr<<t; }
void init_usaco() { freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); }

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<typename T> istream& operator >>(istream &in,vector<T> &v){ for(auto &x:v) in>>x; return in;}
template<typename T> ostream& operator <<(ostream &out,const vector<T> &v){ for(auto &x:v) out<<x<<' '; return out;}
template<typename T1,typename T2> istream& operator >>(istream &in,pair<T1,T2> &p){ in>>p.first>>p.second; return in;}
template<typename T1,typename T2> ostream& operator <<(ostream &out,const pair<T1,T2> &p){ out<<p.first<<' '<<p.second; return out;}

ll gcd(ll a, ll b) { while (b) {a %= b; swap(a,b);} return a; }
ll lcm(ll a, ll b) { ll g=gcd(a,b); ll res=a*(b/g); return res; }
ll extended_gcd(ll a, ll b, ll &x, ll &y) { if (b==0) { x=1; y=0; return a; } ll x1,y1; ll g=extended_gcd(b,a%b,x1,y1); x=y1; y=x1-y1*(a/b); return g; }
ll binExp(ll a, ll b, ll m=M) { a = a % m; ll res = 1; while (b) { if (b&1) { res=(res * a) % m; } a=(a * a) % m; b>>=1; } return res; }
ll mod_inv(ll a, ll m=M) { a = a % m; return binExp(a,m-2,m); }        // only for prime m
ll mod_add(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m=M) { a = a % m; ll binv = mod_inv(b,m); return (((a * binv) % m) + m) % m; }
ll sqrtll(ll n) { ll lo=0,hi=1e9+7; while (hi-lo>1) { ll m=(hi+lo)/2; if (m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi<=n) { return hi; } return lo; }
ld sqrtld(ll n) { ld lo=0,hi=1e9+7; while (hi-lo>eps) { ld m=(hi+lo)/2; if ((n-m*m)>eps) { lo=m; } else { hi=m-eps; }} return lo; }

void solve()
{
    
}

int main()
{
    #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        clock_t clk = clock();
    #endif
    // init_usaco();
    fastIO;
    int t=1;
    cin>>t;
    for (int test=1;test<=t;test++)
    {
        // cout<<"Case #"<<test<<": ";
        solve();
        cout<<endl;
    }
    #ifndef ONLINE_JUDGE
          cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    #endif
    return 0;
}
