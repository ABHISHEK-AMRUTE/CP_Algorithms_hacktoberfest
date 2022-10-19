/*
Ishita Jain
Jaypee University of Engineering and Technology*/


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        
        for(int i=0;i<s.length();i++){
            
           
             if(s[i]=='#' && !s1.empty()){
                s1.pop();
            }
            else if(s[i]=='#' && s1.empty()){
                continue;
            }
            else{
                s1.push(s[i]);
            }
            
        }
        for(int i=0;i<t.length();i++){
           
         if(t[i]=='#' && !s2.empty()){
                s2.pop();
            }
            else if(t[i]=='#' && s2.empty()){
                continue;
            }
            else{
                s2.push(t[i]);
            }
        }
        string str1="";
        string str2="";
        
        while(!s1.empty()){
            str1.push_back(s1.top());
            s1.pop();
        }
         while(!s2.empty()){
            str2.push_back(s2.top());
            s2.pop();
        }
       
        if(str1==str2){
            return true;
        }
        return false;
    }
};