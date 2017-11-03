class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int N = nums.size();
        vector< unordered_map<int, int> > M(N, unordered_map<int, int>());
        int res = 0;
        for(int i=N-1;i>=0;i--){
        	for(int j=i+1;j<N;j++){
        		int dif = nums[j] - nums[i];
        		M[i][dif] = M[j][dif] + 1;
        		res += max(0, M[i][dif] - 2);
        	}
        }
        return res;
    }
};