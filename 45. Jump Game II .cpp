class Solution {
public:
    int jump(vector<int>& jumps) {
        int pos = 0, maxLimit = 0, step = 0, N = jumps.size();
        while(pos < N){
        	int nextLimit = maxLimit;
        	while(pos <= maxLimit){
        		if(pos == N-1)
        			return step;

        		nextLimit = max(nextLimit, pos + jumps[pos]);
        		pos++;
        	}
        	step++;

        	// couldn't reach
        	if(maxLimit == nextLimit)
        		break;
        	maxLimit = nextLimit;
        }
        // couldn't reach
        return -1;
    }
};