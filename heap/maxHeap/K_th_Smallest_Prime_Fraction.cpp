//question-link = https://leetcode.com/problems/k-th-smallest-prime-fraction/



class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

     
        vector<int> ans(2); 
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>> pq;
       
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double fraction = static_cast<double>(arr[i]) / arr[j];
                if(pq.size() < k) {
                    pq.push({fraction, {i, j}});
                } else {
                    if(pq.size() == k && pq.top().first > fraction) {
                        pq.pop();
                        pq.push({fraction, {i, j}});
                    }
                }
            }
        }
        
      
        auto top_fraction = pq.top().second;
        ans[0] = arr[top_fraction.first];
        ans[1] = arr[top_fraction.second];
        
        return ans;
    }
};