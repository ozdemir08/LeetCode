class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int hash[256];
        fill_n(hash, 256, -1);
        
        for(int start=0, i=0;i<s.size();i++){
            if(hash[s[i]] != -1){
                while(start <= hash[s[i]]){
                    hash[s[start++]] = -1;
                }
            }
            hash[s[i]] = i;
            
            if(i-start+1 > max_length)
                max_length = i-start+1;
        }
        return max_length;
    }
};