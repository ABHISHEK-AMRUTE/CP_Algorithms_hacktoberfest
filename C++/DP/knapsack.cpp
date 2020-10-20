
/* Name -Rahul kumar
 college-Dayananada sagar college of engineering,Bangalore*/

#include <bits/stdc++.h>

using namespace std;
//int solve();

int solve(int a[],int sum,int n)
{
    int i,j,t[n+1][sum+1];
    for(i=0;i<n+1;i++)
        for(j=0;j<sum+1;j++)
    {
        if(i==0)
            t[i][j]=0;
        if(j==0)
            t[i][j]=1;

    }
    for(i=1;i<n+1;i++)
        for(j=1;j<sum+1;j++)
    {
    if(a[i-1]<=j)
    {
        t[i][j]=(t[i-1][j-a[i-1]]||t[i-1][j]);
    }
    else if(a[i-1]>j)
    {
        t[i][j]=t[i-1][j];
    }
    }
    return t[n][sum];
}
int subset(int a[],int sum,int n)
{
    int s=0,i=0,z;
    for(i=0;i<n;i++)
    s=s+a[i];
    if(s%2!=0)
    {
        return 0;
    }
    else
    {
        s=sum/2;
        z=solve(a,s,n);
        if(z==1)
            return 1;
        else
            return 0;
    }

}

int main()
{
    int n,i,a[10000],sum;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>sum;
    int p=subset(a,sum,n);
    //int p=solve(a,sum,n);

    cout<<p<<endl;
}
