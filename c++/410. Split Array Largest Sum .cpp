class Solution {
private:
	long long splitArray(int pos, int m, vector<int>& nums, vector< vector<long long> >& DP){
		if(DP[m][pos])
			return DP[m][pos];
        
        int N = nums.size();
        
        // found a solution
		if(pos == N && m == 0)
			return 0;
        
        // no solution here
		if(pos == N || m == 0)
			return INT_MAX;

		long long sum = 0;
		long long res = INT_MAX;

		// try splitting from ith index
		for(int i=pos;i<N;i++){
			sum += nums[i];
			long long subres = splitArray(i+1, m-1, nums, DP);		
			res = min(res, max(subres, sum));
			if(sum > subres)
				break;
		}

		DP[m][pos] = res;
		return res;
	}

public:
    int splitArray(vector<int>& nums, int m) {
        vector< vector<long long> > DP(m+1, vector<long long>(nums.size() + 1, 0));
        return (int)splitArray(0, m, nums, DP);
    }
};