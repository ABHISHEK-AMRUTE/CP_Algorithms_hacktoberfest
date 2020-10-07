// NAME : CHARAN R
// COLLEGE: National Institute of Technology Karnataka

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d;
    cin>>n;
    cin>>d;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

     int r = d%n;
    for(int i=0;i<n;i++)
    {
        cout<<a[(i+r)%n]<<" ";

    }
    
}
