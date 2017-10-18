class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prereqPairs) {
        vector<int> prereqNums(numCourses, 0);
        vector< vector<int> > graph(numCourses, vector<int>()); //prereq -> lec graph

        // create incomings list and graph
        for(int i=0;i<prereqPairs.size();i++){
        	int lec = prereqPairs[i].first;
        	int pre = prereqPairs[i].second;
        	graph[pre].push_back(lec);
        	prereqNums[lec]++;
        }

        vector<int> lectureOrder;
        queue<int> q;

        // fill queue with zero prereqs
        for(int i=0;i<numCourses;i++)
        	if(prereqNums[i] == 0)
        		q.push(i);

        // bfs
        while(!q.empty()){
        	int lec = q.front();
        	q.pop();

        	lectureOrder.push_back(lec);
        	int m = graph[lec].size();
        	for(int i=0;i<m;i++){
        		int nextLec = graph[lec][i];
        		prereqNums[nextLec]--;
        		if(prereqNums[nextLec] == 0)
        			q.push(nextLec);
        	}
        }

        // are there any cycle ?
        if(lectureOrder.size() < numCourses)
        	return vector<int>();
        else
        	return lectureOrder;
    }
};