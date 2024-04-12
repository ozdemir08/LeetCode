class Solution {
private:
    int findMaxCoins(int i, int j, vector< vector<int> >& DP, vector<int>& balloons){
        if(j-i < 2)
            return 0;
        int& res = DP[i][j];
        if(res)
            return res;
        
        for(int k=i+1;k<j;k++){
            int subres = balloons[i] * balloons[k] * balloons[j] + findMaxCoins(i, k, DP, balloons) + findMaxCoins(k, j, DP, balloons);
            res = max(res, subres);
        }
        return res;
    }
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size() + 2;
        vector<int> balloons(N, 1);
        copy(nums.begin(), nums.end(), balloons.begin()+1);
        
        vector< vector<int> > DP(N, vector<int>(N, 0));
        return findMaxCoins(0, N-1, DP, balloons);
    }
};