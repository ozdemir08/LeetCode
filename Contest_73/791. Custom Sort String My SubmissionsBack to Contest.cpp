class Solution {
public:
    string customSortString(string S, string T) {
        int N = S.size(), M = T.size();

        int letterCount[26] = {};
        // count characters in T
        for(int i=0;i<M;i++)
            letterCount[T[i] - 'a']++;

        string res = "";
        // put characters exist in both S, T in proper order
        for(int i=0;i<N;i++){
        	char c = S[i] - 'a';
        	res += string(letterCount[c], S[i]);
        	letterCount[c] = 0;
        }

        // fill the rest
        for(int i=0;i<26;i++){
        	res += string(letterCount[i], i + 'a');
        }

        return res;
    }
};