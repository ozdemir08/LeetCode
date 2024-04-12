class Solution {

private:
	int dir[4][2]{{-1,0}, {1,0}, {0, 1}, {0, -1}};
	vector< vector<char> > grid;
	vector< vector<bool> > visited;
	int n, m;

	void dfs(int i, int j){
		visited[i][j] = true;
		for(int y=0;y<4;y++){
			int ni = i + dir[y][0];
			int nj = j + dir[y][1];
			if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[i][j] && grid[i][j] == '1')
				dfs(ni, nj);
		}
	}

public:
    int numIslands(vector<vector<char>>& gr) {
    	grid = gr;
    	n = grid.size();
    	if(!n) return 0;
    	m = grid[0].size();

    	visited = vector< vector<bool> >(n, vector<bool>(m, false));

    	int res = 0;
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++)
    			if(!visited[i][j] && grid[i][j] == '1'){
    				dfs(i, j);
    				res ++;
    			}
    	return res;
    }
};