#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    { 
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a;
        cin >> b;
        int arr[n+1][m+1]={0};
           
        for(int x=0;x<=n;x++)
        {
            for(int y=0;y<=m;y++)
            {    

                if(x==0||y==0)
                {
                    arr[x][y]=0;
                }
                else
                if(a[x-1]==b[y-1])
                {
                    arr[x][y] = 1 + arr[x-1][y-1];
                }
                else
                {
                    arr[x][y] = max(arr[x-1][y],arr[x][y-1]);
                }
                
                
                
            }
        }
          
        
        int n_l = n-arr[n][m];
         int m_l = m-arr[n][m];
         cout<<n_l<<" "<<m_l<<endl;
         if(n_l==m_l)cout<<n_l<<endl;
         else if(n_l>m_l)cout<<n_l<<endl;
         else cout<<m_l<<endl;
          
    }
}
