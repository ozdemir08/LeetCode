class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    	int n = dungeon.size();
    	if(!n) return 0;
    	int m = dungeon[0].size();

        vector< vector<int> > DP(2, vector<int>(m, 0));
        DP[0][m-1] = max(1-dungeon[n-1][m-1], 1);
    	
    	// last row
        for(int j=m-2;j>=0;j--)
        	DP[0][j] = max(1, DP[0][j+1] - dungeon[n-1][j]);

    	// cur row, prev row
    	int cur = 1, prev = 0;
    	for(int i=n-2;i>=0;i--){
    		// last column of cur row
    		DP[cur][m-1] = max(DP[prev][m-1] - dungeon[i][m-1], 1);

    		// rest of row
    		for(int j=m-2;j>=0;j--){
    			int right = DP[cur][j+1];
    			int bottom = DP[prev][j];
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