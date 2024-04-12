#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	int countSmaller(vector<vector<int> >& matrix, int target){
		int count = 0;
		int n = matrix.size();
		int i = n-1;
		for(int j=0;j<n && i>=0;j++){
			if(matrix[i][j] > target){
				i--; 
				j--;
			}
			else
				count += i + 1;
		}
		return count;
	}
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
    	int N = matrix.size();
    	int left = matrix[0][0], right = matrix[N-1][N-1];
    	while(left <= right){
    		cout << left << ' ' << right << endl;
    		int mid = (left + right) / 2;
    		int count = countSmaller(matrix, mid); 
    		if(count < k)
    			left = mid + 1;
    		else
    			right = mid - 1;
    	}
    	return left;
    }
};

int main(){
	Solution s;
	vector< vector<int> > matrix(5, vector<int>(5,0));
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			matrix[i][j] = i + j;
	cout << s.kthSmallest(matrix, 14) << endl;
}