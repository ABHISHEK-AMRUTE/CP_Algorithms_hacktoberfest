#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int rodcutbu(vector<int> v, int n)
{
    vector<int> dp(n+1, 0);

   
    dp[0]=0;
    int best = 0;

    for(int i=1;i<=n;i++)
    {
        

        for (int j = 1; j <= i; j++)
        {
            int k = v[j-1] + dp[i - j];
            best = max(best, k);
       }
      dp[i]=best;
    }

    for(int i=0;i<=n;i++)
    cout<<dp[i]<<" ";
    cout<<endl;

return best;

}

int rodcut(vector<int> v,int n)
{
if(n==0)
return 0; 



int best=0;

for(int i=0;i<n;i++)
{
    int k=v[i]+rodcut(v,n-1-i);
    best=max(best,k);
}

return best;

}

int main()
{
vector<int> v{1,3,2,5};
int n=v.size();

cout << rodcut(v, n)<<endl;
 cout << rodcutbu(v, n);
}