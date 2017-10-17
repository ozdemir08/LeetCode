#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Number{
public:
	int num, row;
	Number(int n, int r){
		num = n;
		row = r;
	}
};

bool cmp(Number a, Number b){
	return a.num > b.num;
}

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
    	int n = matrix.size();
        vector<int> indices(n, 0);
        
        vector<Number> minHeap;
        make_heap(minHeap.begin(), minHeap.end(), cmp);
        for(int row=0;row<n;row++){
        	int col = indices[row]++;
        	int num = matrix[row][col];
        	minHeap.push_back(Number(num, row));
        	push_heap(minHeap.begin(), minHeap.end(), cmp);
	    }

	    Number lastMin(-1, -1);
	    for(int i=0;i<k;i++){
	    	lastMin = minHeap[0];
	    	pop_heap(minHeap.begin(), minHeap.end(), cmp);
	    	minHeap.pop_back();

	    	int row = lastMin.row;
	    	if(indices[row] < n){
	    		int col = indices[row] ++;
	    		int num = matrix[row][col];
	    		minHeap.push_back(Number(num, row));
	        	push_heap(minHeap.begin(), minHeap.end(), cmp);
			}
	    }
	    return lastMin.num;
    }
};

int main(){
	Solution s;
	vector< vector<int> > matrix(5, vector<int>(5,0));
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			matrix[i][j] = i + j;
	cout << s.kthSmallest(matrix, 7) << endl;
}