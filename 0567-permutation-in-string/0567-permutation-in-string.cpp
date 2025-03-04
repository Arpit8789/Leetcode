class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // If s1 is longer than s2, no permutation of s1 can be a substring of s2.
        if (s1.length() > s2.length()) 
            return false;

        // Arrays to store character counts for s1 and the current window in s2.
        vector<int> count1(26, 0);  // Frequency array for s1
        vector<int> count2(26, 0);  // Frequency array for sliding window in s2

        // Populate count1 (for s1) and count2 (for the first window in s2)
        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;  // Increment count for each character in s1
            count2[s2[i] - 'a']++;  // Increment count for the first window in s2
        }

        // Sliding window approach
        int windowSize = s1.length();
        for (int i = windowSize; i < s2.length(); i++) {
            // If count1 and count2 match, it means we found a valid permutation
            if (count1 == count2)
                return true;

            // Slide the window:
            count2[s2[i] - 'a']++;           // Add the new character to the window
            count2[s2[i - windowSize] - 'a']--;  // Remove the leftmost character from the window
        }

        // Check for the last window separately
        return (count1 == count2);
    }
};
