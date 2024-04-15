class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int wordIndex = 0;
        int currentNumber = 0;

        for (int i = 0; i < abbr.length(); i++) {
            char c = abbr.charAt(i);
            if (c <= 'z' && c >= 'a') {
                if (currentNumber > 0) {
                    if (wordIndex + currentNumber >= word.length()) {
                        return false;
                    }

                    wordIndex = wordIndex + currentNumber;
                    currentNumber = 0;
                }

                if (wordIndex < word.length() && word.charAt(wordIndex) != c) {
                    return false;
                }

                wordIndex++;
            } else {
                int digit = c - '0';
                if (currentNumber == 0 && digit == 0) {
                    return false;
                }

                currentNumber = 10 * currentNumber + digit;
            }
        }

        wordIndex = wordIndex + currentNumber;
        return wordIndex == word.length();
    }
}