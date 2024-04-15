// Maximum Length of a Concatenated String with Unique Characters

class Solution {
public:
 bool isDuplicate(string &s1,string &s2){
     vector<int> v(26,0);
     for(char &ch : s1){
         if(v[ch-'a']>0)
           return true;
         v[ch-'a']++;
     }
     for(char &ch:s2){
         if(v[ch-'a']>0)
             return true;
         v[ch-'a']++;
     }
     
     return false;
 }
    int solve(int i,string temp,vector<string> &arr,int n){
        if(i>=n){
            return temp.length();
        }
        int inc = 0;
        int exc = 0;
        if(isDuplicate(arr[i],temp)){
            exc = solve(i+1,temp,arr,n);
      }
        else{
            exc = solve(i+1,temp,arr,n);
            inc= solve(i+1,temp+arr[i],arr,n);
       }
        return max(exc,inc);
    }
    
    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        return solve(0,temp,arr,n);
    }
};