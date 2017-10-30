// Solution with N^2
class Solution {
public:
    int minCut(string s) {
    	int N = s.size();
    	vector< vector<int> > pals(N, vector<int>()); 
    	vector< int > DP(N, 0);

    	// find pals i -> j
    	for(int i=0;i<N;i++){
            
            // odd palindroms whose middle points are i
    		int l = i, r = i;
    		while(l>=0 && r<N && s[l] == s[r]){
    			pals[l].push_back(r);
    			l--;
    			r++;
    		}
            
            // even palindroms whose middle points are i, i+1
    		l = i, r = i+1;
    		while(l>=0 && r<N && s[l] == s[r]){
    			pals[l].push_back(r);
    			l--;
    			r++;
    		}
    	}

    	// DP[i] = i; each character is a palindrome.
    	// So this is an upper_bound
    	for(int i=0;i<N;i++)
    		DP[i] = i;

        // for [0, j], we have a solution
    	for(int j=0;j<N;j++){
    		int M = pals[j].size();
            // For palindromes start from j, we may cut from j
            // and the result is (# of cuts [0, j-1]) + 1
    		for(int i=0;i<M;i++){
    			int end = pals[j][i];
                int valueWithCut = (!j ? -1 : DP[j-1]) + 1;
    			DP[end] = min(DP[end], valueWithCut);
    		}
    	}
    	return DP[N-1];
    }
};

// Solution with N^3
class Solution {
private:
	bool isPalindrome(string& s, int i, int j){
		while(i<j){
			if(s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	int minCut(string& s, int i, int j, vector< vector<int> >& DP, vector< vector<bool> >& visited){

		// if visited return its value
		// if is palindrome, then 0 is the value of DP[i][j]
		if(visited[i][j] || isPalindrome(s, i, j))
			return DP[i][j];

		visited[i][j] = true;
		int res = INT_MAX;

		// divide from each index
		for(int k=i;k<j;k++){
			int left = minCut(s, i, k, DP, visited);
			int right = minCut(s, k+1, j, DP, visited);
			res = min(res, left + right);
		}
		DP[i][j] = res;
		return res;
	}
public:
    int minCut(string s) {
    	int N = s.size();
    	vector< vector<int> > DP(N, vector<int>(N, 0));
    	vector< vector<bool> > visited(N, vector<bool>(N, false));		        
    	return minCut(s, 0, N-1, DP, visited);
    }
};