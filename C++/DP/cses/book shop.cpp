/* problem link- https://cses.fi/problemset/task/1158/
Rahul kumar 
Dayananda sagar collge of engineering*/


#include <bits/stdc++.h>
using namespace std;
 
#define lll int64_t
#define ll long long
#define ar array
#define mod 1000000007
int solve(int n,int W,int wt[],int v[])
{
    int t[n+1][W+1],i,j;
    for(i=0;i<n+1;i++)
        for(j=0;j<W+1;j++)
    {
        if(i==0||j==0)
            t[i][j]=0;
 
    }
    for(i=1;i<n+1;i++)
        for(j=1;j<W+1;j++)
    {
        if(wt[i-1]<=j)
        {
            t[i][j]=max(v[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
        }
        else
            t[i][j]=t[i-1][j];
 
            //cout<<t[i][j]<<endl;
    }
    return t[n][W];
}
int main()
{
 
int n,W,h[1000],page[1000];
    cin>>n>>W;
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
        cin>>page[i];
    cout<<solve(n,W,h,page);
}