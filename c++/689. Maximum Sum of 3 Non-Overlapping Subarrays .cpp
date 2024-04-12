/*
    This solution uses O(N) space. But it can also be solved 
    without DP, using only three pointers. 
*/

class Solution {
private:
    vector< vector<int> > DP;
    vector< vector<bool> > flag;
    vector<int> sum;
    int N, K;
    
    int findSubArraySum(int i){
        if(!i)
            return sum[K-1];
        return sum[i+K-1] - sum[i-1];
    }
    
    void init(vector<int>&nums, int k){
        N = nums.size();
        K = k;
        // +1 s for edge cases.
        DP = vector< vector<int> >(4, vector<int>(N+1, 0));
        flag = vector< vector<bool> >(4, vector<bool>(N+1, false));
        sum = vector<int>(N, 0);
        sum[0] = nums[0];
        for(int i=1;i<N;i++)
            sum[i] = sum[i-1] + nums[i];
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        init(nums, k);
        
        // fill DP
        for(int i=1;i<=3;i++)
            for(int j=N-K;j>=0;j--){
                // Due to N+1 in DP's definition, no need to handle edge cases.
                int right = DP[i][j+1];
                int bottom = findSubArraySum(j) + DP[i-1][j+K];
                if(bottom >= right){
                    DP[i][j] = bottom;
                    // flag shows ith subarray starts with jth column
                    flag[i][j] = true;
                }
                else
                    DP[i][j] = right;
            }
        
        // find begin index of three row.
        vector<int> res;
        int i=3, j=0;
        while(i>0 && j<=N-1){
            if(flag[i][j]){
                res.push_back(j);
                i--;
                j+=K;
            }
            else
                j++;
        }

        return res;
    }
};