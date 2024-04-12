class Solution {
private:
    bool wordBreak(int place, string& str, set<string>& dict, vector<bool>& visited, vector<bool>& dp){
        if(place == str.size())
        	return true;
        if(visited[place])
        	return dp[place];
        bool res = false;

        string currentWord = "";

        for(int i=place;i<str.size();i++){
        	currentWord += str[i];
        	// this is a word exists in dict
        	if(dict.find(currentWord) != dict.end())
        		res |= wordBreak(i + 1, str, dict, visited, dp);
		}
        visited[place] = true;
        dp[place] = res;
        return res;
    }
    
public:
    bool wordBreak(string str, vector<string>& wordDict) {
        
        set<string> dict(wordDict.begin(), wordDict.end());
        int N = str.size();
        vector<bool> visited(N, false), dp(N, false);
        
        return wordBreak(0, str, dict, visited, dp);
    }
};