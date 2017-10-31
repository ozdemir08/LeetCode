class Solution {
private:
    bool horizontal[9][10], vertical[9][10], square[9][10];
    
    bool check(int i, int j, int num){
        int sq = 3*(i/3) + j/3;
        if(horizontal[i][num] || vertical[j][num] || square[sq][num])
            return false;
        return true;
    }
    
    void toggle(int i, int j, int num, bool val, vector<vector<char>>& board){
        int sq = 3*(i/3) + j/3;
        horizontal[i][num] = val;
        vertical[j][num] = val;
        square[sq][num] = val;
        
        if(val)
            board[i][j] = num + '0';
        else
            board[i][j] = '.';
    }
    
    void put(int i, int j, int num, vector<vector<char>>& board){
        toggle(i, j, num, true, board);
    }
    
    void remove(int i, int j, int num, vector<vector<char>>& board){
        toggle(i, j, num, false, board);
    }
    
    bool solveSudoku(vector<vector<char>>& board, int i, int j) {
        if(i == 9)
            return true;

        int ni = i + (j+1)/9, nj = (j+1) % 9;
        if(board[i][j] != '.'){
            return solveSudoku(board, ni, nj);
        }

        for(int k=1;k<=9;k++)
            if(check(i, j, k)){
                put(i, j, k, board);
                bool res = solveSudoku(board, ni, nj);
                if(res)
                    return true;
                remove(i, j, k, board);
            }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j] != '.'){
                    int val = board[i][j] - '0';
                    horizontal[i][val] = true;
                    vertical[j][val] = true;
                    int sq = 3*(i/3) + j/3;
                    square[sq][val] = true;
                }
        solveSudoku(board, 0, 0);
    }
};