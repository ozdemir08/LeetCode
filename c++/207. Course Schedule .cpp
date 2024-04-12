
class Solution {
private:
	void dfs(int lec, vector< vector<int> >& prerequisites, vector<bool>& visited, int& visitedNum, vector<int>& incoming){
		
		visited[lec] = true;
		visitedNum++;

		int m = prerequisites[lec].size();
		
		for(int i=0;i<m;i++){
			int next = prerequisites[lec][i];
			incoming[next]--;
			if(!incoming[next])
				dfs(next, prerequisites, visited, visitedNum, incoming);
		}
	}

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisitesAsPair) {
        vector< vector<int> > prerequisites(numCourses, vector<int>());
        vector<bool> visited(numCourses, false);
        vector<int> incoming(numCourses, 0);
        for(int i=0;i<prerequisitesAsPair.size();i++){
        	int c = prerequisitesAsPair[i].first;
        	int p = prerequisitesAsPair[i].second;
        	prerequisites[c].push_back(p);
        	incoming[p] ++;
    	}

    	int visitedNum = 0;
    	for(int i=0;i<numCourses;i++)
    		if(!incoming[i] && !visited[i])
    			dfs(i, prerequisites, visited, visitedNum, incoming);

    	return (visitedNum == numCourses);
    }	
};