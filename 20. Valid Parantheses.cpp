class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> M;
        M[')'] = '(';
        M['}'] = '{';
        M[']'] = '[';
        
        for(int i=0;i<s.size();i++)
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else{
                if(st.empty() || st.top() != M[s[i]])
                    return false;
                st.pop();
            }
        return st.empty();
    }
};