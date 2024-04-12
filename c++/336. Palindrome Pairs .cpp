class Solution {
private:
	bool isPalindrome(string s){
		int n = s.size();
		for(int i=0;i<n/2;i++)
			if(s[i] != s[n-i-1])
				return false;
		return true;
	}

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> rWordToIndex;
		int N = words.size();

		// reverse of words to map
		for(int i=0;i<N;i++){
			string word = words[i];
			reverse(word.begin(), word.end());
			rWordToIndex[word] = i;
		}

		vector< vector<int> > res;
		// Look for each word
		for(int i=0;i<N;i++){
			string word = words[i];
			int K = word.size();
            
            //edge case, word = ""
            if(word.empty()){
                for(int j=0;j<N;j++)
                    if(i!=j && isPalindrome(words[j]))
                        res.push_back({j, i});
                continue;
            }

			for(int j=0;j<K;j++){
                // word => left | right
				string left = word.substr(0, j+1);
                string right = word.substr(j+1);

                // Look for left | right | left 
                //            r  |     word
				if(isPalindrome(right) && rWordToIndex.find(left) != rWordToIndex.end()){
					int r = rWordToIndex[left];
					if(i != r) 
					    res.push_back({i, r});
				}
                
                // Look for right | left | right
                //            l   |    word
                if(isPalindrome(left) && rWordToIndex.find(right) != rWordToIndex.end()){
                    int l = rWordToIndex[right];
					if(i != l) 
					    res.push_back({l, i});
                }
			}
		}
		return res;
    }
};