#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<bool> column, diagonal1, diagonal2;
    int N;

	void init(int n){
    	N = n;

        for(int i=0;i<N;i++){
            column.push_back(false);
        }

        for(int i=0;i<2*N-1;i++){
            diagonal1.push_back(false);
            diagonal2.push_back(false);
        }
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
    }

    void putQueen(int row, int col){
    	toggleQueen(row, col, true);
    }


    void removeQueen(int row, int col){
		toggleQueen(row, col, false);
    }

	int findSolution(int row){
		if(row == N)
			return 1;

		int res = 0;

		for(int i=0;i<N;i++)
			if(checkBoard(row, i)){
				putQueen(row, i);
				int newResults = findSolution(row + 1);
				res += newResults;
				removeQueen(row,i);
			}
		return res;
	}


public:
    int totalNQueens(int n) {
        init(n);
		return findSolution(0); 
    }
};

int main(){
	Solution s;
	cout << s.totalNQueens(1) << endl;
	cout << s.totalNQueens(2) << endl;
	cout << s.totalNQueens(3) << endl;
	cout << s.totalNQueens(4) << endl;
}