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
 
int n;
vector <string> v(1005);
vector <vi> dp(1005,vi (1005,-1));
 
int path(int i,int j){
	if(i<0 || j<0) return 0;
	if(v[i][j]=='*') return 0;
	if(i==0 && j==0) return 1;
	
	if(dp[i][j]!=-1) return dp[i][j];
 
	int ans=0;
	ans=(ans+path(i-1,j)%mod)%mod;
	ans=(ans+path(i,j-1)%mod)%mod;
 
	return dp[i][j]=ans;
}
 
void solve(){
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>v[i];
	}
	int ans=path(n-1,n-1);
	cout<<ans<<"\n";
}
 
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   solve();
   return 0;
}