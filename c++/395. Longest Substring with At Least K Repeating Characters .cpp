class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        vector<int> counts(26, 0);
        
        // places of each char
        for(int i=0;i<n;i++){
            char c = s[i];
            counts[c-'a']++;
        }
        
        // indices of all chars less than k
        vector<int> indices;
        indices.push_back(-1);
        
        for(int i=0;i<n;i++){
            char c = s[i];
            // if this char is less than k, 
            //  then this index is not in the solution
            if(counts[c-'a'] < k)
                indices.push_back(i);
        }
        indices.push_back(n);
        
        // no chars less than k
        if(indices.size() == 2)
            return n;
        
        // try all substrings
        int res = 0;
        for(int i=0;i<indices.size()-1;i++){
            int beg = indices[i] + 1;
            int end = indices[i + 1];
            if(end > beg)
                res = max(res, longestSubstring(s.substr(beg, end - beg), k));
        }
        return res;
    }
};