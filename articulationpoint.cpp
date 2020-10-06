#include<iostream>
#include <list>
#define N -1
using namespace std;
class G {
   int n;
   list<int> *adj;
   //declaration of functions
   void APT(int v, bool visited[], int dis[], int low[],
   int par[], bool ap[]);
   public:
      G(int n); //constructor
      void addEd(int w, int x);
      void AP();
};
G::G(int n) {
   this->n = n;
   adj = new list<int>[n];
}
//add edges to the graph
void G::addEd(int w, int x) {
   adj[x].push_back(w); //add u to v's list
   adj[w].push_back(x); //add v to u's list
}
void G::APT(int w, bool visited[], int dis[], int low[], int par[], bool ap[]) {
   static int t=0;
   int child = 0; //initialize child count of dfs tree is 0.
   //mark current node as visited
   visited[w] = true;
   dis[w] = low[w] = ++t;
   list<int>::iterator i;
   //Go through all adjacent vertices
   for (i = adj[w].begin(); i != adj[w].end(); ++i) {
      int x = *i; //x is current adjacent
      if (!visited[x]) {
         child++;
         par[x] = w;
         APT(x, visited, dis, low, par, ap);
         low[w] = min(low[w], low[x]);
         // w is an articulation point in following cases :
         // w is root of DFS tree and has two or more chilren.
         if (par[w] == N && child> 1)
            ap[w] = true;
         // If w is not root and low value of one of its child is more than discovery value of w.
         if (par[w] != N && low[x] >= dis[w])
            ap[w] = true;
      } else if (x != par[w]) //update low value
         low[w] = min(low[w], dis[x]);
   }
}
void G::AP() {
   // Mark all the vertices as unvisited
   bool *visited = new bool[n];
   int *dis = new int[n];
   int *low = new int[n];
   int *par = new int[n];
   bool *ap = new bool[n];
   for (int i = 0; i < n; i++) {
      par[i] = N;
      visited[i] = false;
      ap[i] = false;
   }
   // Call the APT() function to find articulation points in DFS tree rooted with vertex 'i'
   for (int i = 0; i < n; i++)
      if (visited[i] == false)
         APT(i, visited, dis, low, par, ap);
      //print the articulation points
      for (int i = 0; i < n; i++)
         if (ap[i] == true)
            cout << i << " ";
}
int main() {
   cout << "\nArticulation points in first graph \n";
   G g1(5);
   g1.addEd(1, 2);
   g1.addEd(3, 1);
   g1.addEd(0, 2);
   g1.addEd(2, 3);
   g1.addEd(0, 4);
   g1.AP();
   return 0;
}
