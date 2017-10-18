#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int N, M;
	vector< vector<int> > DP;
	int dir[4][2]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int longestIncreasingPath(vector<vector<int> >& matrix, int i, int j) {
    	if(DP[i][j] > 0)
    		return DP[i][j];

    	int res = 0;
    	for(int y=0;y<4;y++){
    		int ni = i + dir[y][0];
    		int nj = j + dir[y][1];
    		if(ni >= 0 && ni < N && nj >= 0 && nj < M && matrix[ni][nj] > matrix[i][j]){
    			int subres = longestIncreasingPath(matrix, ni, nj);
    			res = max(res, subres);
    		}
    	}
    	DP[i][j] = res + 1;
    	return DP[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
    	if(matrix.empty())
    		return 0;

    	int res = 0;
    	N = matrix.size();
    	M = matrix[0].size();
        DP = vector< vector<int> >(N, vector<int>(M, 0));
        for(int i=0;i<N;i++)
        	for(int j=0;j<M;j++)
        		res = max(res, longestIncreasingPath(matrix, i, j));

    	return res;
    }
};


int main(){

}