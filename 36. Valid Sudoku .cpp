class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        bool ver[10][10] = {}, hor[10][10] = {}, sq[10][10] = {};
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                int x = board[i][j] - '0';
                int s = 3*(i/3) + (j/3);
                if(ver[i][x] || hor[j][x] || sq[s][x])
                    return false;
                ver[i][x] = true;
                hor[j][x] = true;
                sq[s][x] = true;
            }
        return true;
    }
};