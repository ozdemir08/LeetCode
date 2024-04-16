class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder result = new StringBuilder();

        int openParanthesesCount = 0;
        int closeParanthesesCount = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                openParanthesesCount++;
            } else if (c == ')') {
                closeParanthesesCount++;
            }
        }

        int paranthesesBalance = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c <= 'z' && c >= 'a') {
                result.append(c);
                continue;
            }

            if (c == '(') {
                openParanthesesCount--;
                if (closeParanthesesCount - paranthesesBalance > 0) {
                    result.append(c);
                    paranthesesBalance++;
                }
                continue;
            }

            if (c == ')') {
                closeParanthesesCount--;
                if (paranthesesBalance > 0) {
                    result.append(c);
                    paranthesesBalance--;
                }
            }
        }

        return result.toString();
    }
}