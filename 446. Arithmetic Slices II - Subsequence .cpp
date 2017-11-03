class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int N = nums.size();
        vector< unordered_map<int, int> > M(N, unordered_map<int, int>());
        int res = 0;
        for(int i=N-1;i>=0;i--){
        	// Look all subsequences starts with nums[i]
        	for(int j=i+1;j<N;j++){
        		// Look all subsequences whose difference is nums[j]-nums[i]
        		long long dif = (long long)nums[j] - nums[i];
                if(dif >= INT_MAX || dif <= INT_MIN)
                    continue;
        		M[i][dif] += M[j][(int)dif] + 1;
        		res += M[j][dif];
        	}
        }
        return res;
    }
};