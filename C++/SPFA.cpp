//Shortest Path Faster Algorithm(SPFA) - Based on Bellman-Ford Algorithm
// Algorithm used on "Coins respawn - At Coder"
// Abraão Caiana de Freitas - Universidade Federal de Campina Grande
#include <bits/stdc++.h>
using namespace std;
#define maxx 100010
#define mp make_pair
typedef pair <int,int> ii;

int ans[maxx],visited[maxx];
vector < ii > ladj[maxx];
map <int, int> dicio;
int n,m,p = 0;
int nos = 0;
vector < int > dist;

void dfs(int x)
{
	visited[x] = 1;
	for(auto e: ladj[x])
  {
		if(visited[e.second] == 0) dfs(e.second);
	}
}

//main spfa
const int INF = -1e9;
bool spfa(int s) 
{
    int N = n+1;
    dist.assign(N, INF);
    vector < int > cnt(N, 0);
    vector < bool > inqueue(N, false);
    queue < int > q;
	  N = nos;
	
    dist[s] = 0;
    q.push(s);
    inqueue[s] = true;
	  while (!q.empty()) 
    {
		    int atual = q.front();
        q.pop();
        inqueue[atual] = false;
        for (auto edge : ladj[atual]) 
        {
            int peso = edge.first - p;
		        int next = edge.second;

            if (dist[atual] + peso > dist[next] && ans[next] == 1) 
            {
                dist[next] = dist[atual] + peso;
                if (!inqueue[next]) 
                {
                    q.push(next);
                    inqueue[next] = true;
                    cnt[next]++;
                    if (cnt[next] > N)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}
vector < int > help; 

int main() {
	cin >> n >> m >> p;
	
	int a, b, weight;
	for(int i = 1; i <= m; i++)
  {
		cin >> a >> b >> weight;
		ladj[a].push_back(mp(weight,b));
	}
  
	dfs(1);
	bool flag = true;
	if(visited[n] == 1)
  {
		ans[1] = 1;
		nos++;
		for(int i = 2; i <= n;i++)
    {
			for(int j = 1; j <= n+1; j++)
          visited[j] = 0;
          
			dfs(i);
			if(visited[1] == 1 || visited[n] == 1)
      {
          nos++;
          ans[i] = 1;
      }
		}
		flag = spfa(1);
	}	

	if(flag == true)
      cout << max(0,dist[n]) << endl;
	else
      cout << -1 << endl;
      
	return 0;
}
