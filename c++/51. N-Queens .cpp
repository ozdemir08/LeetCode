class Solution {
private:
    vector<bool> column, diagonal1, diagonal2;
    int N;
    vector< vector<string> > res;
    vector<string> currentSolution;

    void init(int n){
        N = n;

        column =  vector<bool>(N, false);
        diagonal1 = vector<bool>(2*N, false);
        diagonal2 = vector<bool>(2*N, false);
        currentSolution = vector<string>(N, string(N, '.'));
    }

    bool checkBoard(int row, int col){

        // another queen in the same column
        if(column[col])
            return false;

        // another queen in same diag(from right-top to left-bot)
        int diag1Index = row + col;
        if(diagonal1[diag1Index])
            return false;

        // another queen in same diag(from left-top to right-bot)
        int diag2Index = row - col + N; // to prevent negative indices
        if(diagonal2[diag2Index])
            return false;

        return true;
    }

    void toggleQueen(int row, int col, bool status){
        column[col] = status;

        int diag1Index = row + col;
        diagonal1[diag1Index] = status;

        int diag2Index = row - col + N;
        diagonal2[diag2Index] = status;
        currentSolution[row][col] = (status ? 'Q' : '.');
    }

    void putQueen(int row, int col){
        toggleQueen(row, col, true);
    }


    void removeQueen(int row, int col){
        toggleQueen(row, col, false);
    }

    void findSolution(int row){
        if(row == N){
            res.push_back(currentSolution);
            return;
        }

        for(int i=0;i<N;i++)
            if(checkBoard(row, i)){
                putQueen(row, i);
                findSolution(row + 1);
                removeQueen(row,i);
            }
    }


public:
    vector<vector<string>> solveNQueens(int n) {
        init(n);
        findSolution(0); 
        return res;
    }
};