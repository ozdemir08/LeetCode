class Solution {
public:
    string longestPalindrome(string s) {
        for(int mid=0;mid<s.size();mid++){
            int i;
            
            for(i=0;mid-i>=0 && mid+i<s.size() && s[mid-i] == s[mid+i];i++);
            updateCurrentLongest(mid-i+1, mid+i-1);
            
            for(i=0;mid-i>=0 && mid+i+1<s.size() && s[mid-i] == s[mid+i+1];i++);
            updateCurrentLongest(mid-i+1, mid+i);
        }
        return s.substr(long_beg, long_end-long_beg+1);
    }
private:
    int long_beg=0, long_end=0;
    void updateCurrentLongest(int i, int j){
        if(j-i > long_end-long_beg){
            long_end = j;
            long_beg = i;
        }
    }
};