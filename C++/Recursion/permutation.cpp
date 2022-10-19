  vector<vector<int>> finans;

  void helper(vector<int> &v,vector<int>& vis,vector<int> ans={}){
      if(ans.size()==v.size()){
          finans.push_back(ans);
          return;
      }
      for(int i=0;i<v.size();i++){
          if(vis[i]) continue;
          ans.push_back(v[i]);
          vis[i]=1;
          helper(v,vis,ans);
          vis[i]=0;
          ans.pop_back();
      }
  }

  vector<vector<int>> permute(vector<int>& v) {
      vector<int> vis(v.size(),0);
      helper(v,vis);
      return finans;
  }

int main(){
  vector<int> v={1,2,3,4,5};
  vector<vector<int>> ans=permute(v);
  for(auto vec:ans){
    for(auto val: vec){
      cout<<val<<" " ;
    }
    cout<<endl;
  }
  return 0;
}
