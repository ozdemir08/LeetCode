// Questions: 
// - Just characters or numbers as well? 
// - Don't we need the substring?
// - Size of a string
// - If we find a character with the highest Ascii value, 
// we can have an int array of that size. 

// 1. Clarifying questions
// 2. Assumptions
// 3. Solutions
// 4. Complexity
// 5. Testing
// 6. Readability

class Solution {

    public static int lengthOfLongestSubstring(String s) {
        int[] characterCount = new int[256];

        int longestSubstringWithoutRepeat = 0;
        int currentStart = 0;
        // We can't have a better time complexity than O(n) as we have to iterate it.
        // We can have a O(1) space complexity, characterCount.
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            characterCount[c] = characterCount[c] + 1;
            while (characterCount[c] > 1) {
                char firstCharInCurrentSubstring = s.charAt(currentStart);
                characterCount[firstCharInCurrentSubstring] = characterCount[firstCharInCurrentSubstring] - 1;
                currentStart = currentStart + 1;
            }

            longestSubstringWithoutRepeat = Math.max(longestSubstringWithoutRepeat, i - currentStart + 1);
        }

        return longestSubstringWithoutRepeat;
    }
}