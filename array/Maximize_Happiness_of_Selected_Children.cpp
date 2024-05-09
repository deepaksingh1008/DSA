question_link = https://leetcode.com/problems/maximize-happiness-of-selected-children/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n = h.size();
        sort(h.begin(),h.end());
        long long sum = 0;
        long long temp = 0;
        for(int i=n-1;i>=0;i--){
            if(h[i]>0 and h[i]-temp>0 and k>0){
             sum+=h[i]-temp;
                temp++;
                k--;
            }
            
            
        }
        return sum;
    }
};