#include <iostream>
#include <vector>

using namespace std;    

class Solution {
private:
    vector<string> letterCombinations(int pos, string& digits,vector< vector<char> >& letters) {
        if(pos == digits.size())
            return vector<string>(1, "");
        
        vector<string> res;
        
        vector<string> subres = letterCombinations(pos+1, digits, letters);
        int ind = digits[pos] - '0';

        for(int i=0;i<letters[ind].size();i++){
            for(int j=0;j<subres.size();j++){
                string s = letters[ind][i] + subres[j];
                res.push_back(s);
            }
        }
        return res;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();
        vector< vector<char> > letters(10);
        for(char c='a';c<='o';c++){
            int num = (c - 'a') / 3 + 2;
            letters[num].push_back(c);
        }
        for(char c='p';c<='s';c++)
            letters[7].push_back(c);
        for(char c='t';c<='v';c++)
            letters[8].push_back(c);
        for(char c='w';c<='z';c++)
            letters[9].push_back(c);
        return letterCombinations(0, digits, letters);
    }
};

int main(){
    Solution s;
    vector<string> res = s.letterCombinations("23");
    for(int i=0;i<res.size();i++)
        cout << res[i] << endl;

}