class Solution {
private:
	vector<int> graph[1002];
	int N;
    int cycleBeginNode = -1;

	void dfsForCycle(int pos, vector<int>& nodes, unordered_set<int>& visited){
        cout << pos << endl;
		nodes.push_back(pos);
		if(visited.find(pos) != visited.end()){
            cycleBeginNode = pos;
			return;
        }
		visited.insert(pos);

		for(int i=0;i<graph[pos].size();i++){
			int next = graph[pos][i];
			dfsForCycle(next, nodes, visited);
		}
	}
    
    int findRoot(unordered_map<int, int>& parent){
        for(int i=1;i<=N;i++)
            if(parent.find(i) == parent.end())
                return i;
        
        // no root
        return -1;
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    	int M = edges.size();
    	
    	// case 1: a node has two parents
    	unordered_map<int, int> parent;
        vector< vector<int> > candidates(2, vector<int>());
        bool twoParent = false;
    	for(int i=0;i<M;i++){
    		int from = edges[i][0];
    		int to = edges[i][1];
    		graph[from].push_back(to);
    		N = max(N, max(from, to));
    		if(parent.find(to) == parent.end())
    			parent[to] = from;
    		else{
                twoParent = true;
                candidates[0].push_back(parent[to]);
                candidates[0].push_back(to);
                candidates[1].push_back(edges[i][0]);
                candidates[1].push_back(edges[i][1]);
            }
	    }
        
        vector<int> nodes;
	    unordered_set<int> visited;
        
        if(twoParent){
            int from = candidates[1][0], to = candidates[1][1];
            cout << from << ' ' << to << endl;
            
            // remove last candidate edge and try             
            graph[from][to] = 0;
            dfsForCycle(findRoot(parent), nodes, visited);
            cout << nodes.size() << endl;
            if(nodes.size() == N+1){
                return candidates[1];
            }
            return candidates[0];
        }

	    // case 2: there is a loop

        for(int i=1;i<=N;i++){
            dfsForCycle(i, nodes, visited);
            if(cycleBeginNode != -1)
                break;
        }

	    // find nodes that compose cycle.
	    vector<int> cycle;
	    for(int i=nodes.size()-2;i>=0;i--){
	    	int n = nodes[i];
	    	cycle.push_back(n);
	    	if(n == nodes.back())
	    		break;
	    }

	    // i -> i+1 is an edge. We should remove one of this edges. 

	    // To make this operation in O(N), express each edge as e[0] + N*e[1]
	    // and map it to index
	    unordered_map<int, int> edgeToIndex;
	    for(int i=0;i<M;i++){
	    	int edge = edges[i][0] + M * edges[i][1];
	    	edgeToIndex[edge] = i;
	    }

	    // find the edge in cycle, which has maximum index.
	    int maxIndex = -1;

	    int K = cycle.size();
	    for(int i=0;i<K-1;i++){
	    	int edge = cycle[i] * M + cycle[i+1];
	    	int ind = edgeToIndex[edge];

	    	if(ind > maxIndex) 
	    		maxIndex = ind;
	    }

	    return edges[maxIndex];
	}
};