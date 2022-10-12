ll dp[105][200005];

void fun(ll x[] , ll n , ll sum)  // set dp
{
    dp[0][0] = 1;
    for(ll i=1;i<=sum;i++)
    {
        dp[0][i] = 0;
    }
    
    for(ll i=1;i<=n;i++) //index of element
    {
        for(ll j=0;j<=sum;j++) //sum
        {
            if(dp[i-1][j]==1)
            {
                dp[i][j]=1;
            }
            else
            {
                ll sum = j - x[i];
                if( sum>=0 && dp[i-1][sum]==1 )
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
}



// call -> fun(x,n,sum);
