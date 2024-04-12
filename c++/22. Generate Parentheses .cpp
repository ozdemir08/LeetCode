class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generateParenthesis(n, n, "");
        return results;
    }
private:
    vector<string> results;
    void generateParenthesis(int open, int close, string s) {
        if(!open && !close){
            results.push_back(s);
            return;
        }
        if(open > 0)
            generateParenthesis(open-1, close, s + '(');
        if(close > open)
            generateParenthesis(open, close-1, s + ')');
    }
};