#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mod 1000000007
#define mod1 998244353
 
vi c(1e6+7);
vi dp(1e6+7);
 
ll coins(int x,int n){
	if(x==0) return 0;
	if(x<0) return 1e8;
	if(dp[x]!=-1) return dp[x];
 
	ll ans=1e8;
	for(int i=0 ; i<n ; i++){
		ans=min(ans,coins(x-c[i],n)+1);
	}
	return dp[x]=ans;
}
 
void solve(){
	int n,x;
	cin>>n>>x;
	for(int i=0 ; i<n ; i++){
		cin>>c[i];
	}
	for(int i=0 ; i<=x ; i++){
		dp[i]=-1;
	}
 
	ll ans=coins(x,n);
	if(ans==1e8){
		cout<<"-1\n";
		return;
	}
	cout<<ans<<"\n";
}
 
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   solve();
   return 0;
}