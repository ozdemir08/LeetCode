class Solution {
private:
	int dir[4][2]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	int N, M;
	vector< pair<int,int> > dfs(int i, int j, vector < vector<bool> >& visited, vector< vector<char> > &board){
		queue< pair<int,int> > positionsQueue;
		vector< pair<int,int> > region;

		positionsQueue.push(make_pair(i,j));
		while(!positionsQueue.empty()){
			pair<int,int> pos = positionsQueue.front();
			int x = pos.first;
			int y = pos.second;
			positionsQueue.pop();
			
			visited[x][y] = true;
			region.push_back(pos);

			for(int i=0;i<4;i++){
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if(nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] == 'O' && !visited[nx][ny]){
					positionsQueue.push(make_pair(nx, ny));
				}
			}
		}
		return region;
	}

	bool isSurroundedByXs(vector< pair<int,int> > &region, vector< vector<char> > &board){
		for(int i=0;i<region.size();i++){
			int x = region[i].first, y = region[i].second;
			if(!x || x == N-1 || !y || y == M-1)
				return false;
		}
		return true;
	}

	void markRegion(vector< pair<int,int> > &region, vector< vector<char> > &board){
		for(int i=0;i<region.size();i++){
			int x = region[i].first, y = region[i].second;
			board[x][y] = 'X';
		}
	}

public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        
        N = board.size();
        M = board[0].size();
        
        vector < vector<bool> > visited(N, vector<bool>(M));
        vector< pair<int,int> > region;
        for(int i=0;i<N;i++)
        	for(int j=0;j<M;j++)
        		if(!visited[i][j] && board[i][j] == 'O'){
        			region = dfs(i,j, visited, board);
        			if(isSurroundedByXs(region, board)){
        				markRegion(region, board);
        			}
        		}
    }
};