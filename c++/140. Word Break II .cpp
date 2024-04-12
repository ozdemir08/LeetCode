#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
private:
	set<string> dict;
	map< string, vector<string> > strToSentences;

    vector<string> wordBreak(string s) {

    	if(s.empty())
    		return vector<string>(1, "");

    	if(strToSentences.find(s) != strToSentences.end())
    		return strToSentences[s];

    	string word = "";
    	int n = s.size();
    	vector<string> sentences;

    	for(int i=0;i<n;i++){
    		word += s[i];
    		if(dict.find(word) != dict.end()){
    			vector<string> subSentences = wordBreak(s.substr(i+1));
    			int m = subSentences.size();
    			for(int j=0;j<m;j++){
    				if(subSentences[j].empty())
    					sentences.push_back(word);
    				else{
	    				string newSentence = word + " " + subSentences[j];
	    				sentences.push_back(newSentence);
	    			}
    			}
    		}
    	}

    	strToSentences[s] = sentences;
    	return sentences;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int wordDictSize = wordDict.size();
        for(int i=0;i<wordDictSize;i++)
        	dict.insert(wordDict[i]);
        return wordBreak(s);
    }
};

int main(){
	Solution sol;
	string s = "catsanddog";
	vector<string> wordDict;
	wordDict.push_back("cat");
	wordDict.push_back("cats");
	wordDict.push_back("and");
	wordDict.push_back("sand");
	wordDict.push_back("dog");
	vector<string> v = sol.wordBreak(s, wordDict);
	cout << v.size() << endl;
	for(int i=0;i<v.size();i++)
		cout << v[i] << endl;
}