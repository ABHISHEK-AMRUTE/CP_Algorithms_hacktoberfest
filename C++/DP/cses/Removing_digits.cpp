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
vi dp(1e6+5,-1);
 
int f(int n){
	if(n==0) return 0;
	if(n<0) return 1e7;
	if(dp[n]!=-1) return dp[n];
 
	int temp=n;
	string s=to_string(temp);
	int ans=1e7;
	// int maxi=0;
	for(int i=0 ; i<s.length() ; i++){
		int cur=(s[i]-'0');
		debug(cur)
		// maxi=max(cur,maxi);
		if(cur!=0)
			ans=min(ans,f(n-cur)+1);
	}
	return dp[n]=ans;
}
 
void solve(){
	cin>>n;
	int ans=f(n);
	cout<<ans<<"\n";
}
 
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   solve();
   return 0;
}