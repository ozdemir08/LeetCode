class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int N = ghosts.size();
        int ourDistance = abs(target[0]) + abs(target[1]);

        for(vector<int> &ghost : ghosts){
            int ghostDistance = abs(ghost[0] -target[0]) + abs(ghost[1] - target[1]);
            if(ghostDistance <= ourDistance)
                return false;
        }

        return true;
    }
};