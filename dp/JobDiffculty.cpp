class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& jd, int idx, int d, int n){
        if(dp[idx][d]!=-1) return dp[idx][d];
        if(d == 1){
            int maxi = jd[idx];
            for(int i = idx + 1; i < n; i++){
                maxi = max(maxi, jd[i]);
            }
            return maxi;
        }
        
        int maxJob = INT_MIN;
        int finaljob = INT_MAX;
        for(int i = idx; i <= n - d; i++){
            maxJob = max(maxJob, jd[i]);
            int result = maxJob + solve(jd, i + 1, d - 1, n);
            finaljob = min(finaljob, result);
        }
        return dp[idx][d]=finaljob;
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        dp = vector<vector<int>>(n+1,vector<int>(d+1,-1));
        if(d > n)
            return -1;
        return solve(jd, 0, d, n);
    }
};
