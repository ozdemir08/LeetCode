class Solution {
public:
    bool canCross(vector<int>& stones) {
        int N = stones.size();

        // DP[i][j] means ith stone is reached by j jump
        vector< vector<bool> > DP(N+2, vector<bool>(N+2, false));
        DP[0][0] = 1;
        
        unordered_map<int, int> posToIndex;
        for(int i=0;i<N;i++){
            int pos = stones[i];
            posToIndex[pos] = i;
        }
        
        // try all jumps from stones[i] 
        for(int i=0;i<N;i++){
            int pos = stones[i];
            for(int k=0;k<N;k++){
                if(!DP[i][k])
                    continue;
                
                int next = pos + k;
                
                // k-1 jump
                if(k-1 > 0 && posToIndex.find(next-1) != posToIndex.end()){
                    int nextPos = posToIndex[next-1];
                    DP[nextPos][k-1] = true;
                }
                
                // k jump
                if(posToIndex.find(next) != posToIndex.end()){
                    int nextPos = posToIndex[next];
                    DP[nextPos][k] = true;
                }
                
                // k+1 jump
                if(posToIndex.find(next+1) != posToIndex.end()){
                    int nextPos = posToIndex[next+1];
                    DP[nextPos][k+1] = true;
                }
            }
        }
         
        // check if last stone is reached
        for(int k=0;k<=N;k++)
            if(DP[N-1][k])
                return true;
        return false;
    }
};