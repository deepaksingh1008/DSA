class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        
         sort(v.begin(),v.end());
        int i = 0, j=v.size()-1,ans=0;
        while(i<=j){
            if(j-1>=i&&v[j]+v[j-1]<=limit){
                j-=2;
            }
            else if(v[j]+v[i]<=limit){
                j--;i++;
            }else{
                j--;
            }
            ans++;
        }
        return ans;
    }
};