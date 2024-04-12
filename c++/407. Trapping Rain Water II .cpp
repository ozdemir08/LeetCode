class Cell{
public:
	int height;
	int i, j;
	Cell(int x, int y, int h){
		i = x;
		j = y;
		height = h;
	}
};

class Compare{
public:
    bool operator() (Cell& a, Cell& b){
        return a.height > b.height;
    }  
};

class Solution {
private:
	int dir[4][2]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	void dfs(Cell cur, vector<vector<int>>& heightMap, vector<Cell>& component, vector< vector<bool> >& visited, int& limit){
		if(!cur.i || cur.i+1 == heightMap.size() || !cur.j || cur.j+1 == heightMap[0].size())
			return;
		// put to component to update heightmap and done later.
		component.push_back(cur);

		// find limit height
		for(int y=0;y<4;y++){
			int ni = cur.i + dir[y][0];
			int nj = cur.j + dir[y][1];
			if(heightMap[ni][nj] != cur.height || !ni || ni+1 == heightMap.size() || !nj || nj+1 == heightMap[0].size())
				limit = min(limit, heightMap[ni][nj]);
		}

        // mark as visited
        visited[cur.i][cur.j] = true;

		// dfs to cells with same height
		for(int y=0;y<4;y++){
			int ni = cur.i + dir[y][0];
			int nj = cur.j + dir[y][1];
			if(heightMap[ni][nj] == cur.height && !visited[ni][nj])
				dfs(Cell(ni, nj, cur.height), heightMap, component, visited, limit);
		}
	}
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int N = heightMap.size();
        if(!N)
            return 0;
        int M = heightMap[0].size();
        int res = 0, minHeight = 0;
        vector< vector<bool> > startFrom(N, vector<bool>(M, false)); //

        // add each cell to queue
        priority_queue<Cell, vector<Cell>, Compare> q;

        for(int i=1;i<N-1;i++)
        	for(int j=1;j<M-1;j++)
        		q.push(Cell(i, j, heightMap[i][j]));

        while(!q.empty()){

        	Cell cur = q.top();
        	q.pop();
            
			// for each component, starting dfs from just one cell is enough
        	if(!startFrom[cur.i][cur.j]){

        		int limit = INT_MAX;
        		vector<Cell> component;
                vector< vector<bool> > visited(N, vector<bool>(M, false));
        		dfs(cur, heightMap, component, visited, limit);

        		// water can be trapped into this component
        		if(limit > cur.height){
        			for(int i=0;i<component.size();i++){
        				Cell c = component[i];
        				res += limit - c.height;
        				heightMap[c.i][c.j] = limit;
        			}
        			q.push(Cell(cur.i, cur.j, limit));
        		}
        		// cell at 0, represents this component.
        		for(int i=1;i<component.size();i++){
        			Cell c = component[i];
        			startFrom[c.i][c.j] = true;
        		}
        	}
        }

        return res;
    }
};