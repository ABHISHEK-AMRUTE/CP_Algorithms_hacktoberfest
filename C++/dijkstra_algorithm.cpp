/*
SOUMIK MUKHERJEE
Kalinga Institute Of Industrial Technology, Bhubaneshwar
BTech CSE, 1st year
*/

#include<iostream>
#include<stdio.h>

using namespace std;

#define INFINITY 9999  //preprocessor directive

#define max 5         //preprocessor directive

void dijkstra(int A[max][max],int n,int nodeBegin); //function prototype

int main() {    //main funtion: the excution of the program starts from fere

   int A[max][max]={{0,1,0,3,10},{1,0,5,0,0},{0,5,0,2,1},{3,0,2,0,6},{10,0,1,6,0}};
   int n=5;
   int t=0;
   dijkstra(A,n,t);
   return 0;
}


void dijkstra(int A[max][max],int n,int nodeBegin) {  //DIJKSTRA's ALGO function definition
   int c1[max][max],distance[max],pred[max];
   int visited[max],c2,mindistance,nextnode,i,j;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(A[i][j]==0)
      c1[i][j]=INFINITY;
   else
      c1[i][j]=A[i][j];
   for(i=0;i<n;i++) {
      distance[i]=c1[nodeBegin][i];
      pred[i]=nodeBegin;
      visited[i]=0;
   }
   distance[nodeBegin]=0;
   visited[nodeBegin]=1;
   c2=1;
   while(c2<n-1) {
      mindistance=INFINITY;
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i]) {
         mindistance=distance[i];
         nextnode=i;
      }
      visited[nextnode]=1;
      for(i=0;i<n;i++)
         if(!visited[i])
      if(mindistance+c1[nextnode][i]<distance[i]) {
         distance[i]=mindistance+c1[nextnode][i];
         pred[i]=nextnode;
      }
      c2++;
   }
   
   for(i=0;i<n;i++)
   if(i!=nodeBegin) {
      cout<<"\n Node "<<i<<" distance= "<<distance[i];
      cout<<"\nPath="<<i;
      j=i;
      do {
         j=pred[j];
         cout<<"<-"<<j;
      }while(j!=nodeBegin);
   }
}
