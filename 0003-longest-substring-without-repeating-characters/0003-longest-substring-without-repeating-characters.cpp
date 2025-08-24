class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string curr = "";   // this will store current substring without duplicates
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            // check if current char already exists in curr
            if (curr.find(s[i]) != string::npos) {
                // if duplicate found, remove chars from beginning until duplicate removed
                curr = curr.substr(curr.find(s[i]) + 1);
            }
            // add current char
            curr += s[i];
            // update maxLen
            maxLen = max(maxLen, (int)curr.size());
        }
        return maxLen;
    }
};