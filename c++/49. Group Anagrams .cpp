class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<int> > anagrams;
        int n = strs.size();
        for(int i=0;i<n;i++){
        	string s = strs[i];
        	sort(s.begin(), s.end());
        	anagrams[s].push_back(i);
	    }
	    vector< vector<string> > res;
	    for(unordered_map< string, vector<int> >::iterator it = anagrams.begin(); it != anagrams.end(); it++){
	    	vector<int> v = it -> second;
	    	vector<string> subres;
	    	for(int j=0;j<v.size();j++)
	    		subres.push_back(strs[v[j]]);
	    	res.push_back(subres);
    	}
    	return res;
	}
};