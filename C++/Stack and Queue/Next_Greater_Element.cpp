/*
Ishita Jain
Jaypee University of Engineering and Technology
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       stack<int> s;
        vector<int> v;
        int k=0;
        for(int i=0;i<nums1.size();i++){
            k=0;
            // s.clear();
             while(!s.empty()){
                 s.pop();
             }
             for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                     k=j;
                     break;
                 }
             }
             int flag=0;
             for(int a=k;a<nums2.size()-1;a++){
                
                  if(s.empty()){
                      s.push(nums2[a]);
                  }
                     
               
                if(nums2[a+1]>s.top()){
                    v.push_back(nums2[a+1]);
                    flag=1;
                    break;
                }
             }
             if(flag==0){
                v.push_back(-1);
            }
         }
        return v;
    }
};