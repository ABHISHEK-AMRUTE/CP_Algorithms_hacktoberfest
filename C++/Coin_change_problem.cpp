#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n;
    cin>>k>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long int dp[n][k+1];
    for(int i=0;i<n;i++) {
        dp[i][0]=1;
    }
    for(int i=0;i<=k;i++) {
        if(i%arr[0]==0)
            dp[0][i]=1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            if(j>=arr[i])
                dp[i][j]=dp[i][j-arr[i]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n-1][k];
}