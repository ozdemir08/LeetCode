class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    	int n = dungeon.size();
    	if(!n) return 0;
    	int m = dungeon[0].size();

        vector< vector<int> > DP(2, vector<int>(m, 0));
    	
    	// cur row, prev row
    	int cur = 1, prev = 0;
    	DP[prev][m-1] = 1;
    	for(int i=n-1;i>=0;i--){
    		// last column of cur row
    		DP[cur][m-1] = max(DP[prev][m-1] - dungeon[i][m-1], 1);

    		// rest of row
    		for(int j=m-2;j>=0;j--){
    			int right = DP[cur][j+1];
    			int bottom = (i == n-1 ? INT_MAX : DP[prev][j]);
                int point = min(right, bottom) - dungeon[i][j];
    			DP[cur][j] = max(1, point);
    		}
    		cur = 1 - cur;
    		prev = 1 - prev;
	    }
	    int res = DP[prev][0];
	    return res;
	}
};