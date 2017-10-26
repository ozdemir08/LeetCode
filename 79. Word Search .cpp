class Solution {
private:
    int dir[4][2]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool exist(int pos, int i, int j, vector<vector<char>>& board, string& word) {
        if(pos == word.length())
            return true;
        char c = board[i][j];
        // mark as visited.
        board[i][j] = ' ';
        bool res = false;
        for(int y=0;y<4;y++){
            int ni = i + dir[y][0];
            int nj = j + dir[y][1];
            if(ni>=0 && ni<board.size() && nj>=0 && nj<board[0].size() && board[ni][nj] == word[pos]){
                res = exist(pos+1, ni, nj, board, word);
                if(res)
                    break;
            }
        }
        board[i][j] = c;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if(!n)
            return (word == "");
        int m = board[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j] == word[0]){
                    bool res = exist(1, i, j, board, word);
                    if(res)
                        return true;
                }
        return false;
    }
};