#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
	void edgesToGraph(vector< pair<int, int> >& edges, vector< vector<int> >& graph){
		int m = edges.size();
		for(int i=0;i<m;i++){
			int node1 = edges[i].first;
			int node2 = edges[i].second;		
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}
	}
public:
    vector<int> findMinHeightTrees(int n, vector< pair<int, int> >& edges) {
		vector< vector<int> > graph(n, vector<int>());
		vector<int> neighborNums(n, 0);
		vector<int> heights(n, 0);

		// edges -> graph
		edgesToGraph(edges, graph);

		// number of neighbours for each node
		for(int i=0;i<n;i++)
			neighborNums[i] = graph[i].size();

		queue<int> q;

		// add leaves to queue
		for(int i=0;i<n;i++)
			if(neighborNums[i] == 1){
				q.push(i);
				heights[i] = 1;
			}

		int maxHeight = 0;
		// take nodes, decrease neighbour nodes' neighbornums, add new leaves to queue
		while(!q.empty()){
			//take from queue
			int node = q.front();
			q.pop();

			// update maxHeight
			maxHeight = max(maxHeight, heights[node]);

			int m = graph[node].size();
			for(int i=0;i<m;i++){
				int next = graph[node][i];
				// if visited, skip
				if(heights[next] > 0)
					continue;

				neighborNums[next]--;
				if(neighborNums[next] == 1){
					q.push(next);
					heights[next] = heights[node] + 1;

				}
			}
		}

		// return nodes with maxHeight as result
		vector<int> res;
		for(int i=0;i<n;i++)
			if(heights[i] == maxHeight)
				res.push_back(i);

		return res;
    }
};

int main(){
	vector< pair<int, int> > edges;
	edges.push_back(make_pair(0, 1));
	Solution s;
	vector<int> v = s.findMinHeightTrees(2, edges);
	for(int i=0;i<v.size();i++)
		cout << v[i] << endl;
}