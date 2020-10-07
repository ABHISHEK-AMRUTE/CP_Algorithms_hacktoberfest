#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define     ll          long long int
#define     ld          double
#define     REP(i,x,n)    for(ll i=x;i<n;i++)
#define     SZ(v)       (ll)v.size()
#define     endl        "\n"
#define     ff          first
#define     ss          second
#define     PQ_MIN      priority_queue <ll, vector<ll>, greater<ll> >
#define     PQ          priority_queue <int>
#define     pbds        tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define     setbit(x)   __builtin_popcount(x)
#define     prec(n)     fixed<<setprecision(n)
#define     pb(n)       push_back(n)
#define     mp(a,b)     make_pair(a,b)
#define     clr(n)      memset(n,0,sizeof(n))
#define     reset(n)    memset(n,-1,sizeof(n))
#define     ii          pair<ll,ll>
#define     vll         vector<ll>
#define     PI          3.1415926535897932384626433832795028841971693993751

using namespace std;
using namespace __gnu_pbds;

void solve(){
// input data
int n,q;
cin>>n>>q;
vector<int> a (n);

REP(i,0,n) cin>>a[i];

// preprocessing
int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
vector<int> b (len);
for (int i=0; i<n; ++i)
    b[i / len] += a[i];

// answering the queries
while(q--)
    {
    int l, r;
    cin>>l>>r;

  // read input data for the next query
    int sum = 0;
    for (int i=l; i<=r; )
        if (i % len == 0 && i + len - 1 <= r) {
            // if the whole block starting at i belongs to [l, r]
            sum += b[i / len];
            i += len;
        }
        else {
            sum += a[i];
            ++i;
        }
        cout<<sum<<endl;
}

// it will output range sum query using square root decomposition

/*
input : 
5 2
1 2 3 4 5
2 3
0 0

output :

7
1


*/

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
