#include<bits/stdc++.h>

using namespace std;
#define ll long long
class Hash {
    int Buckets;
    vector<ll> *table;
    public: Hash(ll n){
                Buckets = n;
                table = new vector<ll>[Buckets];
            }
            int hashing(ll key){
                return key % Buckets;
            }
            void insertion(ll key ){
                ll ind = hashing(key );
                table[ind].emplace_back(key);
            }
            void deletion(ll key){
                ll ind = hashing(key);
                vector<ll>::iterator itr ;
                for(itr = table[ind].begin() ; itr!= table[ind].end() ; ++itr){
                    if(*itr == key){
                        break;
                    }
                }
                if(itr != table[ind].end()){
                    table[ind].erase(itr);
                }
            }
            void display(){
                for(int i = 0 ; i < Buckets ; ++i ){
                    for(int j = 0 ; j < table[i].size() ; ++j ){
                        cout<<table[i][j]<<"-->";
                    }
                    cout<<endl;
                }
            }
};
int main(){
    vector<ll> arr = {15 , 12 ,17 , 49 , 42};
    
    ll n = 5;
    Hash h(10);
    for (int i = 0; i < n; i++)  
        h.insertion(arr[i]);   
  
    // h.deletion(12); 
    h.display(); 
  
    return 0;
}