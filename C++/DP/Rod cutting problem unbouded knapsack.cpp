// Rahul kumar
// Dayananda sagar college of engineering,Bangalore
#include <bits/stdc++.h>

using namespace std;
int solve(int a[],int wt[],int n,int W)
{
   int i,j, t[n+1][W+1];
    for(i=0;i<n+1;i++)
    for(j=0;j<W+1;j++)
    {

        if(i==0 || j==0)
            t[i][j]=0;
    }
    for(i=1;i<n+1;i++)
        for(j=1;j<W+1;j++)
    {
       if(wt[i-1]<=j)
       {
           t[i][j]=max(a[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
       }
       else
        t[i][j]=t[i-1][j];
    }
    return t[n][W];
}
int main()
{
    int n,i,p[1000],wt[1000];

//Enter the length of rod
    cin>>n;
    //enter the price of rod having length 1 to n
    for(i=0;i<n;i++)
        cin>>p[i];
    for(i=0;i<n;i++)
        wt[i]=i+1;
    int W=n;
    //Give you the maximum profit you generate
    cout<<solve(p,wt,n,W);

}
