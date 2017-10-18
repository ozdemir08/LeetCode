#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    	// str -> word, bool -> visited
        unordered_map<string, bool> dict;
        int n = wordList.size();
        for(int i=0;i<n;i++)
        	dict[wordList[i]] = false;

        queue< pair<string, int> > q;
        q.push(make_pair(beginWord, 1));

        while(!q.empty()){
        	string word = q.front().first;
        	int length = q.front().second;
        	q.pop();

        	if(word == endWord)
        		return length;

        	int m = word.size();
        	for(int j=0;j<m;j++){
        		char c = word[j];
        		for(int i=0;i<26;i++){
        			// transform
        			word[j] = 'a' + i;
        			// new word in dict but not visited before
        			if(dict.find(word) != dict.end() && !dict[word]){
        				dict[word] = true;
        				pair<string, int> transformed = make_pair(word, length+1);
        				q.push(transformed);
        			}
        		}
        		word[j] = c;
        	}
        }

        return 0;
    }
};

int main(){
	Solution s;
	std::vector<string> v;
	v.push_back("hot");
	v.push_back("dot");
	v.push_back("dog");
	v.push_back("lot");
	v.push_back("log");
	v.push_back("cog");
	cout << s.ladderLength("hit", "cog", v) << endl;

}